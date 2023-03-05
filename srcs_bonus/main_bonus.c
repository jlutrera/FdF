/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutrera- <jutrera-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 22:42:53 by jutrera-          #+#    #+#             */
/*   Updated: 2023/03/03 11:12:08 by jutrera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf_bonus.h"

static int	ft_errormsg(int e)
{
	if (e == 0)
		ft_printf("Correct syntax: ./fdf (map_file)\n");
	else if (e == 1)
		ft_printf("Empty file !\n");
	else if (e == 2)
		ft_printf("Map error !\n");
	else if (e == 3)
		ft_printf("Open error !\n");
	return (0);
}

static int	get_w(char *line, int *width)
{
	char	**numbers;
	int		w;
	int		aux;

	numbers = ft_split(line, ' ');
	if (!numbers)
		return (0);
	w = 0;
	while (numbers[w] && numbers[w][0] != '\n')
	{
		aux = read_number(numbers[w]);
		if (aux == 0 && numbers[w][0] != '0')
		{
			ft_free((void **)numbers, 0);
			return (ft_errormsg(2));
		}
		++w;
	}	
	ft_free((void **)numbers, 0);
	if (*width < w)
		*width = w;
	return (1);
}

static int	get_dimensions(char *file, t_rect *rect)
{
	char	*line;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (ft_errormsg(3));
	line = get_next_line(fd);
	if (!line)
		return (ft_errormsg(1));
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
	t_map	**matrix;
	t_point	**matrix_iso;

	if (argc != 2)
		return (ft_errormsg(0));
	rect.height = 0;
	rect.width = 0;
	if (!get_dimensions(argv[1], &rect))
		return (0);
	matrix = load_map(argv[1], &rect);
	if (!matrix)
		return (0);
	rect.size = 1;
	matrix_iso = ft_iso(rect, matrix, 1);
	if (!matrix_iso)
	{
		ft_free((void **)matrix, rect.height);
		return (0);
	}
	process_img(argv[1], rect, matrix_iso, matrix);
	return (1);
}
