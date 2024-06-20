/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 19:56:16 by mamichal          #+#    #+#             */
/*   Updated: 2024/06/20 13:58:21 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	mandelbrot_or_julia(t_complex *z, t_complex *c, t_fractol_data *data)
{
	if (!ft_strncmp(data->fractal.p_name, "julia", 5))
	{
		c->real = data->fractal.julia_x;
		c->imaginary = data->fractal.julia_y;
	}
	else
	{
		c->real = z->real;
		c->imaginary = z->imaginary;
	}
}

/*
 * NOTE: MANDELBROT SET
 * is in set when
 *			(doesn't go to)
 * z = z^2 + c  =/=> infinity
 * where:
 * z => position after calculations (initially (0, 0))
 * c => coordinates of the calculated point
 *
 * FIX: In case of problems with render speed (to slow or not working)
 * possible to change numer of loop iterations for the cost of
 * precision of rendered fractal
*/
static void	is_in_fractal_set(int horizontal, int vertical, t_fractol_data *data)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	z.real = (map(horizontal, -2.0, +2.0, WIDTH) * data->events.zoom) + data->events.shift_horizontal;
	z.imaginary = (map(vertical, +2.0, -2.0, HEIGHT) * data->events.zoom) + data->events.shift_vertical;
	mandelbrot_or_julia(&z, &c, data);
	i = 0;
	while (i < data->fractal.utils.iterations_number)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.real * z.real) + (z.imaginary * z.imaginary) > \
			data->fractal.utils.escape_value)
		{
			color = map(i, BLACK, WHITE, data->fractal.utils.iterations_number);
			my_pixel_put(&data->img, horizontal, vertical, color);
			return ;
		}
		i++;
	}
	my_pixel_put(&data->img, horizontal, vertical, LIME_SHOCK);
}

void	fractal_render(t_fractol_data *data)
{
	int	horizontal;
	int	vertical;

	vertical = 0;
	while (vertical < HEIGHT)
	{
		horizontal = 0;
		while (horizontal < WIDTH)
		{
			is_in_fractal_set(horizontal, vertical, data);
			horizontal++;
		}
		vertical++;
	}
	mlx_put_image_to_window(data->mlx.p_mlx_conn, data->mlx.p_mlx_win, \
						data->img.p_img, 0, 0);
}
