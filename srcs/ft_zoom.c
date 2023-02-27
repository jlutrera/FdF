/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zoom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutrera- <jutrera-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:32:50 by jutrera-          #+#    #+#             */
/*   Updated: 2023/02/23 17:32:50 by jutrera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	ft_error(float e, t_vars vars)
{
	int	er;
	int	x;
	int	y;

	x = -1;
	er = 0;
	while (++x < vars.rect.height && !er)
	{
		y = -1;
		while (++y < vars.rect.width && !er)
		{
			er += (vars.rect.iso[x][y].y * e > MAX_Y)
				+ (vars.rect.iso[x][y].y * e < 0);
			er += (vars.rect.iso[x][y].x * e > MAX_X)
				+ (vars.rect.iso[x][y].x * e < 0);
		}
	}
	return (er);
}

void	homotecia(float e, t_vars *vars)
{
	int	x;
	int	y;

	if (!ft_error(e, *vars))
	{
		x = -1;
		while (++x < (*vars).rect.height)
		{
			y = -1;
			while (++y < (*vars).rect.width)
			{	
				(*vars).rect.iso[x][y].x *= e;
				(*vars).rect.iso[x][y].y *= e;
			}
		}
	}
}

void	ft_zoom(float e, t_vars *vars)
{
	if (!ft_error(e, *vars))
	{
		mlx_destroy_image((*vars).mlx, (*vars).data.img);
		(*vars).data.img = mlx_new_image((*vars).mlx, MAX_X, MAX_Y);
		(*vars).data.addr = mlx_get_data_addr((*vars).data.img, \
				&(*vars).data.bpp, &(*vars).data.line_len, \
				&(*vars).data.endian);
		ft_freematrix((void **)(*vars).rect.iso, (*vars).rect.height);
		(*vars).rect.size *= e;
		(*vars).rect.iso = ft_iso((*vars).rect, (*vars).rect.map, \
				(*vars).rect.level_z);
		draw_lines(vars);
		mlx_clear_window((*vars).mlx, (*vars).win);
		ft_translate((*vars).rect.size / e, (*vars).rect.size / e, vars);
		put_menu(*vars);
	}
}
