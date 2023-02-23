/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutrera- <jutrera-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 22:42:53 by jutrera-          #+#    #+#             */
/*   Updated: 2023/02/13 22:42:53 by jutrera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	get_w(char *line, int *width)
{
	char	**numbers;
	int		w;

	numbers = ft_split(line, ' ');
	if (!numbers)
		return (0);
	w = -1;
	while (numbers[++w])
	{
		if (atoi(numbers[w]) == 0 && numbers[w][0] != '0')
		{
			while (numbers[w])
				free(numbers[w++]);
			free(numbers);
			ft_printf("Map error !!!\n");
			return (0);
		}
		free(numbers[w]);
	}	
	free(numbers);
	if (*width < w)
		*width = w;
	return (1);
}

int	get_dimensions(char *file, t_rect *rect)
{
	char	*line;
	int		fd;

	fd = open(file, O_RDONLY);
	if (!fd)
		return (0);
	line = get_next_line(fd);
	while (line)
	{
		if (!get_w(line, &(*rect).width))
		{
			free(line);
			return (0);
		}
		(*rect).height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (1);
}

int	main(int argc, char **argv)
{
	t_rect	rect;
	int		**matrix;
	t_point	**matrix_iso;

	if (argc != 2)
		return (-1);
	rect.height = 0;
	rect.width = 0;
	if (!get_dimensions(argv[1], &rect))
		return (0);
	matrix = load_map(argv[1], &rect);
	if (!matrix)
		return (0);
	matrix_iso = ft_iso(rect, matrix, 3);
	if (!matrix_iso)
	{
		ft_freematrix((void **)matrix, rect.height);
		return (0);
	}
	process_img(argv[1], rect, matrix_iso, matrix);
	ft_freematrix((void **)matrix, rect.height);
	ft_freematrix((void **)matrix_iso, rect.height);
	return (0);
}
