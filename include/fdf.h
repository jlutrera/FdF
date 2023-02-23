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
//# include <mlx.h>
# include <math.h>
# include <limits.h>
# include <float.h>

# define P_RED   0xFF0000
# define P_GREEN 0x00FF00
# define P_BLUE  0x0000FF
# define P_WHITE 0xFFFFFF
# define P_YELLOW 0xFFFF00
# define P_ORANGE 0xFFA701
# define P_MAGEN 0x8920FF

//Para Windows
# define K_ESC   0xFF1B
# define K_UP    0xFF52
# define K_DOWN  0xFF54
# define K_LEFT  0xFF51
# define K_RIGHT 0xFF53
# define K_ADD 43
# define K_MINUS 45
# define K_A 97
# define K_D 100

//Para Mac
//# define K_ESC   53
//# define K_UP    126
//# define K_DOWN  125
//# define K_LEFT  123
//# define K_RIGHT 124
//# define K_ADD 30
//# define K_MINUS 44
//# define K_A 0
//# define K_D 2

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

typedef struct s_mouse
{
	int	is_pressed;
	int	x;
	int	y;
	int	prev_x;
	int	prev_y;
}	t_mouse;

typedef struct s_rect
{
	int		width;
	int		height;
	int		escale;
	int		top;
	float	level_z;
	int		**map;
	t_point	**iso;
}	t_rect;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	t_data	data;
	t_rect	rect;
	t_mouse	mouse;
}	t_vars;

t_point		**ft_iso(t_rect rect, int **matrix, float level);
void		my_hooks(t_vars *vars);
void		process_img(char *name, t_rect r, t_point **matrix, int **m);
void		put_menu(t_vars vars);
void		draw_lines(t_vars *vars);
int			**load_map(char *file, t_rect *r);
void		ft_translate(int x, int y, t_vars *vars);
void		ft_freematrix(void **m, int w);
t_point		**create_iso(t_pointf **m, t_rect r, int **m2);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
t_pointf	**get_matrixes(t_rect rect, t_pointf *limits_x,	\
		t_pointf *limits_y, int **m2, float level);
int			ft_adjust_coord(t_pointf **m, t_pointf lx, t_pointf ly, t_rect r);
void		ft_zoom(float e, t_vars *vars);
int			ft_close(t_vars *vars);
void		ft_changez(float i, t_vars *vars);
#endif