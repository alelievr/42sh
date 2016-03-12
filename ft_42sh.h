#ifndef FT_42SH_H
# define FT_42SH_H

# include "libft.h"
# include <term.h>
# include <termios.h>
# include <ncurses.h>
# include <sys/ioctl.h>
# include <unistd.h>
# include <stdlib.h>

#define MAX_ENV					0xF00
#define MAX_VAR					0xF00
#define MAX_REDIRECTION_COMMAND	32

extern	char			**g_env;
extern	char			**g_var;

enum					e_operate
{
	PIPE,
	REDIR_IN_OUT,
	REDIR_R,
	BIN,
	EREDIR_R,
	REDIR_L,
	DREDIR_L,
	DREDIR_R,
	EDREDIR_R,
	SEMICOLON,
	BACKCOTE,
	AND,
	OR,
};

typedef struct			s_redirection
{
	enum e_operate		type;	//specify the type of the redirection
	char				*file;	//output file, if null the fd is taken
	int					fd;		//used when std* redirections like >&2 or 2>&- are
								//	usedredirections for example
	int					ftn__:32;
}						t_redirection;

typedef struct			s_operator
{
	char				*bin;		//binary liked entered in the command line
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
	t_command			*command;
	enum e_operate		type; //can be ||, && or ;
	int					ftn__:32;
	struct s_command	*next;
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

typedef long long
		unsigned int	t_lluint;

/*
 **	Utilities:
*/


int						build_env(void);
int						ft_exebin(char *path, char **av, char **env);
void					ft_signals(void);
int						execute_command(t_operate *b);
int						execute_command(t_operate *begin);
int						is_dir(const char *name);

/*
 **	Builtins:
*/

int						ft_builtins(char **av);

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

/*
 **	Terminal:
*/

void					default_terminal_mode(void);
void					raw_terminal_mode(void);

/*
 ** Prompt:
*/

# define PR_BUF_SIZE		0xF0000

typedef struct			s_prompt
{
	char				buff[PR_BUF_SIZE];
	size_t				len;
	size_t				index;
	t_lluint			key;
	t_list				*history;
	size_t				col;
}						t_prompt;

typedef struct			s_pr_code
{
	t_lluint			code;
	void				(*f)(t_prompt *d);
}						t_pr_code;

void					ft_prompt(void);
t_operate				*ft_parse(char *cmd);
char					*get_command(void);

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
# define PR_TAB			9ull

void					pr_addchar(t_prompt *d);
void					pr_addstr(t_prompt *d, char *s, size_t len);
void					pr_move(t_prompt *d);
void					pr_del(t_prompt *d);
void					pr_tab(t_prompt *d);
void					pr_history(t_prompt *d);

/*
 ** Prompt history:
*/
char					*get_history_index(size_t index);
char					*get_history_search(char *s);
t_list					*get_history_list(t_list *h);

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

#endif
