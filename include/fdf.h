/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutrera- <jutrera-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 23:55:28 by jutrera-          #+#    #+#             */
/*   Updated: 2023/02/13 23:55:28 by jutrera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/include/libft.h"
# include "../mlx_linux/mlx.h"
# include <X11/Xlib.h>
# include <math.h>
# include <limits.h>
# include <float.h>

# define P_RED   0xFF0000
# define P_GREEN 0x00FF00
# define P_BLUE  0x0000FF
# define P_WHITE 0xFFFFFF
# define P_YELLOW 0xFFFF00

# define K_ESC   0xFF1B
# define K_UP    0xFF52
# define K_DOWN  0xFF54
# define K_LEFT  0xFF51
# define K_RIGHT 0xFF53

# define MAX_X   1600
# define MAX_Y   900

typedef struct s_pointf
{
	float	x;
	float	y;
}	t_pointf;

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
}	t_point;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_data;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	t_data	data;
}	t_vars;

typedef struct s_rect
{
	int		width;
	int		height;
	int		escale;
	int		top;
}	t_rect;

t_point	**ft_iso(t_rect rect, int **matrix);
void	my_hooks(t_vars vars);
void	process_img(char *name, int height, int width, t_point **matrix);
void	put_menu(t_vars vars);
void	draw_lines(t_vars vars, t_point **matrix, int h, int w);
int		**load_map(char *file, t_rect *r);
void	put_image(t_vars *vars, t_point **matrix, int h, int w);
void	ft_translate(int x, int y, t_vars *vars);
void	ft_freematrix(void **m, int w);
t_point	**create_iso(t_pointf **m, t_rect r, int **m2);
#endif