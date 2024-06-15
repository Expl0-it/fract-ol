/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 20:23:51 by mamichal          #+#    #+#             */
/*   Updated: 2024/06/15 21:00:38 by mamichal         ###   ########.fr       */
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
