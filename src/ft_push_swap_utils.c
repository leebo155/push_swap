/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 15:31:33 by bohlee            #+#    #+#             */
/*   Updated: 2023/06/26 14:10:31 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_error_and_exit(void)
{
	ft_printf("Error\n");
	exit(1);
}

void	ft_free_arguments(size_t amount, char ***strs)
{
	size_t	index;

	index = 0;
	while (index < amount)
		free((*strs)[index++]);
	free(*strs);
}

char	**ft_make_clear_arguments(char **strs, int strs_size)
{
	int		index;
	size_t	count;
	char	**result;

	index = 0;
	count = ft_count_separted_pieces(strs, strs_size);
	if (count == 0)
		ft_print_error_and_exit();
	result = (char **)malloc(sizeof(char *) * (count));
	if (result == 0)
		ft_print_error_and_exit();
	result = ft_separte_pieces(&result, strs, strs_size);
	return (result);
}

static int	ft_check_duplicates(int *array, size_t size)
{
	size_t	index;

	index = 0;
	while (index < size)
	{
		if (array[index++] == array[size])
			return (1);
	}
	return (0);
}

size_t	*ft_make_array(size_t amount, char ***strs)
{
	int		*array;
	size_t	*result;
	size_t	index;

	index = 0;
	array = (int *)malloc(sizeof(int) * amount);
	if (array == 0)
		ft_print_error_and_exit();
	while (index < amount)
	{
		array[index] = ft_atoi_include_exit((*strs)[index], &array,
				amount, strs);
		if (ft_check_duplicates(array, index++))
		{
			free(array);
			ft_free_arguments(amount, strs);
			ft_print_error_and_exit();
		}
	}
	ft_free_arguments(amount, strs);
	result = ft_simplify_array(&array, index);
	return (result);
}
