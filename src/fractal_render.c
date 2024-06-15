/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 19:56:16 by mamichal          #+#    #+#             */
/*   Updated: 2024/06/15 20:23:33 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	is_in_fractal_set(int horizontal, int vertical, t_fractol_data *data)
{

}

void	fractal_render(t_fractol_data *data)
{
	int	horizontal;
	int	vertical;

	vertical = 0;
	while (vertical++ < HEIGHT)
	{
		horizontal = 0;
		while (horizontal++ < WIDTH)
		{
			is_in_fractal_set(horizontal, vertical, data);
		}
	}
}
