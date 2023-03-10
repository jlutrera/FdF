/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_changez_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutrera- <jutrera-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:30:13 by jutrera-          #+#    #+#             */
/*   Updated: 2023/02/23 17:30:13 by jutrera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf_bonus.h"

void	ft_changez(float i, t_vars *vars)
{
	mlx_destroy_image((*vars).mlx, (*vars).data.img);
	(*vars).data.img = mlx_new_image((*vars).mlx, MAX_X - 400, MAX_Y);
	(*vars).data.addr = mlx_get_data_addr((*vars).data.img, &(*vars).data.bpp, \
		&(*vars).data.line_len, &(*vars).data.endian);
	(*vars).rect.level_z += i;
	ft_free((void **)(*vars).rect.iso, (*vars).rect.height);
	(*vars).rect.iso = ft_iso((*vars).rect, (*vars).rect.map, \
			(*vars).rect.level_z);
	draw_lines(vars);
	ft_translate(0, 0, vars);
}
