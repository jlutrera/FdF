/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_iso.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutrera- <jutrera-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 19:39:12 by jutrera-          #+#    #+#             */
/*   Updated: 2023/02/18 19:39:12 by jutrera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	select_color(int t, int i)
{
	int	d;

	d = t / 5;
	if (i <= d)
		return (P_RED);
	else if (i <= 2 * d)
		return (P_BLUE);
	else if (i <= 3 * d)
		return (P_GREEN);
	else if (i <= 4 * d)
		return (P_YELLOW);
	else
		return (P_WHITE);
}

t_point	**create_iso(t_pointf **m, t_rect r, int **m2)
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
			ft_freematrix((void **)iso, r.height);
			return (0);
		}
		y = -1;
		while (++y < r.width)
		{
			iso[x][y].x = m[x][y].x * r.escale + 200;
			iso[x][y].y = m[x][y].y * r.escale + 25;
			iso[x][y].z = select_color(r.top, m2[x][y]);
		}
	}
	return (iso);
}
