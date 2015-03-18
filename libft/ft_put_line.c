/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/16 21:05:32 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/01/21 21:04:21 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline void		ft_put_line_horz(t_mlximg *datas,
							int (*fcolor)(const t_mlximg *datas,
							const t_matrix *, const t_matrix *, t_2dpt *),
							const t_matrix *p1, const t_matrix *p2)
{
	static t_2dpt		p;
	int					bound;

	p.y = (int)p1->tab[0][1];
	if ((p.y < 0) || (p.y > datas->nlines))
		return ;
	p.x = (int)p1->tab[0][0] - 1;
	bound = datas->lsize / datas->bpp * 8 - 1;
	if (p.x < 0)
		p.x = -1;
	while (++p.x < (int)p2->tab[0][0])
	{
		if (p.x > bound)
			return ;
		ft_put_pixel(datas, &p, fcolor(datas, p1, p2, &p));
	}
}

static inline void		ft_put_line_right(t_mlximg *datas,
							int (*fcolor)(const t_mlximg *datas,
							const t_matrix *, const t_matrix *, t_2dpt *),
							const t_matrix *p1, const t_matrix *p2)
{
	if ((int)p2->tab[0][1] > (int)p1->tab[0][1])
	{
		if (p2->tab[0][0] - p1->tab[0][0] >= p2->tab[0][1] - p1->tab[0][1])
			ft_put_line_octant1(datas, fcolor, p1, p2);
		else
			ft_put_line_octant2(datas, fcolor, p1, p2);
	}
	else if ((int)p2->tab[0][1] < (int)p1->tab[0][1])
	{
		if (p2->tab[0][0] - p1->tab[0][0] >= p1->tab[0][1] - p2->tab[0][1])
			ft_put_line_octant3(datas, fcolor, p1, p2);
		else
			ft_put_line_octant4(datas, fcolor, p1, p2);
	}
	else
		ft_put_line_horz(datas, fcolor, p1, p2);
}

static inline void		ft_put_line_vert(t_mlximg *datas,
							int (*fcolor)(const t_mlximg *datas,
							const t_matrix *, const t_matrix *, t_2dpt *),
							const t_matrix *p1, const t_matrix *p2)
{
	static t_2dpt		p;
	int					bound;

	p.x = (int)p1->tab[0][0];
	if ((p.x < 0) || (p.x > (datas->lsize / datas->bpp * 8 - 1)))
		return ;
	if ((int)p2->tab[0][1] - (int)p1->tab[0][1] > 0)
	{
		p.y = MAX(0, (int)p1->tab[0][1]);
		bound = MIN(datas->nlines + 1, (int)p2->tab[0][1]);
		while (p.y < bound)
		{
			ft_put_pixel(datas, &p, fcolor(datas, p1, p2, &p));
			++p.y;
		}
		return ;
	}
	p.y = MIN(datas->nlines, (int)p1->tab[0][1]);
	bound = MAX(-1, (int)p2->tab[0][1]);
	while (p.y > bound)
	{
		ft_put_pixel(datas, &p, fcolor(datas, p1, p2, &p));
		--p.y;
	}
}

void					ft_put_line(t_mlximg *datas,
							int (*fcolor)(const t_mlximg *datas,
							const t_matrix *, const t_matrix *, t_2dpt *),
							const t_matrix *p1, const t_matrix *p2)
{
	if ((int)p2->tab[0][0] < (int)p1->tab[0][0])
		ft_put_line_right(datas, fcolor, p2, p1);
	else if ((int)p2->tab[0][0] > (int)p1->tab[0][0])
		ft_put_line_right(datas, fcolor, p1, p2);
	else
		ft_put_line_vert(datas, fcolor, p1, p2);
}
