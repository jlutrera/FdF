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

void	put_menu(t_vars vars)
{
	mlx_string_put(vars.mlx, vars.win, 20, 20, P_GREEN, "KEY OPTIONS");
	mlx_string_put(vars.mlx, vars.win, 40, 40, P_WHITE, "UP    : Scroll UP");
	mlx_string_put(vars.mlx, vars.win, 40, 60, P_WHITE, "DOWN  : Scroll DOWN");
	mlx_string_put(vars.mlx, vars.win, 40, 80,
		P_WHITE, "LEFT  : Scroll LEFT");
	mlx_string_put(vars.mlx, vars.win, 40, 100,
		P_WHITE, "RIGHT : Scroll RIGHT");
	mlx_string_put(vars.mlx, vars.win, 40, 120,
		P_WHITE, "  +   : ZOOM in");
	mlx_string_put(vars.mlx, vars.win, 40, 140, P_WHITE, "  -   : ZOOM  out");
	mlx_string_put(vars.mlx, vars.win, 40, 160,
		P_WHITE, "  A   : ROTATE right");
	mlx_string_put(vars.mlx, vars.win, 40, 180, P_WHITE, "  S   : ROTATE left");
}
