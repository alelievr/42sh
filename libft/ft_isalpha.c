/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 14:34:22 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/03/16 17:33:16 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int						ft_isalpha(int c)
{
	unsigned int		x;

	x = (unsigned int)c;
	return (!((x < 'A') || ((x > 'Z') && (x < 'a')) || (x > 'z')));
}
