/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 20:23:51 by mamichal          #+#    #+#             */
/*   Updated: 2024/06/26 12:00:18 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

double	map(double unscaled, double new_min, double new_max, double old_max)
{
	double	old_min;
	double	new_difference;
	double	old_difference;

	old_min = 0;
	new_difference = new_max - new_min;
	old_difference = old_max - old_min;
	return (new_difference * (unscaled - old_min) / old_difference + new_min);
}

t_complex	sum_complex(t_complex z1, t_complex z2)
{
	t_complex	res;

	res.real = z1.real + z2.real;
	res.imaginary = z1.imaginary + z2.imaginary;
	return (res);
}

/*
 * NOTE:
 * real = (real^2 - imaginary^2)
 * imaginary = (2*real*imaginary)
 * OH YES I REAAAAAAALLLYY LOVE COMPLEX MATH ;_;
*/
t_complex	square_complex(t_complex z)
{
	t_complex	res;

	res.real = (z.real * z.real) - (z.imaginary * z.imaginary);
	res.imaginary = (2 * z.real * z.imaginary);
	return (res);
}

int	parse_rgb(int red, int green, int blue)
{
	return (red << 16 | green << 8 | blue);
}

int	count_gradient(int i, t_fractol_data *data)
{
	int	red;
	int	green;
	int	blue;

	map(i, 0, 1, data->fractal.utils.iterations_number);
	red = 9 * (1 - i) * (i * i * i) * 255;
	green = 15 * ((1 - i) * (1 - i)) * (i * i) * 255;
	blue = 8.5 * ((1 - i) * (1 - i) * (1 - i)) * i * 255;
	return (parse_rgb(red, green, blue));
}
