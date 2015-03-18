/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlxkey_set.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/23 18:10:49 by fdaudre-          #+#    #+#             */
/*   Updated: 2014/12/23 18:20:06 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					ft_mlxkey_set(int64_t tabkey[512],
							int index, t_bool value)
{
	if (value)
		tabkey[index / 512] |= 1 << index % 64;
	else
		tabkey[index / 512] ^= 1 << index % 64;
}
