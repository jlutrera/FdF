/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_iso_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutrera- <jutrera-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 19:39:12 by jutrera-          #+#    #+#             */
/*   Updated: 2023/03/03 10:14:52 by jutrera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf_bonus.h"

static int	select_color(int t, t_map m)
{
	float	d;
	int		i;

	if (m.color != 0)
		return (m.color);
	d = t / 6;
	i = m.value;
	if (i <= 0.5 * d)
		return (P_BLUE);
	else if (i <= 2 * d)
		return (P_CYAN);
	else if (i <= 3.5 * d)
		return (P_GREEN);
	else if (i <= 5 * d)
		return (P_YELLOW);
	return (P_WHITE);
}

t_point	**create_iso(t_pointf **m, t_rect r, t_map **m2)
{
	int		x;
	int		y;
	t_point	**iso;

	iso = (t_point **)malloc(r.height * sizeof(t_point *));
	if (!iso)
		return (0);
	x = -1;
	while (++x < r.height)
	{
		iso[x] = (t_point *)malloc(r.width * sizeof(t_point));
		if (!iso[x])
		{
			ft_free((void **)iso, x);
			return (0);
		}
		y = -1;
		while (++y < r.width)
		{
			iso[x][y].x = (m[x][y].x * r.escale + 25) * r.size;
			iso[x][y].y = (m[x][y].y * r.escale + 25) * r.size;
			iso[x][y].z = select_color(r.top, m2[x][y]);
		}
	}
	return (iso);
}
