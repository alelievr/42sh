/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_dir.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 15:33:24 by alelievr          #+#    #+#             */
/*   Updated: 2015/03/16 16:35:02 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"
#include <dirent.h>

int		is_dir(char *path)
{
	DIR	*tmp;

	if ((tmp = opendir(path)) == NULL)
		return (0);
	else
		closedir(tmp);
	return (1);
}
