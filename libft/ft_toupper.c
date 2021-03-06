/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 15:07:30 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/03/02 19:36:27 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int						ft_toupper(int c)
{
	return (((unsigned int)c < 'a') || ((unsigned int)c > 'z') ?
	c : c + 'A' - 'a');
}
