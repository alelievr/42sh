/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 11:42:14 by alelievr          #+#    #+#             */
/*   Updated: 2016/03/06 19:29:38 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_strlen(char const *s)
{
	const unsigned long	*str = (unsigned long *)(unsigned long)s;
	register size_t		ret;
	const char			*cp;

	ret = 0;
	while (42)
	{
		if ((LONGCHR_NULL(*str++)))
		{
			cp = (const char *) (str - 1);
			IFRET__(cp[0] == 0, cp - s);
			IFRET__(cp[1] == 0, cp - s + 1);
			IFRET__(cp[2] == 0, cp - s + 2);
			IFRET__(cp[3] == 0, cp - s + 3);
			IFRET__(cp[4] == 0, cp - s + 4);
			IFRET__(cp[5] == 0, cp - s + 5);
			IFRET__(cp[6] == 0, cp - s + 6);
			IFRET__(cp[7] == 0, cp - s + 7);
		}
	}
	return (0);
}
