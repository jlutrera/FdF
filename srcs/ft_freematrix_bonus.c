/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freematrix_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutrera- <jutrera-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 13:45:47 by jutrera-          #+#    #+#             */
/*   Updated: 2023/03/02 19:13:34 by jutrera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf_bonus.h"

void	ft_freematrix(void **m, int n)
{
	int	i;

	if (m)
	{
		if (*m)
		{
			i = 0;
			while (i < n)
				free(m[i++]);
		}
		free(m);
	}
}

void	ft_free(void **v)
{
	int	i;

	i = 0;
	while (v[i])
		free(v[i++]);
	free(v);
}
