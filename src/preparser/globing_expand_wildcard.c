/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   globing_expand_wildcard.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 18:13:31 by alelievr          #+#    #+#             */
/*   Updated: 2016/03/24 00:52:05 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"
#include <dirent.h>
#include <sys/syslimits.h>

static int				cmd_copy_next_string_to_glob(char **s, char *buff)
{
	while (ft_isspace(**s) && **s)
		++(*s);
	*buff = 0;
	if (!**s)
		return (0);
	while (!ft_isspace(**s) && **s)
		*buff++ = *(*s)++;
	*buff = 0;
	return (1);
}

void					cmd_globing_expand_wildcard(char *s, char *buff)
{
	static char		to_expand[0xF0000];
	t_mlist			*matched_list;
	t_mlist			*tmp;
	size_t			n;

	*buff = 0;
	n = 0;
	while (cmd_copy_next_string_to_glob(&s, to_expand))
	{
		printf("to expand: %s\n", to_expand);
		if (!(matched_list = cmd_match_patern_files(to_expand)))
			(void)(ft_strcat(buff, to_expand) && ft_strcat(buff, " "));
		while (matched_list)
		{
			if ((n >= MAX_WILDCARD_MATCHES) &&
					ft_printf("too many matches, stopping !\n"))
				GOTO(end);
			ft_strcat(buff, matched_list->str);
			ft_strcat(buff, " ");
			free(matched_list->str);
			tmp = matched_list->next;
			free(matched_list);
			matched_list = tmp;
			n++;
		}
	}
	end:;
}
