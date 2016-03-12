/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 16:30:07 by alelievr          #+#    #+#             */
/*   Updated: 2016/03/11 20:18:27 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"
#define PROMPT42		"$> "
#include <errno.h>

static t_pr_code		g_pr_codes[] =
{
	{PR_RI, pr_move},
	{PR_LE, pr_move},
	{PR_S_RI, pr_move},
	{PR_S_LE, pr_move},
	{PR_S_UP, pr_move},
	{PR_S_DO, pr_move},
	{PR_BEG, pr_move},
	{PR_C_A, pr_move},
	{PR_END, pr_move},
	{PR_C_E, pr_move},
	{PR_BACK, pr_del},
	{PR_DEL, pr_del},
	{PR_C_K, pr_del},
	{PR_C_U, pr_del},
	{PR_UP, pr_history},
	{PR_DW, pr_history},

	{PR_TAB, pr_tab},
	{0, NULL}
};

static void				pr_initline(t_prompt *d)
{
	static struct winsize	ws;
	size_t					l;

	if (ioctl(0, TIOCGWINSZ, &ws) == -1)
	{
		ft_printf("ioctl error: %s\n", strerror(errno));
		exit(1);
	}
	d->col = ws.ws_col;
	l = ft_strlen(PROMPT42) + d->index;
	if (l > (ws.ws_col - !(l % ws.ws_col)))
	{
		if (!(!d->buff[d->index] && (l == ws.ws_col)))
		ft_putstr(tparm(tgetstr("UP", NULL), l / (ws.ws_col)
					- !((l % ws.ws_col) || (d->buff[d->index]))));
	}
	ft_putstr(tgetstr("cr", NULL));
	ft_putstr(tgetstr("cd", NULL));
}

static void				pr_affbuff(t_prompt *d)
{
	size_t					l;
	size_t					gap;
	size_t					x;

ft_putstr(tgetstr("sc", NULL));
ft_putstr(tgetstr("ho", NULL));
ft_printf("[%llu]", d->key);
ft_putstr(tgetstr("rc", NULL));
	l = ft_strlen(d->buff) - d->index;
	gap = (ft_strlen(PROMPT42) + ft_strlen(d->buff)) % d->col;
	if (!gap)
		gap = d->col - 1;
	ft_printf("%{F}%s%{!F}%s", 123, PROMPT42, d->buff);
	if (l > gap)
	{
		x = l - gap;
		x = x / d->col + !!(x % d->col);
		ft_putstr(tparm(tgetstr("UP", NULL), x));
		ft_putstr(tparm(tgetstr("ch", NULL), d->col - 1));
		l = l - gap - d->col * (x - 1);
		l += (l == 0 ? 0 : -1);
	}
	if (l)
		ft_putstr(tparm(tgetstr("LE", NULL), l));
}

static inline void		get_command_init(t_prompt *d)
{
	raw_terminal_mode();
	d->index = 0;
	d->len = 0;
	d->buff[0] = '\0';
	pr_initline(d);
}

static inline void		pr_history_append(t_prompt *d)
{
	ft_printf("%{F}%s%{!F}%s\n", 123, PROMPT42, d->buff);
	ft_lstadd(&d->history, ft_lstnew(d->buff, d->len));
}

char					*get_command(void)
{
	static t_prompt		d;
	int					i;

	get_command_init(&d);
	while (42)
	{
		pr_affbuff(&d);
		d.key = 0;
		if ((read(0, &(d.key), 8) < 1) || (d.key == 4) || (d.key == 10))
			break ;
		pr_initline(&d);
		if (ft_isprint(d.key) && (d.key != '\t'))
			pr_addchar(&d);
		i = -1;
		while (g_pr_codes[++i].f != NULL)
			if (d.key == g_pr_codes[i].code)
			{
				g_pr_codes[i].f(&d);
				break ;
			}
	}
	pr_initline(&d);
	pr_history_append(&d);
	default_terminal_mode();
	return ((d.key == 4) && (!d.buff[0]) ? NULL : (char *)d.buff);
}
