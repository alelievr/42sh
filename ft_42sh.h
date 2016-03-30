#ifndef FT_42SH_H
# define FT_42SH_H

# include "libft.h"
# include <term.h>
# include <termios.h>
# include <ncurses.h>
# include <sys/ioctl.h>
# include <unistd.h>
# include <stdlib.h>

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

enum					e_status
{
	S_RUNNING,
	S_STOPPED,
	S_TERMINATED
};

typedef struct			s_redirection
{
	enum e_operate		type;	//specify the type of the redirection
	char				*file;	//std file, if null the fd is taken
	int					fd;		//used when std* redirections like >&2 or 2>&- are
								//	usedredirections for example
	int					ftn__:32;
}						t_redirection;

typedef struct			s_operator
{
	char				*bin;		//binary entered in the command line
	char				**av_bin;	//binay arguments
	int					ac_bin;		//binay arguments number
	int					ftn__:32;
	t_redirection		redirs[MAX_REDIRECTION_COMMAND];	//all redirections of the command
}						t_operator;

typedef struct			s_pipe
{
	int			fd[2];
	int			open;
}						t_pipe;

typedef struct			s_command
{
	t_operator			*list; //each node is a command like (ls -l fkewlf > file),
							   //	if there is a next element, the command output
							   //	is piped in the next node
	t_pipe				pipe;
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

typedef struct			s_operate
{
	enum e_operate		type;
	int					ftn__:32;
//	int					len;
	char				**value;
	struct s_operate	*next;
}					t_operate;

typedef struct			s_builtins
{
	char	*name;
	int		(*fun)(int, char **);
}						t_builtins;

typedef struct			s_file
{
	unsigned char		type;
	char				*name;
}						t_file;

typedef struct			s_process
{
	pid_t				pid;
	char				*name;
	enum e_status		status;
	struct s_process	*next;
}						t_process;

typedef struct			s_hashtable
{
	unsigned long		hash;
	char				*path;
	struct s_hashtable	*next;
}						t_hashtable;

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
int						ft_exebin(char *path, char **av, char **env);
void					siguser_handler(int s);
void					ft_signals(void);
int						execute_command(t_operate *b);
int						execute_command(t_operate *begin);

int						is_dir(const char *name);

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

int						ft_builtins(char **av);
int						is_builtin(char *s);

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
 **	Pid utils:
*/
t_process				*get_fg_pid(pid_t p, char *pname, int status);
int						delete_last_bg_pid(void);
void					add_bg_pid(pid_t p, char *pname, int status);
t_process				*get_last_bg_pid(void);
void					killall_bg_process(void);
int						wait_process(pid_t pid, char *pname);

/*
 **	HashTable:
 */
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
# define NOT_ESCAPED(b, s, c) (*(s) == c && (s == b || *((s) - 1) != '\\'))
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

typedef struct			s_lexer
{
	char		*op;
	int			expected;
}						t_lexer;

t_commandline			*ft_lex(char **cmd);
int						ft_lex_word(char **word, t_commandline **cmd);

void					print_cmd_line(t_commandline *c);

#endif
