/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iso_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutrera- <jutrera-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 09:44:00 by jutrera-          #+#    #+#             */
/*   Updated: 2023/03/03 10:50:26 by jutrera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf_bonus.h"

static void	get_limits(float (*limits)[], t_pointf value)
{
	if (value.x < (*limits)[0])
		(*limits)[0] = value.x;
	else if (value.x > (*limits)[1])
		(*limits)[1] = value.x;
	if (value.y < (*limits)[2])
		(*limits)[2] = value.y;
	else if (value.y > (*limits)[3])
		(*limits)[3] = value.y;
}

static float	upper(int t, float l, int v)
{
	if (t == 0)
		return (0);
	return (l * v / (0.5 * t));
}

float	ft_adjust_coord(t_pointf **m, float limits[], t_rect r)
{
	int		x;
	int		y;
	float	max_x;
	float	max_y;

	x = -1;
	while (++x < r.height)
	{
		y = -1;
		while (++y < r.width)
		{
			m[x][y].x -= limits[0];
			m[x][y].y -= limits[2];
		}
	}
	max_x = (MAX_X - 450) / (limits[1] - limits[0]);
	max_y = (MAX_Y - 50) / (limits[3] - limits[2]);
	if (max_x > max_y)
		return (max_y);
	return (max_x);
}

t_pointf	**get_matrixes(t_rect rect, float (*limits)[], \
		t_map **m2, float level)
{
	int			x;
	int			y;
	t_pointf	**m;

	m = (t_pointf **)malloc(rect.height * sizeof(t_pointf *));
	x = -1;
	while (++x < rect.height)
	{
		m[x] = (t_pointf *)malloc(rect.width * sizeof(t_pointf));
		if (!m[x])
		{
			ft_free((void **)m, rect.height);
			return (NULL);
		}
		y = -1;
		while (++y < rect.width)
		{
			m[x][y].x = (y - x) * cos(0.523599);
			m[x][y].y = (x + y) * sin(0.523599) - \
				upper(rect.top, level, m2[x][y].value);
			get_limits(limits, m[x][y]);
		}
	}
	return (m);
}

t_point	**ft_iso(t_rect rect, t_map **matrix, float level)
{
	t_point		**matrix_iso;
	t_pointf	**m;
	float		limits[4];

	limits[0] = FLT_MAX;
	limits[2] = FLT_MAX;
	limits[1] = FLT_MIN;
	limits[3] = FLT_MIN;
	m = get_matrixes(rect, &limits, matrix, level);
	if (!m)
		return (NULL);
	rect.escale = ft_adjust_coord(m, limits, rect);
	matrix_iso = create_iso(m, rect, matrix);
	if (!matrix_iso)
		return (NULL);
	ft_free((void **)m, rect.height);
	return (matrix_iso);
}
