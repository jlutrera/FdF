/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutrera- <jutrera-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 22:47:04 by jutrera-          #+#    #+#             */
/*   Updated: 2023/02/27 22:47:04 by jutrera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_BONUS_H
# define FDF_BONUS_H

# include "../include/fdf.h"

void		put_menu(t_vars vars);
void		ft_zoom(float e, t_vars *vars);
void		ft_changez(float i, t_vars *vars);
void		ft_translate(int x, int y, t_vars *vars);
#endif