/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 11:26:47 by mamichal          #+#    #+#             */
/*   Updated: 2024/06/20 13:30:08 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	ft_atod(char *s)
{
	long	int_part;
	double	float_part;
	double	power;
	int		sign;

	int_part = 0;
	float_part = 0.0;
	sign = 1;
	power = 1.0;
	while ((*s >= 9 && *s <= 13) || 32 == *s)
		s++;
	while ('-' == *s || '+' == *s)
		if ('-' == *s++)
			sign *= -1;
	while (*s != '.' && *s)
		int_part = (int_part * 10) + (*s++ - '0');
	if ('.' == *s)
		s++;
	while (*s)
	{
		power = power / 10;
		float_part = (float_part) + (*s++ - '0') * power;
	}
	return ((int_part + float_part) * sign);
}
