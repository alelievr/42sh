/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 15:39:25 by alelievr          #+#    #+#             */
/*   Updated: 2016/03/18 18:48:46 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"
#define CHECK_QUOTE(x, y) (*x == '\'' && ((x==y)||(x != y && *(x - 1) != '\\')))
#define CHECK_DBQUOTE(x, y) (*x == '\"' && ((x==y)||(x != y && *(x-1) != '\\')))
#define CHECK_BKQUOTE(x, y) (*x == '`' && ((x==y)||(x != y && *(x-1) != '\\')))
#define SKIP_QUOTE(x) skip_char(x, '\'')
#define SKIP_BKQUOTE(x) skip_char(x, '`')

static inline int	skip_blank(char **s)
{
	while (**s && ft_isspace(**s))
		(*s)++;
	return (**s == 0);
}

static inline int	skip_char(char **s, char c)
{
	(*s)++;
	while (**s && **s != c)
		(*s)++;
	return (**s == 0);
}

static inline int	skip_dbquote(char **s, char *begin)
{
	(*s)++;
	while (**s && **s != '\"')
	{
		if (CHECK_QUOTE(*s, begin) && SKIP_QUOTE(s))
			break ;
		if (CHECK_BKQUOTE(*s, begin) && SKIP_BKQUOTE(s))
			break ;
		(*s)++;
	}
	return (**s == 0);
}

static inline int	skip_word(char **s, char *begin)
{
	while (**s && !ft_isspace(**s))
	{
		if (CHECK_QUOTE(*s, begin) && SKIP_QUOTE(s))
			break ;
		else if (CHECK_BKQUOTE(*s, begin) && SKIP_BKQUOTE(s))
			break ;
		else if (CHECK_DBQUOTE(*s, begin) && skip_dbquote(s, begin))
			break ;
		(*s)++;
	}
	return (**s == 0);
}

//this function must be called with a perfectly closed ' " and `
char				**cmd_split_quote(char *cmd)
{
	static char		*ptrs[0xF0000];
	size_t			nptr;
	size_t			len;
	char			*begin;

	begin = cmd;
	nptr = 0;
	len = 0;
	while (42)
	{
		if (skip_blank(&cmd))
			break ;
		ptrs[nptr++] = cmd;
		len++;
		if (CHECK_QUOTE(cmd, begin) && SKIP_QUOTE(&cmd))
			break ;
		else if (CHECK_BKQUOTE(cmd, begin) && SKIP_BKQUOTE(&cmd))
			break ;
		else if (CHECK_DBQUOTE(cmd, begin) && skip_dbquote(&cmd, begin))
			break ;
		else if (skip_word(&cmd, begin))
			break ;
		ptrs[nptr++] = cmd;
	}
	ptrs[nptr++] = cmd;
	return (cmd_split_quote_table(ptrs, len));
}
