/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 15:27:22 by alelievr          #+#    #+#             */
/*   Updated: 2016/03/18 19:19:09 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

char		**preparse_command(char *cmd)
{
	char	**ret;
	int		i;

	if (!(cmd = cmd_replace_alias(cmd)))
		return (NULL);
	if (!(ret = cmd_split_quote(cmd)))
		return (NULL);
	i = -1;
	while (ret[++i])
	{
		ret[i] = cmd_replace_vars(ret[i]);
		ret[i] = cmd_globing_expand(ret[i]);
	}
	return (ret);
}
