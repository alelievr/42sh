/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alias.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 17:26:30 by alelievr          #+#    #+#             */
/*   Updated: 2016/03/17 20:30:23 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

t_alias			*get_alias_list(t_alias *a)
{
	static t_alias	*al = NULL;

	if (a)
		al = a;
	return (al);
}

static t_alias	*new_alias(char *alias, char *val)
{
	t_alias	*ret;

	if (!(ret = malloc(sizeof(t_alias))))
		m_error();
	ret->alias = ft_strdup(alias);
	ret->value = ft_strdup(val);
	ret->next = NULL;
	return (ret);
}

static int		replace_alias(t_alias *al, char *data, char *value)
{
	while (al)
	{
		if (!ft_strcmp(al->alias, data))
		{
			free(al->value);
			al->value = ft_strdup(value);
			return (1);
		}
		al = al->next;
	}
	return (0);
}

static void		add_alias(char *data)
{
	char	*value;
	t_alias	*al;
	t_alias	*tmp;

	if (!(value = ft_strchr(data, '=')) || value == data
			|| ft_strlen(data) <= 2)
	{
		ft_printf("syntax error !\nusage: alias cmd=cmd_to_be_aliased\n");
		return ;
	}
	*value++ = 0;
	if (!(al = get_alias_list(NULL)))
		get_alias_list(new_alias(data, value));
	else if (replace_alias(al, data, value))
		;
	else
	{
		tmp = new_alias(data, value);
		tmp->next = al;
		get_alias_list(tmp);
	}
}

int				ft_alias(int ac, char **av)
{
	while (*(++av))
		add_alias(*av);
	(void)ac;
	return (1);
}

char			*get_alias_value(char *name)
{
	t_alias	*al;

	if ((al = get_alias_list(NULL)))
		while (al)
		{
			if (!ft_strcmp(name, al->alias))
				return (al->value);
			al = al->next;
		}
	return (NULL);
}
