/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 15:57:55 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/02/27 14:02:01 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					ft_strdel(char **as)
{
	if (LIBFT_DEBUG && (as == NULL))
		ft_errnullptr("ft_strdel");
	if (as == NULL)
		return ;
	free(*as);
	*as = NULL;
}
