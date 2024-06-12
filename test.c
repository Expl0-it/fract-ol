/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:37:04 by mamichal          #+#    #+#             */
/*   Updated: 2024/06/12 19:39:23 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_img_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1000, 700, "Hello world");
	img.img = mlx_new_image(mlx, 1000, 700);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	for (int i=0; i <=100; i++)
	{
		my_pixel_put(&img, 500 + i, 350, 0x00FF0000);
	}
//	mlx_pixel_put(mlx, mlx_win, 5, 5, 0x00FF0000);
//	my_pixel_put(&img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	mlx_destroy_image(mlx, img.img);
	mlx_destroy_window(mlx, mlx_win);
}
