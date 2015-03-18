/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Updated: 2015/03/18 14:55:02 by fdaudre-         ###   ########.fr       */
/*   Created: 2015/03/18 14:51:54 by alelievr          #+#    #+#             */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_42SH_H
# define FT_42SH_H

# include "libft.h"
# include <term.h>
# include <unistd.h>
# include <stdlib.h>

#define MAX_ENV			0xF00

extern	char			**g_env;

enum					e_operate
{
	PIPE,
	REDIR_IN_OUT,
	REDIR_R,
	EREDIR_R,
	REDIR_L,
	DREDIR_L,
	DREDIR_R,
	EDREDIR_R,
	SEMICOLON,
	BACKCOTE,
	AND,
	XOR,
	BIN
};

typedef struct			s_operate
{
	int		type;
	int		len;
	char	**value;
}					t_operate;

typedef struct			s_builtins
{
	char	*name;
	int		(*fun)(int, char **);
}						t_builtins;

typedef long long
		unsigned int	t_lluint;

/*
 **	Utilities:
*/

char					*get_env(char *name);
int						set_env(char *name, char *value);
int						unset_env(char *name);

int						build_env(void);
int						ft_exebin(char *path, char **av, char **env);
void					ft_signals(void);
int						execute_command(t_operate *b);
int						is_dir(char *path);

/*
**	Builtins:
*/

int						ft_builtins(char **com);

int						ft_env(int ac, char **av);
int						ft_exit(int ac, char **av);
int						ft_unsetenv(int ac, char **av);
int						ft_setenv(int ac, char **av);
int						ft_echo(int ac, char **av);
int						ft_cd(int ac, char **av);

/*
 **	Terminal:
*/

void					default_terminal_mode(void);
void					raw_terminal_mode(void);

/*
** Prompt:
*/

#define PR_BUF_SIZE		0xF0000

typedef struct			s_prompt
{
	char				buff[PR_BUF_SIZE];
	size_t				index;
	t_lluint			key;
	t_list				*history;
}						t_prompt;

typedef struct			s_pr_code
{
	t_lluint			code;
	void				(*f)(t_prompt *d);
}						t_pr_code;

void					ft_prompt(void);
t_operate				*ft_parse(char *cmd);
char					*get_command(void);

/*
** Operation:
*/



#endif
