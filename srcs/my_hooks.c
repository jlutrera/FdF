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

int	m_close(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	vars->win = NULL;
	exit (0);
}

int	k_event(int keycode, t_vars *vars)
{
	if (keycode == K_ESC)
		m_close(vars);
	if (keycode == K_RIGHT)
		ft_translate(10, 0, vars);
	if (keycode == K_LEFT)
		ft_translate(-10, 0, vars);
	if (keycode == K_DOWN)
		ft_translate(0, 10, vars);
	if (keycode == K_UP)
		ft_translate(0, -10, vars);
	return (0);
}

void	my_hooks(t_vars vars)
{
	mlx_hook(vars.win, 17, 1L << 17, &m_close, &vars);
	mlx_hook(vars.win, 2, 1L << 0, &k_event, &vars);
	mlx_loop(vars.mlx);
	mlx_destroy_image(vars.mlx, vars.data.img);
}
