#ifndef FT_42SH_H
# define FT_42SH_H

# include "libft.h"
# include <term.h>
# include <termios.h>
# include <ncurses.h>
# include <sys/ioctl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# define O_RDONLY					0
# define O_WRONLY					1
# define O_RDWR						2

# define MAX_ENV					0xF00
# define MAX_VAR					0xF00
# define BELL						write(1, "\a", 1)
# define PROMPT42					"$> "
# define PATH_NOT_FOUND				-2

# define MAX_REDIRECTION_COMMAND	32
# define MAX_PIPE_COMMAND			16
# define MAX_VARNAME_LENGTH			512
# define MAX_ALIAS_NAME_LENGTH		(0xF00 - 1)
# define MAX_WILDCARD_MATCHES		0xF00
# define MAX_BINARY_ARGUMENTS		0xF000
# define PIPE_BUFF_SIZE				127

extern	char			**g_env;
extern	char			**g_var;

enum					e_operate
{
	OP_BIN,
	OP_PIPE,
//	OP_REDIR_IN_OUT,
	OP_REDIR_R,
	OP_REDIR_L,
//	OP_EREDIR_R,
//	OP_EDREDIR_R,
	OP_DREDIR_L,
	OP_DREDIR_R,
	OP_SEMICOLON,
//	OP_BACKCOTE,
	OP_AND,
	OP_OR,
	OP_NO_OP
};

# define CLOSE_FD					(-2)
# define STDOUT_AND_STDERR			(12)
# define PROCESS_FD					(-3)
typedef struct			s_redirection
{
	enum e_operate		type;	//specify the type of the redirection
	char				*file;	//std file, if null the fd is taken
	int					fd_from;
	int					fd_to;	//used when std* redirections like >&2 or 2>&- are
								//	usedredirections for example
}						t_redirection;

typedef struct			s_operator
{
	char				*bin;		//binary entered in the command line
	char				**av_bin;	//binay arguments
	int					ac_bin;		//binay arguments number
	int					ftn__:32;
	t_redirection		redirs[MAX_REDIRECTION_COMMAND];	//all redirections of the command
}						t_operator;

typedef struct			s_command
{
	t_operator			*list; //each node is a command like (ls -l fkewlf > file),
							   //	if there is a next element, the command output
							   //	is piped in the next node
	int					background; //can be 1 or 0 if the command is in background
	int					ftn__:32;
	struct s_command	*next;
}						t_command;

typedef struct			s_commandline
{
	t_command				*command;
	enum e_operate			type; //can be ||, && or ;
	int						ftn__:32;
	struct s_commandline	*next;
}						t_commandline;

typedef struct			s_builtins
{
	char	*name;
	int		(*fun)(int, char **);
	bool	forkable;
}						t_builtins;

typedef struct			s_file
{
	unsigned char		type;
	char				*name;
}						t_file;

typedef struct			s_alias
{
	char			*alias;
	char			*value;
	struct s_alias	*next;
}						t_alias;

typedef struct			s_matched_list
{
	char					*str;
	struct s_matched_list	*next;
}						t_mlist;

typedef long long
		unsigned int	t_lluint;

/*
 **	Utilities:
*/


int						build_env(void);
int						ft_exebin(char *path, char **av, char **env, bool fork);
void					siguser_handler(int s);
void					ft_signals(void);
int						dlog(char *fmt, ...);

int						is_dir(const char *name);
int						is_file(const char *name, int flag);

char					*get_dirpath(char *path, char *buff);
char					*get_filename(char *path, char *buff);
size_t					get_dirpath_length(char *path);
size_t					get_filename_length(char *path);
char					*unscape_space(char *path);
t_alias					*get_alias_list(t_alias *a);
char					*get_alias_value(char *name);

/*
 **	Builtins:
*/

int						ft_builtins(char **av, int *ret);
int						is_builtin(char *s);
int						is_builtin_forkable(char *s);

int						ft_env(int ac, char **av);
int						ft_exit(int ac, char **av);
int						ft_unsetenv(int ac, char **av);
int						ft_unset(int ac, char **av);
int						ft_setenv(int ac, char **av);
int						ft_set(int ac, char **av);
int						ft_getenv(int ac, char **av);
int						ft_get(int ac, char **av);
int						ft_echo(int ac, char **av);
int						ft_cd(int ac, char **av);
int						ft_bonus(int ac, char **av);
int						ft_fg(int ac, char **av);
int						ft_bg(int ac, char **av);
int						ft_jobs(int ac, char **av);
int						ft_history(int ac, char **av);
int						ft_alias(int ac, char **av);
int						ft_where(int ac, char **av);

/*
 **	HashTable:
 */

