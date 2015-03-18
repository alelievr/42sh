/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errnullptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 12:00:25 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/02/27 12:24:20 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					ft_errnullptr(char const *str)
{
	ft_fprintf(2, "%{F}error: NULL ptr: %s (aborting)%{!F}\n", FT_ECOL, str);
	exit(-1);
}
