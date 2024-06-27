/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:51:07 by mamichal          #+#    #+#             */
/*   Updated: 2024/06/26 12:00:44 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

// INCLUDES
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>
// TODO: DLEATE LATER AFTER ADDING PRINTF TO LIBFT
//# include "../libft/includes/ft_printf.h"
# include "../libft/libft.h"
# include "../mlx_linux/mlx.h"

# define ERROR_MSG "Posible program input:\n\
\t./fractol mandelbrot\n\
\t./fractol julia <val_1> <val_2>\n"

# define WIDTH 800
# define HEIGHT 800

# ifndef ITERATIONS
#  define ITERATIONS 50
# endif

// NOTE: COLORS (stolen from chatgpt)
# define BLACK       0x000000  // RGB(0, 0, 0)
# define WHITE       0xFFFFFF  // RGB(255, 255, 255)
# define RED         0xFF0000  // RGB(255, 0, 0)
# define GREEN       0x00FF00  // RGB(0, 255, 0)
# define BLUE        0x0000FF  // RGB(0, 0, 255)

// Psychedelic colors
# define MAGENTA_BURST   0xFF00FF
# define LIME_SHOCK      0xCCFF00
# define NEON_ORANGE     0xFF6600
# define PSYCHEDELIC_PURPLE 0x660066
# define AQUA_DREAM      0x33CCCC
# define HOT_PINK        0xFF66B2
# define ELECTRIC_BLUE   0x0066FF
# define LAVA_RED        0xFF3300

typedef enum e_errors
{
	OK = 0,
	MALLOC_ERROR = 1,
	INVALID_ARGUMENTS = 2
}				t_errors;

typedef struct s_img_data
{
	void	*p_img;
	char	*p_addr;
	int		bpp;
	int		line_len;
	int		endian;
}				t_img_data;

typedef struct s_complex
{
	double	real;
	double	imaginary;
}				t_complex;

typedef struct s_mlx_data
{
	void		*p_mlx_conn;
	void		*p_mlx_win;

}				t_mlx_data;

typedef struct s_events
{
	double	shift_horizontal;
	double	shift_vertical;
	double	zoom;
}				t_events;

typedef struct s_fractal_utils
{
	double	escape_value;
	int		iterations_number;
}				t_fractal_utils;

typedef struct s_fractal
{
	char			*p_name;
	t_fractal_utils	utils;
	double			julia_x;
	double			julia_y;
}				t_fractal;

typedef struct s_fractol_data
{
	t_mlx_data	mlx;
	t_img_data	img;
	t_fractal	fractal;
	t_complex	complex_nb;
	t_events	events;
}				t_fractol_data;

// src/math_utils.c
double		map(double unscaled, double new_min, \
				double new_max, double old_max);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);
int			parse_rgb(int red, int green, int blue);
int	count_gradient(int i, t_fractol_data *data);

// src/ft_atod.c
double		ft_atod(char *s);

// src/my_put_pixel.c
void		my_pixel_put(t_img_data *img, int x, int y, int color);

// src/fractol_data_init.c
void		fractol_data_init(t_fractol_data *data);

// src/fractal_render.c
void		fractal_render(t_fractol_data *data);

// src/handle_events.c
int			handle_close(t_fractol_data *data);
int			handle_key(int keysym, t_fractol_data *data);
int			handle_mouse(int button, int horizontal, int vertical, \
				t_fractol_data *data);

#endif
