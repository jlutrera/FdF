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
# define P_ORANGE 0xFFA701
# define P_MAGEN 0x8920FF
# define P_CYAN 0x4BB5FF
# define P_GRAY	0x333333

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

# define MAX_X   1920
# define MAX_Y   1000

typedef struct s_map
{
	int	value;
	int	color;
}	t_map;

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
	float	escale;
	int		top;
	float	level_z;
	float	size;
	t_map	**map;
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

t_point		**ft_iso(t_rect rect, t_map **matrix, float level);
void		my_hooks(t_vars *vars);
void		process_img(char *name, t_rect r, t_point **matrix, t_map **m);
void		draw_lines(t_vars *vars);
t_map		**load_map(char *file, t_rect *r);
void		ft_freematrix(void **m, int w);
void		ft_free(void **v);
t_point		**create_iso(t_pointf **m, t_rect r, t_map **m2);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
t_pointf	**get_matrixes(t_rect rect, float (*limits)[], \
		t_map **m2, float level);
float		ft_adjust_coord(t_pointf **m, float limits[], t_rect r);
int			ft_close(t_vars *vars);
int			read_number(char *s);
int			read_color(char *s);
int			ft_hextoi(char *s);
int			ft_errormsg(int e);
int			ft_error(float e, t_vars vars);
//Bonus part
void		put_menu(t_vars vars);
void		ft_zoom(float e, t_vars *vars);
void		ft_changez(float i, t_vars *vars);
void		ft_translate(int x, int y, t_vars *vars);
//void		ft_rotation(int axis, float angle, t_vars *vars);
#endif