typedef struct			s_hashtable
{
	unsigned long		hash;
	char				*path;
	struct s_hashtable	*next;
}						t_hashtable;

unsigned long			hashstring(char *str);
t_hashtable				*new_hashtable_entry(unsigned long hash, const char *path);
int						add_hashtable_entry(t_hashtable **ht, t_hashtable *e);

char					*get_binhash_path(unsigned long hash);
t_hashtable				*get_binhash(t_hashtable *h);
void					load_binhash(void);
void					delete_binhash(void);
void					reload_binhash(void);

/*
 **	Preparser:
*/
# define NOT_ESCAPED(b, s, c)	(*(s) == c && (s == b || *((s) - 1) != '\\'))
# define ESCAPED(b, s, c)		(*(s) == c && s != b && *((s) - 1) == '\\')
char					**preparse_command(char *cmd);
char					**cmd_split_quote(char *cmd);
char					**cmd_split_quote_table(char **ptrs, size_t len);
char					*cmd_replace_alias(char *s);
char					*cmd_replace_vars(char *s);
char					*cmd_globing_expand(char *s);
void					cmd_globing_expand_braces(char *s, char *buff);
void					cmd_globing_expand_wildcard(char *s, char *buff);
int						cmd_globing_match(char *s1, char *s2);
t_mlist					*cmd_match_patern_files(char *s);
int						cmd_is_to_glob(char *s);

/*
 **	Terminal:
*/

void					default_terminal_mode(void);
void					raw_terminal_mode(void);

/*
 ** Prompt:
*/

# define PR_BUF_SIZE		0xF0000
# define PR_RBUF_SIZE		0xF000

typedef struct			s_prompt
{
	char				buff[PR_BUF_SIZE];
	char				rbuff[PR_RBUF_SIZE];
	size_t				index;
	t_lluint			key;
	t_list				*history;
	size_t				history_index;
	size_t				col;
	int					r_mode;
	int					good_prompt;
}						t_prompt;

typedef struct			s_pr_code
{
	t_lluint			code;
	void				(*f)(t_prompt *d);
}						t_pr_code;

void					ft_prompt(void);
char					*get_command(t_prompt *d);
void					load_history(t_prompt *d);
void					write_history(t_prompt *d);

# define PR_UP			4283163ull
# define PR_DO			4348699ull
# define PR_RI			4414235ull
# define PR_LE			4479771ull
# define PR_UP			4283163ull
# define PR_DW			4348699ull
# define PR_S_UP		71683997260571ull
# define PR_S_DO		72783508888347ull
# define PR_S_RI		73883020516123ull
# define PR_S_LE		74982532143899ull
# define PR_BEG			4741915ull
# define PR_END			4610843ull
# define PR_BACK		127ull
# define PR_DEL			2117294875ull
# define PR_C_A			1ull
# define PR_C_E			5ull
# define PR_C_K			11ull
# define PR_C_U			21ull
# define PR_C_L			12ull
# define PR_C_P			16ull
# define PR_TAB			9ull

# define PR_DEFAULT		0
# define PR_NEW_LINE	1

void					pr_addchar(t_prompt *d,
		char c) __attribute__((overloadable));
void					pr_addchar(t_prompt *d) __attribute__((overloadable));
void					pr_addstr(t_prompt *d, char *s, size_t len);
void					pr_move(t_prompt *d);
void					pr_del(t_prompt *d);
void					pr_tab(t_prompt *d);
void					pr_history(t_prompt *d);
void					pr_vim_export(t_prompt *p);
void					pr_clear(t_prompt *p);
void					pr_affbuff(t_prompt *p);

/*
 ** Prompt history:
*/
t_list					*get_history_index(size_t index);
t_list					*get_history_search(char *s);
t_list					*get_history_list(t_list *h);

/*
 **	Prompt utils:
*/
void					pr_ctrlc_handler(int s);
void					pr_display(t_prompt *d);
void					pr_display_line(char *buff, int prompt);
void					pr_initline(t_prompt *d, int flag);
void					get_command_init(t_prompt *d);
int						check_unterminated_sequences(t_prompt *d);
t_prompt				*get_current_prompt(t_prompt *p);
char					*pr_unscape_buff(char *buff);
size_t					pr_get_cursor_row(t_prompt *d);
size_t					pr_get_current_prompt_length(t_prompt *d);
void					pr_up_cursor(t_prompt *d);

/*
 ** Operation:
*/

void					ft_exec(int ac, char **av);
void					ft_pipe(int ac, char **av);
void					ft_redir_stdin_stdout(int ac, char **av);
void					ft_right_redir(int ac, char**av);
void					ft_double_right_redir(int ac, char **av);
void					ft_error_double_right_redir(int ac, char **av);
void					ft_error_right_redir(int ac, char **av);
void					ft_left_redir(int ac, char **av);
void					ft_double_left_redir(int ac, char **av);

