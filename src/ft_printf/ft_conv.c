/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 15:18:38 by bohlee            #+#    #+#             */
/*   Updated: 2023/05/18 16:28:59 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_conv_char(va_list *vars, int percent)
{
	char	*result;

	result = (char *)malloc(sizeof(char) * 2);
	if (result == 0)
		return (result);
	if (percent)
		result[0] = '%';
	else
		result[0] = va_arg(*vars, int);
	result[1] = 0;
	return (result);
}

char	*ft_conv_str(va_list *vars)
{
	char	*var;

	var = va_arg(*vars, char *);
	if (var)
		return (ft_strdup(var));
	return (ft_strdup("(null)"));
}

char	*ft_conv_address(va_list *vars)
{
	char	*result;
	int		res_size;
	size_t	address;
	size_t	tmp_address;

	res_size = 2;
	tmp_address = va_arg(*vars, size_t);
	if (tmp_address == 0)
		res_size++;
	address = tmp_address;
	while (tmp_address && res_size++)
		tmp_address /= 16;
	result = (char *)malloc(sizeof(char) * (res_size + 1));
	if (result == 0)
		return (result);
	result[res_size--] = 0;
	while (res_size > 1)
	{
		result[res_size--] = "0123456789abcdef"[address % 16];
		address /= 16;
	}
	result[res_size--] = 'x';
	result[res_size] = '0';
	return (result);
}

char	*ft_conv_pos_number(va_list *vars)
{
	char			*result;
	int				res_size;
	unsigned int	tmp_number;
	unsigned int	number;

	res_size = 0;
	tmp_number = va_arg(*vars, unsigned int);
	number = tmp_number;
	if (tmp_number == 0)
		res_size++;
	while (tmp_number)
	{
		tmp_number /= 10;
		res_size++;
	}
	result = (char *)malloc(sizeof(char) * (res_size + 1));
	if (result == 0)
		return (0);
	result[res_size--] = 0;
	while (res_size >= 0)
	{
		result[res_size--] = (number % 10) + '0';
		number /= 10;
	}
	return (result);
}

char	*ft_conv_number(va_list *vars, int type)
{
	char	*result;
	int		minus;
	int		unit;
	ssize_t	number;

	minus = 0;
	if (type == 3 || type == 4)
		number = va_arg(*vars, int);
	else
		number = va_arg(*vars, unsigned int);
	if (number < 0)
		minus++;
	unit = 10;
	if (type == 6 || type == 7)
		unit = 16;
	result = ft_get_number(number, type, unit, minus);
	return (result);
}
