/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 20:55:21 by alelievr          #+#    #+#             */
/*   Updated: 2016/03/31 21:04:46 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

int			lex_check_next_value(t_commandline **cmd, char **word)
{
	t_operator	*o;

	if (!word[1])
		LEXER_ERROR("missing identifier `%s'\n", *word);
	if (!(o = get_current_operator(*cmd)))
		LEXER_ERROR("syntax error near `%s'\n", *word);
	return (1);
}
