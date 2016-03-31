/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <fdaudre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/20 10:20:48 by fdaudre-          #+#    #+#             */
/*   Updated: 2016/03/31 18:57:04 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"


static t_lexer		g_syntax[] = {
	{"|", lex_pipe},
	{">", lex_rredir},
	{">>", lex_drredir},
	{"<", lex_lredir},
	{"<<", lex_dlredir},
	{"||", lex_or},
	{"&&", lex_and},
	{";", lex_semicolon},
	{"[0-9]>&", lex_fdredir},
	{"[0-9]>", lex_fdrredir},
	{">&", lex_allredir},
	{">>&", lex_alldredir},
	{"[0-9]>>", lex_dfdredir},
	{"[0-9]>>&", lex_alldfdredir},
	{"&", lex_background},
//	{"`", lex_backquote},
	{NULL, 0}
};

static int			ft_lex_word(char ***word, t_commandline **cmd)
{
	size_t		i;
	int			matched;

	matched = 0;
	if (!*cmd)
		*cmd = lex_new_commandline();
	i = -1;
	while (g_syntax[++i].op)
		if (cmd_globing_match(**word, g_syntax[i].op))
		{
			matched = 1;
			if (!g_syntax[i].f(word, cmd))
				return (0);
			break ;
		}
	if (!matched)
		if (!add_word_to_current_command(*word, cmd))
			return (0);
	return (1);
}

t_commandline			*ft_lex(char **cmd)
{
	t_commandline		*ret;

	if (!cmd || !*cmd)
		return (NULL);
	ret = NULL;
	while (*cmd)
	{
		printf("lexing: %s\n", *cmd);
		if (!ft_lex_word(&cmd, &ret))
			return (NULL);
		if (!*cmd)
			break ;
		cmd++;
	}
	return (ret);
}

int						is_operator(char *s)
{
	size_t		i;

	i = -1;
	while (g_syntax[++i].op)
		if (cmd_globing_match(s, g_syntax[i].op))
			return (1);
	return (0);
}

int						match_operator(char *s)
{
	size_t		i;
	size_t		j;
	char		op[5];

	j = 5;
	while (j - 1)
	{
		ft_bzero(op, sizeof(op));
		ft_strlcpy(op, s, j);
		i = -1;
		while (g_syntax[++i].op)
			if (cmd_globing_match(op, g_syntax[i].op))
				return (j - 1);
		j--;
	}
	return (0);
}
