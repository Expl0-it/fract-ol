/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_pixel_put.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:02:47 by mamichal          #+#    #+#             */
/*   Updated: 2024/06/12 19:39:05 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	my_pixel_put(t_img_data *data, int x, int y, int color)
{
	char	*dst;
	int		offset;

	offset = ((y * data->line_length) + x * (data->bits_per_pixel / 8));
	dst = data->addr + offset;
	*(unsigned int*)dst = color;
}
