/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutrera- <jutrera-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 12:53:03 by jutrera-          #+#    #+#             */
/*   Updated: 2023/02/14 12:53:03 by jutrera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	remap(int **matrix, t_rect r, int f)
{
	int	x;
	int	y;

	x = 0;
	while (x < r.height)
	{
		y = 0;
		while (y < r.width)
		{
			matrix[x][y] -= f;
			y++;
		}
		x++;
	}
}

int	*load_maprows(char *line, t_rect *r, int *floor)
{
	int		*m;
	int		y;
	char	**numbers;

	numbers = ft_split(line, ' ');
	if (!numbers)
		return (0);
	m = (int *)ft_calloc(sizeof(int), (*r).width);
	if (!m)
		return (0);
	y = -1;
	while (numbers[++y])
	{
		m[y] = ft_atoi(numbers[y]);
		if (*floor > m[y])
			*floor = m[y];
		if ((*r).top < m[y])
			(*r).top = m[y];
		free(numbers[y]);
	}
	free(numbers);
	return (m);
}

int	**get_matrix(int fd, int *f, t_rect *r)
{
	int		**m;
	int		x;
	char	*line;

	m = (int **)ft_calloc(sizeof(int *), (*r).height);
	if (!m)
		return (0);
	x = 0;
	line = get_next_line(fd);
	while (line)
	{
		m[x] = load_maprows(line, r, f);
		if (!m[x])
		{
			ft_freematrix((void **)m, (*r).height);
			free(line);
			return (0);
		}
		++x;
		free(line);
		line = get_next_line(fd);
	}
	return (m);
}

int	**load_map(char *file, t_rect *r)
{
	int		**matrix;
	int		fd;
	int		floor;

	fd = open(file, O_RDONLY);
	if (!fd)
		return (0);
	floor = INT_MAX;
	(*r).top = INT_MIN;
	matrix = get_matrix(fd, &floor, r);
	if (!matrix)
		return (0);
	close(fd);
	remap(matrix, *r, floor);
	(*r).top -= floor;
	return (matrix);
}
