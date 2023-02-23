/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutrera- <jutrera-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 09:52:42 by jutrera-          #+#    #+#             */
/*   Updated: 2023/02/09 09:52:42 by jutrera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	k_event(int keycode, t_vars *vars)
{
	if (keycode == K_ESC)
		ft_close(vars);
	if (keycode == K_RIGHT)
		ft_translate(10, 0, vars);
	if (keycode == K_LEFT)
		ft_translate(-10, 0, vars);
	if (keycode == K_DOWN)
		ft_translate(0, 10, vars);
	if (keycode == K_UP)
		ft_translate(0, -10, vars);
	if (keycode == K_ADD)
		ft_zoom(1.5, vars);
	if (keycode == K_MINUS)
		ft_zoom(0.5, vars);
	if (keycode == K_A)
		ft_changez(-0.2, vars);
	if (keycode == K_D)
		ft_changez(0.2, vars);
	return (0);
}

int	mouse_press(int button, int x, int y, t_vars *vars)
{
	(void)x;
	(void)y;
	if (button == 1)
		(*vars).mouse.is_pressed = 1;
	if (button == 4)
		ft_zoom(1.5, vars);
	if (button == 5)
		ft_zoom(0.5, vars);
	return (0);
}

int	mouse_release(int button, int x, int y, t_vars *vars)
{
	(void)x;
	(void)y;
	if (button == 1)
		(*vars).mouse.is_pressed = 0;
	if (button == 4)
		ft_zoom(0.5, vars);
	if (button == 5)
		ft_zoom(1.5, vars);
	return (0);
}

int	mouse_move(int x, int y, t_vars *vars)
{
	int	delta_x;
	int	delta_y;

	(*vars).mouse.prev_x = (*vars).mouse.x;
	(*vars).mouse.prev_y = (*vars).mouse.y;
	(*vars).mouse.x = x;
	(*vars).mouse.y = y;
	if ((*vars).mouse.is_pressed)
	{
		delta_x = (*vars).mouse.x - (*vars).mouse.prev_x;
		delta_y = (*vars).mouse.y - (*vars).mouse.prev_y;
		ft_translate(delta_x, delta_y, vars);
	}
	return (0);
}

void	my_hooks(t_vars *vars)
{
	mlx_hook((*vars).win, 17, 1L << 17, &ft_close, vars);
	mlx_hook((*vars).win, 2, 1L << 0, &k_event, vars);
	mlx_hook((*vars).win, 4, 1L << 2, &mouse_press, vars);
	mlx_hook((*vars).win, 5, 1L << 3, &mouse_release, vars);
	mlx_hook((*vars).win, 6, 1L << 6, &mouse_move, vars);
}
