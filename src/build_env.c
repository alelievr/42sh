/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/14 16:48:12 by alelievr          #+#    #+#             */
/*   Updated: 2015/03/16 16:50:29 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

void		build_path(void)
{
	char	buff[0xF000];
	int		i;

	i = 0;
	buff[0] = 0;
	if (is_dir("/usr/bin"))
		ft_strcat(buff, "/usr/bin");
	ft_strcat(buff, ":");
	if (is_dir("/bin"))
		ft_strcat(buff, "/bin");
	ft_strcat(buff, ":");
	if (is_dir("/usr/local/bin"))
		ft_strcat(buff, "/usr/local/bin");
	ft_strcat(buff, ":");
	if (is_dir("/usr/sbin"))
		ft_strcat(buff, "/sbin");
	ft_strcat(buff, ":");
	if (is_dir("/usr/sbin"))
		ft_strcat(buff, "/usr/sbin");
	while (buff[i + 1])
		i++;
	while (buff[i] == ':')
		i--;
	buff[i + 1] = 0;
	set_env("PATH", buff);
}

int			build_env(void)
{
	char	buff[0xF000];
	int		tmp;

	if (!get_env("PWD"))
	{
		getcwd(buff, 0xF000);
		set_env("PWD", buff);
	}
	if (!get_env("SHLVL"))
		set_env("SHLVL", "1");
	else
	{
		tmp = ft_deconvert((unsigned char *)get_env("SHLVL"), 10);
		ft_convert(buff, tmp + 1, 10, 0);
		set_env("SHLVL", buff);
	}
	if (!get_env("PATH"))
		build_path();
	return (0);
}
