/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 21:23:43 by mamichal          #+#    #+#             */
/*   Updated: 2024/06/25 16:37:36 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	handle_close(t_fractol_data *data)
{
	mlx_destroy_image(data->mlx.p_mlx_conn, data->img.p_img);
	mlx_destroy_window(data->mlx.p_mlx_conn, data->mlx.p_mlx_win);
	mlx_destroy_display(data->mlx.p_mlx_conn);
	free(data->mlx.p_mlx_conn);
	exit(OK);
}

int	handle_key(int keysym, t_fractol_data *data)
{
	if (keysym == XK_Escape)
		handle_close(data);
	else if (keysym == XK_Left)
		data->events.shift_horizontal -= (0.5 * data->events.zoom);
	else if (keysym == XK_Right)
		data->events.shift_horizontal += (0.5 * data->events.zoom);
	else if (keysym == XK_Down)
		data->events.shift_vertical -= (0.5 * data->events.zoom);
	else if (keysym == XK_Up)
		data->events.shift_vertical += (0.5 * data->events.zoom);
	else if (keysym == XK_plus)
		data->fractal.utils.iterations_number += 10;
	else if (keysym == XK_minus)
		data->fractal.utils.iterations_number -= 10;
	fractal_render(data);
	return (0);
}

int	handle_mouse(int button, int horizontal, int vertical, t_fractol_data *data)
{
	if (Button4 == button)
		data->events.zoom *= 0.95;
	else if (Button5 == button)
		data->events.zoom *= 1.05;
	fractal_render(data);
	return (0);
}
