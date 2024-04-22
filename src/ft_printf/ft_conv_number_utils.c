/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_number_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:33:33 by bohlee            #+#    #+#             */
/*   Updated: 2023/05/18 13:38:50 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_get_res_size(ssize_t num, int unit)
{
	ssize_t	number;
	int		size;

	number = num;
	size = 0;
	while (number)
	{
		number /= unit;
		size++;
	}
	if (size)
		return (size);
	else
		return (1);
}

char	*ft_get_number(ssize_t num, int type, int unit, int minus)
{
	char	*result;
	int		res_size;
	int		index;
	ssize_t	number;

	number = num;
	res_size = minus + ft_get_res_size(num, unit);
	result = (char *)malloc(sizeof(char) * (res_size + 1));
	if (result == 0)
		return (0);
	result[res_size--] = 0;
	while (res_size >= minus)
	{
		index = (number % unit) * (1 - (2 * minus));
		if (unit == 10)
			result[res_size--] = "0123456789"[index];
		else if (type == 6)
			result[res_size--] = "0123456789abcdef"[index];
		else
			result[res_size--] = "0123456789ABCDEF"[index];
		number /= unit;
	}
	if (minus)
		result[res_size] = '-';
	return (result);
}
