/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_menu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutrera- <jutrera-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 00:07:57 by jutrera-          #+#    #+#             */
/*   Updated: 2023/02/14 00:07:57 by jutrera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	fill_color(t_vars vars, int color)
{
	int	x;
	int	y;

	x = 0;
	while (x < 200)
	{
		y = 0;
		while (y < 200)
		{
			mlx_pixel_put(vars.mlx, vars.win, MAX_X - x, y, color);
			y++;
		}
		x++;
	}
}

void	write_strings(t_vars vars)
{
	int	x;

	x = MAX_X - 160;
	mlx_string_put(vars.mlx, vars.win, x - 20, 20, P_GREEN, "KEY OPTIONS");
	mlx_string_put(vars.mlx, vars.win, x, 40, P_YELLOW, "UP    : Scroll UP");
	mlx_string_put(vars.mlx, vars.win, x, 60, P_YELLOW, "DOWN  : Scroll DOWN");
	mlx_string_put(vars.mlx, vars.win, x, 80,
		P_YELLOW, "LEFT  : Scroll LEFT");
	mlx_string_put(vars.mlx, vars.win, x, 100,
		P_YELLOW, "RIGHT : Scroll RIGHT");
	mlx_string_put(vars.mlx, vars.win, x, 120,
		P_YELLOW, "  +   : ZOOM in");
	mlx_string_put(vars.mlx, vars.win, x, 140, P_YELLOW, "  -   : ZOOM  out");
	mlx_string_put(vars.mlx, vars.win, x, 160,
		P_YELLOW, "  A   : Down high");
	mlx_string_put(vars.mlx, vars.win, x, 180, P_YELLOW, "  D   : Up high");
}

void	put_menu(t_vars vars)
{
	fill_color(vars, P_GRAY);
	write_strings(vars);
}
