/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_data_init.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 10:43:48 by mamichal          #+#    #+#             */
/*   Updated: 2024/06/16 22:25:27 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	init_mlx_data(t_fractol_data *data)
{
	data->mlx.p_mlx_conn = mlx_init();
	if (NULL == data->mlx.p_mlx_conn)
		exit(MALLOC_ERROR);
	data->mlx.p_mlx_win = mlx_new_window(data->mlx.p_mlx_conn, \
							WIDTH, HEIGHT, data->fractal.p_name);
	if (NULL == data->mlx.p_mlx_win)
	{
		mlx_destroy_display(data->mlx.p_mlx_conn);
		free(data->mlx.p_mlx_conn);
		exit(MALLOC_ERROR);
	}
	data->img.p_img = mlx_new_image(data->mlx.p_mlx_conn, WIDTH, HEIGHT);
	if (NULL == data->img.p_img)
	{
		mlx_destroy_window(data->mlx.p_mlx_conn, data->mlx.p_mlx_win);
		mlx_destroy_display(data->mlx.p_mlx_conn);
		free(data->mlx.p_mlx_conn);
		exit(MALLOC_ERROR);
	}
	data->img.p_addr = mlx_get_data_addr(data->img.p_img, &data->img.bpp, \
						&data->img.line_len, &data->img.endian);
}

static void	init_events(t_fractol_data *data)
{
	mlx_hook(data->mlx.p_mlx_conn, KeyPress, KeyPressMask, handle_key, data);
	mlx_hook(data->mlx.p_mlx_conn, ButtonPress, ButtonPressMask, handle_mouse, data);
	mlx_hook(data->mlx.p_mlx_conn, DestroyNotify, StructureNotifyMask, handle_close, data);
}

static void	init_utils(t_fractol_data *data)
{
	data->fractal.utils.escape_value = 4;
	data->fractal.utils.iterations_number = ITERATIONS;
	data->events.shift_horizontal = 0.0;
	data->events.shift_vertical = 0.0;
	data->events.zoom = 1.0;
}

void	fractol_data_init(t_fractol_data *data)
{
	init_mlx_data(data);
	init_events(data);
	init_utils(data);
}
