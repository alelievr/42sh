/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_line2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/26 19:20:54 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/01/22 12:00:48 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void				clipping(t_mlximg *datas, const t_matrix *p, t_2dpt *p1)
{
	static t_2dpt		p2;
	double				delta;

	p2.x = (int)p->tab[0][0];
	p2.y = (int)p->tab[0][1];
	delta = (double)(p2.x - p1->x) / (double)(p2.y - p1->y);
	if (p1->x < 0)
	{
		p1->y += (int)((0 - (double)p1->x) / delta);
		p1->x = 0;
	}
	if (p1->y < 0)
	{
		p1->x += (int)((0 - (double)p1->y) * delta);
		p1->y = 0;
	}
	if (p1->y > datas->nlines)
	{
		p1->x += (int)((datas->nlines - (double)p1->y) * delta);
		p1->y = datas->nlines;
	}
}

inline void				ft_put_line_octant1(t_mlximg *datas,
							int (*fcolor)(const t_mlximg *datas,
							const t_matrix *, const t_matrix *, t_2dpt *),
							const t_matrix *p1, const t_matrix *p2)
{
	static int			e;
	static t_2dpt		p;
	int					xmax;

	p.x = (int)p1->tab[0][0];
	p.y = (int)p1->tab[0][1];
	clipping(datas, p2, &p);
	if ((p.x < 0) || (p.y > datas->nlines))
		return ;
	e = p2->tab[0][0] - p1->tab[0][0];
	xmax = MIN(datas->lsize / datas->bpp * 8, (int)p2->tab[0][0] + 1);
	while (p.x < xmax)
	{
		ft_put_pixel(datas, &p, fcolor(datas, p1, p2, &p));
		if ((e -= 2 * (p2->tab[0][1] - p1->tab[0][1])) < 0)
		{
			if (++p.y > datas->nlines)
				return ;
			e += 2 * (p2->tab[0][0] - p1->tab[0][0]);
		}
		++p.x;
	}
}

inline void				ft_put_line_octant2(t_mlximg *datas,
							int (*fcolor)(const t_mlximg *datas,
							const t_matrix *, const t_matrix *, t_2dpt *),
							const t_matrix *p1, const t_matrix *p2)
{
	static int			e;
	static t_2dpt		p;
	int					comp;
	int					ymax;

	p.x = (int)p1->tab[0][0];
	p.y = (int)p1->tab[0][1];
	clipping(datas, p2, &p);
	comp = datas->lsize / datas->bpp * 8 - 1;
	if ((p.x < 0) || (p.x > comp))
		return ;
	e = p2->tab[0][1] - p1->tab[0][1];
	ymax = MIN(datas->nlines, (int)p2->tab[0][1]) + 1;
	while (p.y < ymax)
	{
		ft_put_pixel(datas, &p, fcolor(datas, p1, p2, &p));
		if ((e -= 2 * (p2->tab[0][0] - p1->tab[0][0])) < 0)
		{
			if (++p.x > comp)
				return ;
			e += 2 * (p2->tab[0][1] - p1->tab[0][1]);
		}
		++p.y;
	}
}

inline void				ft_put_line_octant3(t_mlximg *datas,
							int (*fcolor)(const t_mlximg *datas,
							const t_matrix *, const t_matrix *, t_2dpt *),
							const t_matrix *p1, const t_matrix *p2)
{
	static int			e;
	static t_2dpt		p;
	int					xmax;

	p.x = (int)p1->tab[0][0];
	p.y = (int)p1->tab[0][1];
	clipping(datas, p2, &p);
	if ((p.x < 0) || (p.y < 1) || (p.y > datas->nlines))
		return ;
	e = p2->tab[0][0] - p1->tab[0][0];
	xmax = MIN(datas->lsize / datas->bpp * 8, (int)p2->tab[0][0] + 1);
	while (p.x < xmax)
	{
		ft_put_pixel(datas, &p, fcolor(datas, p1, p2, &p));
		if ((e += 2 * (p2->tab[0][1] - p1->tab[0][1])) < 0)
		{
			if (--p.y < 0)
				return ;
			e += 2 * (p2->tab[0][0] - p1->tab[0][0]);
		}
		++p.x;
	}
}

inline void				ft_put_line_octant4(t_mlximg *datas,
							int (*fcolor)(const t_mlximg *datas,
							const t_matrix *, const t_matrix *, t_2dpt *),
							const t_matrix *p1, const t_matrix *p2)
{
	static int			e;
	static t_2dpt		p;
	int					comp;
	int					ymin;

	p.x = (int)p1->tab[0][0];
	p.y = (int)p1->tab[0][1];
	clipping(datas, p2, &p);
	comp = datas->lsize / datas->bpp * 8 - 1;
	if ((p.y < 1) || (p.x < 0) || (p.x > comp))
		return ;
	e = p2->tab[0][1] - p1->tab[0][1];
	ymin = MAX(0, (int)p2->tab[0][1]) - 1;
	while (p.y > ymin)
	{
		ft_put_pixel(datas, &p, fcolor(datas, p1, p2, &p));
		if ((e += 2 * (p2->tab[0][0] - p1->tab[0][0])) > 0)
		{
			if (++p.x > comp)
				return ;
			e += 2 * (p2->tab[0][1] - p1->tab[0][1]);
		}
		--p.y;
	}
}
