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
	return (0);
}

void	my_hooks(t_vars *vars)
{
	mlx_hook((*vars).win, 17, 1L << 17, &ft_close, vars);
	mlx_hook((*vars).win, 2, 1L << 0, &k_event, vars);
}
