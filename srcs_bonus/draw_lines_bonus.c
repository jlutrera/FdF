/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_lines_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutrera- <jutrera-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 12:47:47 by jutrera-          #+#    #+#             */
/*   Updated: 2023/03/03 10:17:40 by jutrera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf_bonus.h"

static double	distance(t_point a, t_point b)
{
	return (sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y)));
}

static int	color_at_point(t_point a, t_point b, t_point p)
{
	double	dist;
	int		red;
	int		blue;
	int		green;

	dist = distance(a, p) / distance(a, b);
	red = ((b.z & P_RED) >> 16) * dist + ((p.z & P_RED) >> 16) * (1 - dist);
	green = ((b.z & P_GREEN) >> 8) * dist
		+ ((p.z & P_GREEN) >> 8) * (1 - dist);
	blue = (b.z & P_BLUE) * dist + (p.z & P_BLUE) * (1 - dist);
	return ((red << 16) | (green << 8) | blue);
}		

static void	bresenham(t_vars *vars, t_point p, t_point q)
{
	t_point	d;
	t_point	s;
	t_point	p_ini;
	int		err;
	int		e2;

	d.x = abs(q.x - p.x);
	d.y = abs(q.y - p.y);
	s.x = 1 * (p.x < q.x) - 1 * (p.x >= q.x);
	s.y = 1 * (p.y < q.y) - 1 * (p.y >= q.y);
	err = d.x - d.y;
	p_ini = p;
	while (1)
	{
		my_mlx_pixel_put(&(*vars).data, p.x, p.y, color_at_point(p_ini, q, p));
		if (p.x == q.x && p.y == q.y)
			break ;
		e2 = err * 2;
		err -= d.y * (e2 > -d.y);
		p.x += s.x * (e2 > -d.y);
		err += d.x * (e2 < d.x);
		p.y += s.y * (e2 < d.x);
	}
}

void	draw_lines(t_vars *vars)
{
	int	y;
	int	x;

	x = -1;
	while (++x < (*vars).rect.height)
	{
		y = -1;
		while (++y < (*vars).rect.width - 1)
		{
			bresenham(vars, (*vars).rect.iso[x][y], (*vars).rect.iso[x][y + 1]);
			if (x < (*vars).rect.height - 1)
				bresenham(vars, (*vars).rect.iso[x][y],
					(*vars).rect.iso[x + 1][y]);
		}
		if (x < (*vars).rect.height - 1)
			bresenham(vars, (*vars).rect.iso[x][y], (*vars).rect.iso[x + 1][y]);
	}
}
