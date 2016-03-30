/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <fdaudre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/20 10:20:48 by fdaudre-          #+#    #+#             */
/*   Updated: 2016/03/30 18:09:19 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

t_commandline			*ft_lex(char **cmd)
{
	t_commandline		*ret;

	if (!cmd || !*cmd)
		return (NULL);
	ret = NULL;
	while (*cmd)
	{
		if (!ft_lex_word(cmd, &ret))
			return (NULL);
		if (!*cmd)
			break ;
		cmd++;
	}
	return (ret);
}
