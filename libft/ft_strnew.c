/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 15:51:39 by fdaudre-          #+#    #+#             */
/*   Updated: 2014/11/10 20:40:37 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char					*ft_strnew(size_t size)
{
	char				*str;
	int					i;

	str = (char *)malloc(++size * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = -1;
	while (++i < (int)size)
		str[i] = '\0';
	return (str);
}
