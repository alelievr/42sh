/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 21:19:51 by alelievr          #+#    #+#             */
/*   Updated: 2015/03/17 23:59:42 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"
#define OP_N 0
#define OP_E 1
#define OP_ME 2

#include <stdio.h>
static int	ft_display_code(int code, char *str)
{
	int		ret;
	char	c;

	c = code;
	ft_putnbr(c);
	write(1, &c, 1);
	ret = 0;
	str++;
	while (*str >= '0' && *str <= '9')
	{
		str++;
		ret++;
	}
	return (ret);
}

static int	nbr_len(char *str)
{
	int		i;

	i = 0;
	while (*str >= '0' && *str <= '9')
	{
		str++;
		i++;
	}
	return (i);
}

static void	ft_option_echo(char **av, int option, int i)
{
	int		j;

	i = 0;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] == '\\')
			{
				if (av[i][j + 1] == 'x')
					j += ft_display_code(ft_ndeconvert(av[i] + j + 2, 16,
								nbr_len(av[i] + j + 2)), av[i] + j);
				else if (av[i][j + 1] == '0')
					j += ft_display_code(ft_ndeconvert(av[i] + j + 2, 8,
								nbr_len(av[i] + j + 2)), av[i] + j);
				else
					write(1, &av[i][j], 1);
			}
			else
				write(1, &av[i][j], 1);
			j++;
		}
		i++;
	}
	(void)option;
}

static char	**get_option(char **av, int *option)
{
	int		i;

	*option = 0;
	while (*av && *av[0] == '-')
	{
		i = 0;
		while (av[0][0] && av[0][++i])
			if (av[0][i] == 'e')
				BIT_ON(*option, OP_E);
			else if (av[0][i] == 'E')
				BIT_ON(*option, OP_ME);
			else if (av[0][i] == 'n')
				BIT_ON(*option, OP_N);
			else
				break ;
	//	if (av[1] && *av[1] != '-')
	//		break ;
		av++;
	}
	return (av);
}

int			ft_echo(int ac, char **av)
{
	int		i;
	int		option;

	if (av == NULL || ac == 1)
		return (write(1, "\n", 1));
	i = 0;
	av = get_option(av + 1, &option);
	if (!BIT_TEST(option, OP_E))
		while (av[i])
			ft_putstr(av[i++]);
	else
		ft_option_echo(av + 1, option, i);
	if (!BIT_TEST(option, OP_N))
		write(1, "\n", 1);
	(void)ac;
	return (1);
}
