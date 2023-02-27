/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutrera- <jutrera-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 00:47:27 by jutrera-          #+#    #+#             */
/*   Updated: 2023/02/25 00:47:27 by jutrera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	ft_hextoi(char *s)
{
	int	i;
	int	j;
	int	r;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] >= 'A' && s[i] <= 'F')
			r = 7;
		else if (s[i] >= 'a' && s[i] <= 'f')
			r = 39;
		else
			r = 0;
		j = j * 16 + (s[i] - 48 - r);
		i++ ;
	}
	return (j);
}

int	read_number(char *s)
{
	char	*n;
	int		i;
	int		j;
	int		number;

	i = 0;
	while (s[i] && s[i] != ',')
		i++;
	if (s[i] == 0)
		return (ft_atoi(s));
	n = (char *)malloc((i + 1) * sizeof(char));
	if (!n)
		return (0);
	j = -1;
	while (++j < i)
		n[j] = s[j];
	n[j] = 0;
	number = ft_atoi(n);
	free(n);
	return (number);
}

int	read_color(char *s)
{
	char	*n;
	int		i;
	int		j;
	int		color;

	i = 0;
	while (s[i] && s[i] != ',' && s[i] != '\n')
		i++;
	if (!s[i] || s[i] == '\n')
		return (0);
	n = (char *)ft_calloc(sizeof(char), 7);
	if (!n)
		return (0);
	j = i + 3;
	i = 0;
	while (s[j] && i < 6)
		n[i++] = s[j++];
	color = ft_hextoi(n);
	free(n);
	return (color);
}
