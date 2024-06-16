/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 21:23:43 by mamichal          #+#    #+#             */
/*   Updated: 2024/06/16 22:12:09 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	handle_close(t_fractol_data *data)
{
	mlx_destroy_image(data->mlx.p_mlx_conn, data->mlx.img_data.p_img);
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
		data->events.shift_horizontal += 0.5;
	else if (keysym == XK_Right)
		data->events.shift_horizontal -= 0.5;
	else if (keysym == XK_Down)
		data->events.shift_vertical += 0.5;
	else if (keysym == XK_Up)
		data->events.shift_vertical -= 0.5;
	else if (keysym == XK_plus)
		data->fractal.utils.iterations_number += 10;
	else if (keysym == XK_minus)
		data->fractal.utils.iterations_number -= 10;
	fractal_render(data);
	return (0);
}