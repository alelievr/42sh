/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 16:30:07 by alelievr          #+#    #+#             */
/*   Updated: 2016/03/18 02:37:33 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"
#include <errno.h>
#define IS_CHAR(x)	(x > 255llu) ? -1 : x

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
	{PR_C_P, pr_vim_export},

	{PR_TAB, pr_tab},
	{0, NULL}
};

void					pr_initline(t_prompt *d)
{
	static struct winsize	ws;
	size_t					l;

	if (ioctl(0, TIOCGWINSZ, &ws) == -1)
	{
		ft_printf("ioctl error: %s\n", strerror(errno));
		default_terminal_mode();
		d->good_prompt = 0;
		return ;
	}
	if (!ws.ws_col && !(d->good_prompt = 0))
		default_terminal_mode();
	if (!d->good_prompt)
		return ;
	d->col = ws.ws_col;
	l = ft_strlen(PROMPT42) + d->index;
	if (l > (ws.ws_col - !(l % ws.ws_col))) //number of line of my cmd-line
	{
		if (!(!d->buff[d->index] && (l == ws.ws_col)))
			ft_putstr(tparm(tgetstr("UP", NULL), l / (ws.ws_col) //up x - 1 times the nline
						- !((l % ws.ws_col) || (d->buff[d->index]))));
	}
	ft_putstr(tgetstr("cr", NULL));
	ft_putstr(tgetstr("cd", NULL));
}

static void				pr_affbuff_line(char *buff, size_t index, size_t col, int prompt)
{
	size_t					l;
	size_t					gap;
	size_t					x;

	l = ft_strlen(buff) - index;
	gap = (ft_strlen(PROMPT42) + ft_strlen(buff)) % col;
	if (!gap)
		gap = col - 1;
	pr_display_line(buff, prompt);
	if (l > gap)
	{
		x = l - gap;
		x = x / col + !!(x % col);
		ft_putstr(tparm(tgetstr("UP", NULL), x));
		ft_putstr(tparm(tgetstr("ch", NULL), col - 1));
		l = l - gap - col * (x - 1);
		l += (l == 0 ? 0 : -1);
	}
	if (l)
		ft_putstr(tparm(tgetstr("LE", NULL), l));
}

static void				pr_affbuff(t_prompt *d)
{
//	size_t			nlines;
//	size_t			x;
ft_putstr(tgetstr("sc", NULL));
ft_putstr(tgetstr("ho", NULL));
ft_printf("[%llu]", d->key);
ft_putstr(tgetstr("rc", NULL));

//	ft_putstr(tparm(tgetstr("UP", NULL), nlines));
//	x = get_col_index(d);
	pr_affbuff_line(d->buff, d->index, d->col, 42);
}

inline void				get_command_init(t_prompt *d)
{
	if (d->good_prompt)
		raw_terminal_mode();
	d->history_index = 0;
	d->index = 0;
	d->len = 0;
	d->buff[0] = '\0';
	pr_initline(d);
}

static inline void		pr_history_append(t_prompt *d)
{
	char		*tmp;

	tmp = d->buff;
	while (*tmp)
		if (!ft_isspace(*tmp++))
		{
			ft_lstadd(&d->history, ft_lstnew(d->buff, ft_strlen(d->buff) + 1));
			get_history_list(d->history);
			break ;
		}
}

int						get_line(t_prompt *d)
{
	size_t		i;

	if (d->good_prompt == 0)
		return (read(0, d->buff, sizeof(d->buff)));
	while (42)
	{
		pr_affbuff(d);
		d->key = 0;
		if ((read(0, &(d->key), sizeof(d->key)) < 1) || (d->key == 4) || (d->key == 10))
			break ;
		pr_initline(d);
		if (ft_isprint(IS_CHAR(d->key)) && (d->key != '\t'))
			pr_addchar(d);
		i = -1;
		while (g_pr_codes[++i].f != NULL)
			if (d->key == g_pr_codes[i].code)
			{
				g_pr_codes[i].f(d);
				break ;
			}
		if (d->key == PR_C_P)
			break ;
	}
	return (d->key);
}

char					*get_command(t_prompt *d)
{
	int			once;

	once = 1;
	signal(SIGINT, pr_ctrlc_handler);
	get_command_init(d);
	while (check_unterminated_sequences(d) || once)
	{
		if (!d->good_prompt)
			ft_printf("%{F}%s%{!F}", 123, PROMPT42);
		if (get_line(d) == PR_C_P)
			break ;
		pr_initline(d);
		if (once)
			once = 0;
	}
	pr_initline(d);
	pr_history_append(d);
	signal(SIGINT, siguser_handler);
	if (d->good_prompt)
		pr_display(d);
	if (d->good_prompt)
		default_terminal_mode();
	return ((d->key == 4) && (!d->buff[0]) ? NULL : (char *)d->buff);
}
