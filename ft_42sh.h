/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 16:28:25 by alelievr          #+#    #+#             */
/*   Updated: 2015/03/16 16:39:37 by alelievr         ###   ########.fr       */
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

char				*get_env(char *name);
int					set_env(char *name, char *value);
int					build_env(void);
int					set_env(char *name, char *value);
char				*get_env(char *name);
int					get_command(void);
int					is_dir(char *path);

/*
**	Builtins:
*/

int					ft_env(int ac, char **av);

#endif
