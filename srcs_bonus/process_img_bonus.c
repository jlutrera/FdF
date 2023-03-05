/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_img_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutrera- <jutrera-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 09:49:22 by jutrera-          #+#    #+#             */
/*   Updated: 2023/03/03 11:22:39 by jutrera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf_bonus.h"

static void	ft_init(t_vars *vars, t_rect r, t_point **matrix, t_map **m)
{
	int		width;
	int		height;

	(*vars).menu.img = mlx_xpm_file_to_image((*vars).mlx, \
		"./images/menu.xpm", &width, &height);
	(*vars).menu.addr = mlx_get_data_addr((*vars).menu.img, \
		&(*vars).menu.bpp, &(*vars).menu.line_len, &(*vars).menu.endian);
	(*vars).mouse.x = 0;
	(*vars).mouse.y = 0;
	(*vars).mouse.is_pressedr = 0;
	(*vars).mouse.is_pressedl = 0;
	(*vars).rect.height = r.height;
	(*vars).rect.width = r.width;
	(*vars).rect.level_z = 1;
	(*vars).data.img = mlx_new_image((*vars).mlx, MAX_X - 400, MAX_Y);
	(*vars).data.addr = mlx_get_data_addr((*vars).data.img, \
		&(*vars).data.bpp, &(*vars).data.line_len, &(*vars).data.endian);
	(*vars).rect.iso = matrix;
	(*vars).rect.map = m;
	(*vars).rect.top = r.top;
	(*vars).rect.size = 1;
}

void	process_img(char *name, t_rect r, t_point **matrix, t_map **m)
{
	t_vars	vars;
	char	*s;

	vars.mlx = mlx_init();
	s = ft_strjoin("FdF  ###  ", name);
	vars.win = mlx_new_window(vars.mlx, MAX_X, MAX_Y, s);
	free(s);
	ft_init(&vars, r, matrix, m);
	draw_lines(&vars);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.data.img, 0, 0);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.menu.img, 1520, 0);
	my_hooks(&vars);
	mlx_loop(vars.mlx);
}
