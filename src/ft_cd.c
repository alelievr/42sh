/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 21:19:16 by alelievr          #+#    #+#             */
/*   Updated: 2015/03/20 11:24:16 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

void		ft_cd_dir(char *path, char *old_pwd)
{
	char	cwd[0xF00];
	char	old_cwd[0xF00];

	ft_bzero(cwd, 0xF00);
	ft_bzero(old_cwd, 0xF00);
	getcwd(old_cwd, 0xF00);
	chdir(path);
	getcwd(cwd, 0xF00);
	set_env("PWD", cwd);
	strcpy(old_pwd, old_cwd);
	set_env("OLDPWD", old_pwd);
}

static void	ft_cd_err(int err, char *name)
{
	if (err == -1)
	{
		ft_putstr("cd: no such file or directory: ");
		ft_putendl(name);
	}
	else if (err == -2)
	{
		ft_putstr("cd: permission denied: ");
		ft_putendl(name);
	}
}

int			ft_cd(int ac, char **av)
{
	static char	old_pwd[0xF00] = {0};
	int			err;

	if (ac == 1)
		ft_cd_dir(get_env("HOME"), old_pwd);
	else if (ac == 2)
	{
		if (!ft_strcmp(av[1], "-"))
		{
			if (old_pwd == NULL)
				ft_putstr("cd: old pwd not set !\n");
			else
				ft_cd_dir(old_pwd, old_pwd);
		}
		else if ((err = is_dir(av[1])) > 0)
			ft_cd_dir(av[1], old_pwd);
		else
			ft_cd_err(err, av[1]);
	}
	else
		ft_putstr("cd: Too many arguments\n");
	return (1);
}
