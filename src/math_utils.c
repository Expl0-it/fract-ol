/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 20:23:51 by mamichal          #+#    #+#             */
/*   Updated: 2024/06/15 20:41:14 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

double	apply_scale(t_scale scale_values)
{
	double	new_difference;
	double	old_difference;

	new_difference = scale_values.new_max - scale_values.new_min;
	old_difference = scale_values.old_max - scale_values.old_min;
	return (new_difference * (scale_values.unscaled_num \
		- scale_values.old_min) / old_difference \
		+ scale_values.new_min);
}
