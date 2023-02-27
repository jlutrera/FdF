/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutrera- <jutrera-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:32:13 by jutrera-          #+#    #+#             */
/*   Updated: 2023/02/23 17:32:13 by jutrera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	ft_close(t_vars *vars)
{
	mlx_destroy_image((*vars).mlx, (*vars).data.img);
	mlx_destroy_window((*vars).mlx, (*vars).win);
	(*vars).win = NULL;
	exit (0);
}
