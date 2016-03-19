/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   globing_expand_braces.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 17:56:51 by alelievr          #+#    #+#             */
/*   Updated: 2016/03/19 20:50:26 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

static int			cmd_copy_next_brace_name(char **s, char *buff, size_t max)
{
	size_t		i;

	i = 0;
	while (**s && **s != '}' && **s != ',')
	{
		if (i == max - 2)
			break ;
		buff[i++] = **s;
		++(*s);
	}
	buff[i] = 0;
	return (**s);
}

static void		cmd_append_braces_content(char *before, char *in,
		char *after, char *buff)
{
	ft_strcat(buff, before);
	ft_strcat(buff, in);
	ft_strcat(buff, after);
	ft_strcat(buff, " ");
}

static void		cmd_copy_after_braces(char *s, char *bafter, size_t max)
{
	size_t		i;
	while (*s && *s != '}')
		s++;
	if (*s == '}')
		s++;
	i = 0;
	while (*s)
	{
		if (i == max - 2)
			break ;
		*bafter++ = *s++;
		i++;
	}
	*bafter = 0;
}

void			cmd_globing_expand_braces(char *s, char *buff)
{
	static char		bcontent[0xF000];
	static char		bafter[0xF000];
	static char		bname[0xF000];
	size_t			i;

	i = 0;
	while (*s && *s != '{')
		bcontent[i++] = *s++;
	bcontent[i] = 0;
	cmd_copy_after_braces(s, bafter, sizeof(bafter));
	*buff = 0;
	s++;
	while (cmd_copy_next_brace_name(&s, bname, sizeof(bname)))
	{
		printf("bin = %s\n", bname);
		cmd_append_braces_content(bcontent, bname, bafter, buff);
		s++;
	}
}
