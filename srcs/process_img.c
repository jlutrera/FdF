/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutrera- <jutrera-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 09:49:22 by jutrera-          #+#    #+#             */
/*   Updated: 2023/02/09 09:49:22 by jutrera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	put_image(t_vars *vars, t_point **matrix, int h, int w)
{
	(*vars).data.img = mlx_new_image((*vars).mlx, MAX_X, MAX_Y);
	(*vars).data.addr = mlx_get_data_addr((*vars).data.img, &(*vars).data.bpp,
			&(*vars).data.line_len, &(*vars).data.endian);
	draw_lines(*vars, matrix, h, w);
}

void	process_img(char *name, int height, int width, t_point **matrix)
{
	t_vars	vars;
	char	*s;

	vars.mlx = mlx_init();
	s = ft_strjoin("FdF  ###  ", name);
	vars.win = mlx_new_window(vars.mlx, MAX_X, MAX_Y, s);
	free(s);
	put_image(&vars, matrix, height, width);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.data.img, 0, 0);
	put_menu(vars);
	my_hooks(vars);
}
