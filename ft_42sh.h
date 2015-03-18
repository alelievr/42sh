/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 16:28:25 by alelievr          #+#    #+#             */
/*   Updated: 2015/03/18 14:49:06 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_42SH_H
# define FT_42SH_H

#include "libft/libft.h"
#include <term.h>
#include <unistd.h>
#include <stdlib.h>

#define MAX_ENV	0xF00

extern	char	**g_env;

enum	e_operate
{
	PIPE,
	REDIR_R,
	EREDIR_R,
	REDIR_L,
	DREDIR_L,
	DREDIR_R,
	EDREDIR_R,
	SEMICOLON,
	ENV,
	BACKCOTE,
	AND,
	XOR
};

typedef struct		s_operate
{
	int		type;
	char	*value;
}					t_operate;

typedef struct		s_builtins
{
	char	*name;
	int		(*fun)(int, char **);
}					t_builtins;

char				*get_env(char *name);
int					set_env(char *name, char *value);
int					build_env(void);
int					set_env(char *name, char *value);
char				*get_env(char *name);
int					get_command(void);
int					is_dir(char *path);
int					ft_exebin(char *path, char **av, char **env);
int					unset_env(char *name);
void				ft_signals(void);

/*
**	Builtins:
*/

int					ft_builtins(char **com);

int					ft_env(int ac, char **av);
int					ft_exit(int ac, char **av);
int					ft_unsetenv(int ac, char **av);
int					ft_setenv(int ac, char **av);
int					ft_echo(int ac, char **av);
int					ft_cd(int ac, char **av);

#endif
