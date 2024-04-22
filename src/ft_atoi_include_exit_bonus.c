/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_include_exit_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 16:57:40 by bohlee            #+#    #+#             */
/*   Updated: 2023/06/27 19:04:48 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	ft_is_negative(char *str, int *index)
{
	int	result;

	result = 1;
	if (str[*index] == '-' || str[*index] == '+')
	{
		if (str[(*index)++] == '-')
			result *= -1;
	}
	return (result);
}

static int	ft_is_integer(ssize_t number, int negative)
{
	if (number < 2147483648)
		return (0);
	else if (number == 2147483648 && negative == -1)
		return (0);
	else
		return (1);
}

int	ft_atoi_include_exit(char *str, int **array,
			size_t amount, char ***strs)
{
	int		index;
	int		negative;
	ssize_t	result;

	index = 0;
	result = 0;
	negative = ft_is_negative(str, &index);
	while ('0' <= str[index] && str[index] <= '9')
	{
		result = (result * 10) + (str[index++] - '0');
		if (ft_is_integer(result, negative))
		{
			free(*array);
			ft_free_arguments(amount, strs);
			ft_print_error_and_exit();
		}
	}
	if (str[index])
	{
		free(*array);
		ft_free_arguments(amount, strs);
		ft_print_error_and_exit();
	}
	return (result * negative);
}
