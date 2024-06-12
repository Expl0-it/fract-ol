/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includ.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:51:07 by mamichal          #+#    #+#             */
/*   Updated: 2024/06/12 19:27:42 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUD_H
# define INCLUD_H

// INCLUDES
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>
// TODO: DLEATE LATER AFTER ADDING PRINTF TO LIBFT
//# include "../libft/includes/ft_printf.h"
# include "../mlx_linux/mlx.h"

#define WIDTH 500
#define HIGHT 500

typedef enum e_errors
{
	OK = 0,
	MALLOC_ERROR = 1
}				t_errors;

typedef struct	s_img_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img_data;

typedef struct	s_complex
{
	double	real;
	double	imaginary;
}				t_complex;

// src/my_put_pixel.c
void	my_pixel_put(t_img_data *data, int x, int y, int color);

#endif
