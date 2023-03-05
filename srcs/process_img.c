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

static void	ft_init(t_vars *vars, t_rect r, t_point **matrix)
{
	(*vars).rect.height = r.height;
	(*vars).rect.width = r.width;
	(*vars).data.img = mlx_new_image((*vars).mlx, MAX_X, MAX_Y);
	(*vars).data.addr = mlx_get_data_addr((*vars).data.img, &(*vars).data.bpp, \
			&(*vars).data.line_len, &(*vars).data.endian);
	(*vars).rect.iso = matrix;
}

void	process_img(char *name, t_rect r, t_point **matrix)
{
	t_vars	vars;
	char	*s;

	vars.mlx = mlx_init();
	s = ft_strjoin("FdF  ###  ", name);
	vars.win = mlx_new_window(vars.mlx, MAX_X, MAX_Y, s);
	free(s);
	ft_init(&vars, r, matrix);
	draw_lines(&vars);
	ft_free((void **)matrix, r.height);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.data.img, 0, 0);
	my_hooks(&vars);
	mlx_loop(vars.mlx);
}
