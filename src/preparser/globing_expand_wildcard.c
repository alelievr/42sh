/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   globing_expand_wildcard.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 18:13:31 by alelievr          #+#    #+#             */
/*   Updated: 2016/03/23 22:15:47 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"
#include <dirent.h>
#include <sys/syslimits.h>

void					cmd_globing_expand_wildcard(char *s, char *buff)
{
	t_mlist		*matched_list;
	t_mlist		*tmp;
	size_t		n;

	*buff = 0;
	n = 0;
	matched_list = cmd_match_patern_files(s);
	while (matched_list)
	{
		if (n >= MAX_WILDCARD_MATCHES)
		{
			ft_printf("too many matches, stopping !\n");
			break ;
		}
		ft_strcat(buff, matched_list->str);
		ft_strcat(buff, " ");
		free(matched_list->str);
		tmp = matched_list->next;
		free(matched_list);
		matched_list = tmp;
		n++;
	}
}
