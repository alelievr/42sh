/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_vars.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 16:51:46 by alelievr          #+#    #+#             */
/*   Updated: 2016/05/23 20:57:51 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

static inline int		cmd_copy_varname(char **s, char *buff)
{
	int		ac;

	(*s)++;
	ac = (**s == '{');
	if (ac)
	{
		++(*s);
		while (**s && **s != '}')
			*buff++ = *(*s)++;
		++(*s);
	}
	else
		while (**s && !ft_isspace(**s))
			*buff++ = *(*s)++;
	*buff = 0;
	return (1);
}

static inline size_t	cmd_copy_var_value(char *varname, char *buff)
{
	char	*var;
	
	if ((var = get_env(varname)))
	{
		printf("var = %s\n", var);
		ft_strcpy(buff, var);
	}
	else if ((var = get_var(varname)))
		ft_strcpy(buff, var);
	if (var)
		return (ft_strlen(var));
	else
		return (0);
}

char					*cmd_replace_vars(char *s)
{
	static char	buff[0xF0000];
	char		varname[0xF000];
	int			inhibed;
	char		*begin;
	size_t		i;

	i = 0;
	begin = s;
	inhibed = (*s == '\'');
	while (*s)
	{
		if ((*s == '\'' && ((s == begin)
						|| (s != begin && *(s - 1) != '\\'))))
			inhibed = !inhibed;
		if (!inhibed && *s == '$' && cmd_copy_varname(&s, varname))
			i += cmd_copy_var_value(varname, buff + i);
		else if (!inhibed && *s == '~' && s++)
			i += cmd_copy_var_value("HOME", buff + i);
		else
			buff[i++] = *s++;
	}
	buff[i] = 0;
//	free(begin);
	return (ft_strdup(buff));
}
