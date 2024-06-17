/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 19:56:16 by mamichal          #+#    #+#             */
/*   Updated: 2024/06/17 11:29:12 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

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

	z.real = 0.0;
	z.imaginary = 0.0;
	c.real =(map(horizontal, -2.0, +2.0, WIDTH) * data->events.zoom) + data->events.shift_horizontal; 
	c.imaginary = (map(vertical, +2.0, -2.0, HEIGHT) * data->events.zoom) + data->events.shift_vertical;
	i = 0;
	while (i < data->fractal.utils.iterations_number)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.real * z.real) + (z.imaginary * z.imaginary) > \
			data->fractal.utils.escape_value)
		{
			color = map(i, BLACK, WHITE, data->fractal.utils.iterations_number);
			my_pixel_put(&data->img, horizontal, vertical, color);
//			mlx_pixel_put(data->mlx.p_mlx_conn, data->mlx.p_mlx_win, horizontal, vertical, color);
			return ;
		}
		i++;
	}
	my_pixel_put(&data->img, horizontal, vertical, LIME_SHOCK);
//	mlx_pixel_put(data->mlx.p_mlx_conn, data->mlx.p_mlx_win, horizontal, vertical, LIME_SHOCK);
}

void	fractal_render(t_fractol_data *data)
{
	int	horizontal;
	int	vertical;

	vertical = 0;
	while (vertical++ < HEIGHT)
	{
		horizontal = 0;
		while (horizontal++ < WIDTH)
		{
			is_in_fractal_set(horizontal, vertical, data);
		}
	}
	mlx_put_image_to_window(data->mlx.p_mlx_conn, data->mlx.p_mlx_win, \
						data->img.p_img, 0, 0);
}
