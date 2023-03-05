/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_translate_bonu.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutrera- <jutrera-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:31:20 by jutrera-          #+#    #+#             */
/*   Updated: 2023/02/23 17:31:20 by jutrera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf_bonus.h"

void	ft_translate(int x, int y, t_vars *vars)
{
	static int	pos_x = 0;
	static int	pos_y = 0;

	pos_x += x;
	pos_y += y;
	mlx_clear_window((*vars).mlx, (*vars).win);
	mlx_put_image_to_window((*vars).mlx, (*vars).win,
		(*vars).data.img, pos_x, pos_y);
	mlx_put_image_to_window((*vars).mlx, (*vars).win, \
		(*vars).menu.img, 1520, 0);
}
