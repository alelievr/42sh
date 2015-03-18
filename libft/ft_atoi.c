/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 21:32:58 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/03/16 17:43:46 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int						ft_atoi(char const *str)
{
	int					i;
	int					sign;
	int					nbr;

	if (LIBFT_DEBUG && (str == NULL))
		ft_errnullptr("ft_atoi");
	i = 0;
	nbr = 0;
	while (ft_isspace(str[i]))
		++i;
	sign = (str[i] == '-' ? -1 : 1);
	if ((str[i] == '-') || (str[i] == '+'))
		i++;
	while ((str[i] > '/') && (str[i] < ':'))
		nbr = (10 * nbr) + (str[i++] - '0');
	return (sign * nbr);
}
