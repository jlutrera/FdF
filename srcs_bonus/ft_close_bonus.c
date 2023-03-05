/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutrera- <jutrera-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:32:13 by jutrera-          #+#    #+#             */
/*   Updated: 2023/03/03 10:39:32 by jutrera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf_bonus.h"

int	ft_close(t_vars *vars)
{
	ft_free((void **)(*vars).rect.map, (*vars).rect.height);
	ft_free((void **)(*vars).rect.iso, (*vars).rect.height);
	mlx_destroy_image((*vars).mlx, (*vars).data.img);
	mlx_destroy_image((*vars).mlx, (*vars).menu.img);
	mlx_destroy_window((*vars).mlx, (*vars).win);
	(*vars).win = NULL;
	exit (0);
}
