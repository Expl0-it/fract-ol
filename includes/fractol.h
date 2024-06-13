/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:51:07 by mamichal          #+#    #+#             */
/*   Updated: 2024/06/12 20:25:53 by mamichal         ###   ########.fr       */
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
// TODO: DLEATE LATER AFTER ADDING PRINTF TO LIBFT
//# include "../libft/includes/ft_printf.h"
# include "../libft/libft.h"
# include "../mlx_linux/mlx.h"

# define ERROR_MSG "Posible program input:\n\
\t./fractol mandelbrot\n\
\t./fractol julia <val_1> <val_2>\n"

# define WIDTH 500
# define HEIGHT 500

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
	t_img_data	img_data;

}				t_mlx_data;

typedef struct s_fractal
{
	char	*p_name;
}				t_fractal;

typedef struct s_fractol_data
{
	t_mlx_data	mlx;
	t_img_data	img;
	t_fractal	fractal;
	t_complex	complex_nb;
}				t_fractol_data;

// src/my_put_pixel.c
void	my_pixel_put(t_img_data *img, int x, int y, int color);

#endif
