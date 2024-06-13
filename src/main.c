/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 19:38:09 by mamichal          #+#    #+#             */
/*   Updated: 2024/06/12 20:31:18 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	main(int argc, char **argv)
{
	if (2 == argc && !ft_strncmp(argv[1], "mandelbrot", 10)
		|| 4 == argc && !ft_strncmp(argv[1], "julia", 5))
	{
		
	}
	else
	{
		ft_putstr_fd(ERROR_MSG, STDERR_FILENO);
		exit(INVALID_ARGUMENTS);
	}
}
