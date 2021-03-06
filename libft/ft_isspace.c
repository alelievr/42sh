/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 17:39:19 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/03/20 15:03:09 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int						ft_isspace(int c)
{
	return ((c == '\t')
	|| (c == '\n')
	|| (c == '\v')
	|| (c == '\f')
	|| (c == '\r')
	|| (c == ' '));
}
