/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_dir.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 15:33:24 by alelievr          #+#    #+#             */
/*   Updated: 2015/03/18 01:23:52 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"
#include <dirent.h>

int		is_dir(char *path)
{
	DIR	*tmp;

	if ((tmp = opendir(path)) == NULL)
		return (-1);
	else
	{
		if (access(path, R_OK) == -1)
			return (-2);
		closedir(tmp);
	}
	return (1);
}
