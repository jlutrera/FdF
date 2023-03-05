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
# include <math.h>
# include <limits.h>
# include <float.h>
//Windows
// # include "../mlx_linux/mlx.h"
// # include <X11/Xlib.h>
//Mac
# include <mlx.h>

// COLORS
# define P_RED   	0xFF0000
# define P_GREEN 	0x00FF00
# define P_BLUE  	0x0000FF
# define P_WHITE 	0xFFFFFF
# define P_YELLOW 	0xFFFF00
# define P_CYAN 	0x4BB5FF

//KEYCODE para Windows
//# define K_ESC   	0xFF1B

//KeyCodes for Mac
# define K_ESC   	53

//Window Size for the image
# define MAX_X   	1920
# define MAX_Y   	1000

//STRUCTS
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

typedef struct s_rect
{
	int		width;
	int		height;
	float	escale;
	int		top;
	t_point	**iso;
}	t_rect;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	t_data	data;
	t_rect	rect;
}	t_vars;

//PROTOTYPES
t_point		**create_iso(t_pointf **m, t_rect r, t_map **m2);
void		draw_lines(t_vars *vars);
t_point		**ft_iso(t_rect rect, t_map **matrix, float level);
t_map		**load_map(char *file, t_rect *r);
void		my_hooks(t_vars *vars);
void		process_img(char *name, t_rect r, t_point **matrix);
//		ft_utils.c
void		ft_free(void **v, int n);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
int			read_number(char *s);
int			read_color(char *s);
int			ft_hextoi(char *s);
#endif