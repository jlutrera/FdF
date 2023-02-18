/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutrera- <jutrera-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 18:41:37 by jutrera-          #+#    #+#             */
/*   Updated: 2023/02/18 18:41:37 by jutrera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	ft_translate(int x, int y, t_vars *vars)
{
	static int	pos_x = 0;
	static int	pos_y = 0;

	pos_x += x;
	pos_y += y;
	mlx_put_image_to_window((*vars).mlx, (*vars).win,
		(*vars).data.img, pos_x, pos_y);
	put_menu(*vars);
}