/*
 ** Variables:
*/

char					*get_env(char *name);
int						set_env(char *name, char *value);
int						unset_env(char *name);
int						set_var(char *name, char *value);
int						unset_var(char *name);
char					*get_var(char *name);

/*
 **	Lexer:
*/
# define LEXER_ERROR(x, args...) {ft_printf("42sh: "); ft_printf(x, ##args); return (0);}
# define EXECUTER_ERROR(x, args...) {ft_printf("42sh: "); ft_printf(x, ##args); return (COMMAND_FAILED);}

typedef struct			s_lexer
{
	char		*op;
	int			(*f)(char ***, t_commandline **);
}						t_lexer;

t_commandline			*ft_lex(char **cmd);
int						is_operator(char *s);
int						match_operator(char *s);
int						lex_redir_file_template(enum e_operate t,
		t_redirection *r, int fd_in , char **v_op);
int						lex_check_next_value(t_commandline **cmd, char **word);

int						add_word_to_current_command(char **word, t_commandline **cmd);
int						add_redir_to_current_command(t_redirection r, t_commandline **cmd);

t_operator				*get_current_operator(t_commandline *cl);
t_command				*get_current_command(t_commandline *cl);
t_commandline			*get_current_commandline(t_commandline *cl);

t_commandline			*lex_new_commandline(void);
t_command				*lex_new_command(void);
t_operator				*lex_new_operator(void);


int						lex_pipe(char ***word, t_commandline **cmd);
int						lex_lredir(char ***word, t_commandline **cmd);
int						lex_dlredir(char ***word, t_commandline **cmd);
int						lex_or(char ***word, t_commandline **cmd);
int						lex_and(char ***word, t_commandline **cmd);
int						lex_semicolon(char ***word, t_commandline **cmd);
int						lex_background(char ***word, t_commandline **cmd);
int						lex_fd_rredir(char ***word, t_commandline **cmd);
int						lex_all_rredir(char ***word, t_commandline **cmd);
int						lex_fd_drredir(char ***word, t_commandline **cmd);
int						lex_all_drredir(char ***word, t_commandline **cmd);

void					print_cmd_line(t_commandline *c);

/*
 **	Pid utils:
*/

enum					e_status
{
	S_RUNNING,
	S_STOPPED,
	S_TERMINATED,
	S_UNDEFINED,
};

typedef struct			s_process
{
	pid_t				pid;
	char				*name;
	enum e_status		status;
	struct s_process	*next;
}						t_process;

struct s_pipe_process;

struct s_pipe_process	*exe_init_pid_list(struct s_pipe_process *p);
t_process				*get_fg_pid(pid_t p, char *pname, int status);
int						delete_last_bg_pid(void);
void					add_bg_pid(pid_t p, char *pname, int status);
t_process				*get_last_bg_pid(void);
void					killall_bg_process(void);
int						wait_process(pid_t pid, char *pname);

/*
 **	Executer:
*/
# define BINARY_OK				0
# define BINARY_NOT_IN_PATH		1
# define BINARY_NOT_EXECUTABLE	2
# define BINARY_NOT_FILE		3

# define COMMAND_FAILED			1
# define COMMAND_OK				0

# define P_CHILD				0
# define P_FATHER				1
# define PIPE_READ				0
# define PIPE_WRITE				1

# define P_LIST_END				(-2)

typedef struct			s_filedes
{
	int			fd;
	int			flag;
}						t_filedes;

typedef struct			s_pipe
{
	int			fd[2];
	int			fd_buff[2];
	int			open;
	char		buff[PIPE_BUFF_SIZE];
}						t_pipe;

typedef struct			s_pipe_process
{
	t_pipe					pipe;
	t_process				process;
	size_t					npipes;
	size_t					id;
}						t_pprocess;

int						executer(t_commandline *cl);
int						execute_command(t_command *c);
int						execute_commandline(t_commandline *cl);
int						execute_operator(t_operator *o, t_command *c, int process);
int						execute_binary(char *path, char **av, char **env);
int						exe_stdout_to_pipe(t_pipe *p);
int						exe_stdin_from_pipe(t_pipe *p);

void					exe_add_running_pid(pid_t pid);
void					exe_remove_running_pids(void);
int						exe_wait_command_pid(int *res);
void					exe_send_sig_pids(int sig);

int						exe_get_pipe_number(t_command *c);
t_pprocess				*exe_create_command_pipes(t_command *c);
void					exe_destroy_command_pipes(t_pprocess *plist);
void					exe_io_buff_pipe_read_write(t_command *c, t_pprocess *ps);

#endif
