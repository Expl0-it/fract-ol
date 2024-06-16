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

