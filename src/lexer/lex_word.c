/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_word.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 18:10:09 by alelievr          #+#    #+#             */
/*   Updated: 2016/03/30 18:46:08 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

enum		e_syntax
{
	S_BINARY,
	S_FILE,
	S_WORD,
	S_ANYTHING
};

t_lexer	g_syntax[] = {
	{"|", S_ANYTHING},
	{">", S_FILE},
	{">>", S_FILE},
	{"<", S_FILE},
	{"<<", S_WORD},
	{"||", S_ANYTHING},
	{"&&", S_ANYTHING},
	{";", S_ANYTHING},
	{"`", S_ANYTHING}
};

int			ft_lex_word(char **word, t_commandline **cmd)
{
	if (!ft_strcmp(*word, "|"))
	(void)word;
	(void)cmd;
	return (1);
}
