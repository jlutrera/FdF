/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iso.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutrera- <jutrera-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 09:44:00 by jutrera-          #+#    #+#             */
/*   Updated: 2023/02/09 09:44:00 by jutrera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	get_limits(t_pointf *lx, t_pointf *ly, t_pointf value)
{
	if (value.x < (*lx).x)
		(*lx).x = value.x;
	else if (value.x > (*lx).y)
		(*lx).y = value.x;
	if (value.y < (*ly).x)
		(*ly).x = value.y;
	else if (value.y > (*ly).y)
		(*ly).y = value.y;
}

int	ft_adjust_coord(t_pointf **m, t_pointf lx, t_pointf ly, t_rect r)
{
	int		x;
	int		y;
	float	max_x;
	float	max_y;

	x = 0;
	while (x < r.height)
	{
		y = 0;
		while (y < r.width)
		{
			m[x][y].x -= lx.x;
			m[x][y].y -= ly.x;
			y++;
		}
		x++;
	}
	max_x = (MAX_X - 400) / (lx.y - lx.x);
	max_y = (MAX_Y - 50) / (ly.y - ly.x);
	if (max_x > max_y)
		return (max_y);
	return (max_x);
}

t_pointf	**get_matrixes(t_rect rect, t_pointf *limits_x,
		t_pointf *limits_y, int **m2)
{
	int			x;
	int			y;
	t_pointf	**m;

	m = (t_pointf **)malloc(rect.height * sizeof(t_pointf *));
	x = 0;
	while (x < rect.height)
	{
		m[x] = (t_pointf *)malloc(rect.width * sizeof(t_pointf));
		if (!m[x])
		{
			ft_freematrix((void **)m, rect.height);
			return (0);
		}
		y = 0;
		while (y < rect.width)
		{
			m[x][y].x = (y - x) * cos(0.523599);
			m[x][y].y = (x + y) * sin(0.523599) - m2[x][y] / 2;
			get_limits(limits_x, limits_y, m[x][y]);
			y++;
		}
		x++;
	}
	return (m);
}

t_point	**ft_iso(t_rect rect, int **matrix)
{
	t_point		**matrix_iso;
	t_pointf	**m;
	t_pointf	limits_x;
	t_pointf	limits_y;

	limits_x.x = FLT_MAX;
	limits_y.x = FLT_MAX;
	limits_x.y = FLT_MIN;
	limits_y.y = FLT_MIN;
	m = get_matrixes(rect, &limits_x, &limits_y, matrix);
	if (!m)
		return (0);
	rect.escale = ft_adjust_coord(m, limits_x, limits_y, rect);
	matrix_iso = create_iso(m, rect, matrix);
	if (!matrix_iso)
		return (0);
	ft_freematrix((void **)m, rect.height);
	return (matrix_iso);
}
