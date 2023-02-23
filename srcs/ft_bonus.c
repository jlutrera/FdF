/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutrera- <jutrera-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 18:41:37 by jutrera-          #+#    #+#             */
/*   Updated: 2023/02/18 18:41:37 by jutrera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	ft_close(t_vars *vars)
{
	mlx_destroy_image((*vars).mlx, (*vars).data.img);
	mlx_destroy_window((*vars).mlx, (*vars).win);
	(*vars).win = NULL;
	exit (0);
}

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
			er = er + (vars.rect.iso[x][y].y * e > MAX_Y)
				+ (vars.rect.iso[x][y].y * e < 0);
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
	mlx_destroy_image((*vars).mlx, (*vars).data.img);
	(*vars).data.img = mlx_new_image((*vars).mlx, MAX_X, MAX_Y);
	(*vars).data.addr = mlx_get_data_addr((*vars).data.img, &(*vars).data.bpp,
			&(*vars).data.line_len, &(*vars).data.endian);
	homotecia(e, vars);
	draw_lines(vars);
	mlx_clear_window((*vars).mlx, (*vars).win);
	put_menu(*vars);
	ft_translate(0, 0, vars);
	put_menu(*vars);
}

void	ft_translate(int x, int y, t_vars *vars)
{
	static int	pos_x = 0;
	static int	pos_y = 0;

	pos_x += x;
	pos_y += y;
	mlx_put_image_to_window((*vars).mlx, (*vars).win,
		(*vars).data.img, pos_x, pos_y);
	put_menu(*vars);
}

void	ft_changez(float i, t_vars *vars)
{
	int	t;

	mlx_destroy_image((*vars).mlx, (*vars).data.img);
	(*vars).data.img = mlx_new_image((*vars).mlx, MAX_X, MAX_Y);
	(*vars).data.addr = mlx_get_data_addr((*vars).data.img, &(*vars).data.bpp, \
		&(*vars).data.line_len, &(*vars).data.endian);
	t = (*vars).rect.level_z + i;
	if (t > 0)
		(*vars).rect.level_z = t;
	ft_freematrix((void **)(*vars).rect.iso, (*vars).rect.height);
	(*vars).rect.iso = ft_iso((*vars).rect, (*vars).rect.map, \
			(*vars).rect.level_z);
	draw_lines(vars);
	mlx_clear_window((*vars).mlx, (*vars).win);
	put_menu(*vars);
	ft_translate(0, 0, vars);
	put_menu(*vars);
}
