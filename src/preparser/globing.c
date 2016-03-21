/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   globing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 18:23:25 by alelievr          #+#    #+#             */
/*   Updated: 2016/03/22 00:49:16 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#define	NOT_ESCAPED(b, s, c) (*(s) == c && (s == b || *((s) - 1) != '\\'))
#define	BRCMP_(s1, s2) (ft_strchr(cmd_get_brq_value(s2), *s1))
#define	CHAR_CMP(s1,s2,be) (*(s1)==*(s2)||NOT_ESCAPED(be,s2,'?')||BRCMP_(s1,s2))
#define CHECK_END(x) {char *__ = x; while (*__=='*')__++; if (!*__) return (1);}

char	*cmd_get_brq_value(char *s2)
{
	static char		match[257];

	if (*s2)
	(void)s2;
	return (match);
}

int		cmd_get_next_occ(char **s, char *s1)
{
	char	*begin;
	char	*b;
	char	*tmp;

	if (!**s)
		return (-1);
	while (**s == '*')
		(*s)++;
	begin = *s;
	b = s1;
	while (**s && **s != '*' && *s1)
	{
		tmp = s1;
		printf("+++ s1 = %s, s2 = %s\n", s1, *s);
		while (CHAR_CMP(s1, (*s), begin) && **s && *s1)
		{
			//printf("\t\'%c\' == \'%c\', %i\n", *s1, **s, NOT_ESCAPED(begin, *s, '?'));
			s1++;
			(*s)++;
		}
		printf("--- s1 = %s, s2 = %s\n", s1, *s);
		if (!**s || **s == '*')
			return (s1 - b);
		*s = begin;
		s1 = tmp + 1;
	}
	return (-1);
}

int		cmd_globing_match(char *s1, char *s2)
{
	char	*begin;
	char	*tmp;
	int		ret;

	printf("s1 = %s, s2 = %s\n", s1, s2);
	begin = s2;
	while (CHAR_CMP(s1, s2, begin) && *s1 && *s2 && s2++)
		s1++;
	if (!*s1 && !*s2)
		return (1);
	if (*s2 == '*')
		CHECK_END(s2);
	if (*s2 == '*')
	{
		tmp = s2;
		printf("=> s1 = %s, s2 = %s\n", s1, s2);
		while ((ret = cmd_get_next_occ(&s2, s1)) != -1)
		{
			s1 += ret;
			printf("ret = %i\n", ret);
			if (cmd_globing_match(s1, s2))
				return (1);
			s2 = tmp;
		}
	}
	return (0);
}

int		main(int ac, char **av)
{
	if (ac == 3)
		printf("%i\n", cmd_globing_match(av[1], av[2]));
	return (0);
}
