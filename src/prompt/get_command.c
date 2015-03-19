/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 16:30:07 by alelievr          #+#    #+#             */
/*   Updated: 2015/03/19 15:13:10 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"
#define PROMPT42		"$> "

static t_pr_code		g_pr_codes[] =
{
	{PR_RI, pr_move},
	{PR_LE, pr_move},
	{PR_S_RI, pr_move},
	{PR_S_LE, pr_move},
	{PR_BEG, pr_move},
	{PR_C_A, pr_move},
	{PR_END, pr_move},
	{PR_C_E, pr_move},
	{PR_BACK, pr_del},
	{PR_DEL, pr_del},
	{PR_C_K, pr_del},
	{PR_C_U, pr_del},
	{0, NULL}
};

static void				pr_addchar(t_prompt *d)
{
	size_t				tmp;

	tmp = ft_strlen(d->buff);
	d->buff[tmp + 1] = '\0';
	while (tmp != d->index)
	{
		d->buff[tmp] = d->buff[tmp - 1];
		--tmp;
	}
	d->buff[tmp] = d->key;
	++(d->index);
}

static void				pr_initline(t_prompt *d)
{
	static struct winsize	ws;
	size_t					l;

	ioctl(0, TIOCGWINSZ, &ws);
	if ((l = ft_strlen(PROMPT42) + d->index) > ws.ws_col)
		ft_putstr(tparm(tgetstr("UP", NULL), l / (ws.ws_col + (l % ws.ws_col ? 0 : 1))));
	ft_putstr(tgetstr("cr", NULL));
	ft_putstr(tgetstr("cd", NULL)); // clear
}

static void				pr_affbuff(t_prompt *d)
{
	size_t					l;

//ft_printf("[%llu]\n", d->key);
	ft_printf("%{F}%s%{!F}%s", 123, PROMPT42, d->buff);
	if ((l = ft_strlen(d->buff) - d->index))
		ft_putstr(tparm(tgetstr("LE", NULL), l));
}

static inline void		get_command_init(t_prompt *d)
{
	raw_terminal_mode();
	d->index = 0;
	d->buff[0] = '\0';
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
	default_terminal_mode();
	return ((d.key == 4) && (!d.buff[0]) ? NULL : (char *)d.buff);
}
