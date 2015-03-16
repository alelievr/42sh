/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/14 16:48:12 by alelievr          #+#    #+#             */
/*   Updated: 2015/03/16 17:21:08 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"
#include <sys/types.h>
#include <pwd.h>

static void	build_path(void)
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

static void	build_env2(void)
{
	struct passwd	*pw;
	char			buff[0xF00];

	getcwd(buff, 0xF00);
	ft_strcat(buff, "/42sh");
	pw = getpwuid(getuid());
	if (!get_env("HOME"))
		set_env("HOME", pw->pw_dir);
	if (!get_env("USER"))
		set_env("USER", pw->pw_name);
	if (!get_env("SHELL"))
		set_env("SHELL", buff);
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
	build_env2();
	return (0);
}
