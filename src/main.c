/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 19:38:09 by mamichal          #+#    #+#             */
/*   Updated: 2024/06/20 13:13:55 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	main(int argc, char **argv)
{
	t_fractol_data	data;

	if (2 == argc && !ft_strncmp(argv[1], "mandelbrot", 10)
		|| 4 == argc && !ft_strncmp(argv[1], "julia", 5))
	{
		data.fractal.p_name = argv[1];
		if (!ft_strncmp(argv[1], "julia", 5))
		{
			data.fractal.julia_x = ft_atod(argv[2]);
			data.fractal.julia_y = ft_atod(argv[3]);
		}
		fractol_data_init(&data);
		fractal_render(&data);
		mlx_loop(data.mlx.p_mlx_conn);
	}
	else
	{
		ft_putstr_fd(ERROR_MSG, STDERR_FILENO);
		exit(INVALID_ARGUMENTS);
	}
}
