/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutrera- <jutrera-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 12:53:03 by jutrera-          #+#    #+#             */
/*   Updated: 2023/03/03 11:11:26 by jutrera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf_bonus.h"

static void	remap(t_map **matrix, t_rect r, int f)
{
	int	x;
	int	y;

	x = -1;
	while (++x < r.height)
	{
		y = -1;
		while (++y < r.width)
			matrix[x][y].value -= f;
	}
}

static void	fix_floor_and_top(int *floor, t_rect *r, int v)
{
	if (*floor > v)
		*floor = v;
	if ((*r).top < v)
		(*r).top = v;
}

static t_map	*load_maprows(char *line, t_rect *r, int *floor)
{
	t_map	*m;
	int		y;
	char	**numbers;

	numbers = ft_split(line, ' ');
	if (!numbers)
		return (NULL);
	m = (t_map *)ft_calloc(sizeof(t_map), (*r).width);
	if (!m)
	{
		ft_free((void **)numbers, 0);
		return (NULL);
	}
	y = 0;
	while (numbers[y] && y < (*r).width)
	{
		m[y].value = read_number(numbers[y]);
		m[y].color = read_color(numbers[y]);
		fix_floor_and_top(floor, r, m[y].value);
		y++;
	}
	ft_free((void **)numbers, 0);
	return (m);
}

static t_map	**get_matrix(int fd, int *f, t_rect *r)
{
	t_map	**m;
	int		x;
	char	*line;

	m = (t_map **)ft_calloc(sizeof(t_map *), (*r).height);
	if (!m)
		return (NULL);
	x = 0;
	line = get_next_line(fd);
	while (line)
	{
		m[x] = load_maprows(line, r, f);
		if (!m[x])
		{
			ft_free((void **)m, (*r).height);
			free(line);
			return (NULL);
		}
		++x;
		free(line);
		line = get_next_line(fd);
	}
	return (m);
}

t_map	**load_map(char *file, t_rect *r)
{
	t_map	**matrix;
	int		fd;
	int		floor;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	floor = INT_MAX;
	(*r).top = INT_MIN;
	matrix = get_matrix(fd, &floor, r);
	if (!matrix)
		return (NULL);
	close(fd);
	remap(matrix, *r, floor);
	(*r).top -= floor;
	return (matrix);
}
