/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raw_terminal_mode.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 11:23:44 by alelievr          #+#    #+#             */
/*   Updated: 2015/03/19 11:44:58 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include <termios.h>
#include "ft_42sh.h"

void		raw_terminal_mode(void)
{
	struct termios	t;

//ft_printf("TERM: [%s]\n", get_env("TERM"));
	tgetent(NULL, get_env("TERM")); // 
	tcgetattr(STDIN_FILENO, &t);
	t.c_lflag &= ~(ECHO | ICANON);
//	t.c_oflag &= ~(OPOST);
	t.c_cc[VMIN] = 1;
	t.c_cc[VTIME] = 0;
	tcsetattr(STDIN_FILENO, TCSADRAIN, &t);
}
