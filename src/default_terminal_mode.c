/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default_terminal_mode.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 11:31:05 by alelievr          #+#    #+#             */
/*   Updated: 2015/03/18 11:37:59 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"
#include <termios.h>
#include <term.h>

void		default_terminal_mode(void)
{
	struct termios	t;

	tcgetattr(STDIN_FILENO, &t);
	t.c_lflag |= ~(ECHO | ICANON);
	t.c_oflag |= ~(OPOST);
	tcsetattr(STDIN_FILENO, TCSADRAIN, &t);
}
