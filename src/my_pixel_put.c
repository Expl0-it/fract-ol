/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_pixel_put.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:02:47 by mamichal          #+#    #+#             */
/*   Updated: 2024/06/15 23:25:46 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	my_pixel_put(t_img_data *img, int x, int y, int color)
{
	char	*dst;
	int		offset;

	offset = ((y * img->line_len) + (x * (img->bpp / 8)));
	dst = img->p_addr + offset;
	*(unsigned int *)dst = color;
}

/*
void	my_pixel_put(t_img_data *img, int x, int y, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->p_addr + offset) = color;
}
*/
