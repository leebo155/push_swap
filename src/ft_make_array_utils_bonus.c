/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_array_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 17:02:58 by bohlee            #+#    #+#             */
/*   Updated: 2023/06/27 17:03:10 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	*ft_duplicate_array(int **array, size_t size)
{
	size_t	index;
	int		*result;

	index = 0;
	result = (int *)malloc(sizeof(int) * size);
	if (result == 0)
	{
		free(*array);
		ft_print_error_and_exit();
	}
	while (index < size)
	{
		result[index] = (*array)[index];
		index++;
	}
	return (result);
}

static void	ft_swap_array_values(int **array, size_t low, size_t high)
{
	int	tmp;

	tmp = (*array)[low];
	(*array)[low] = (*array)[high];
	(*array)[high] = tmp;
}

static void	ft_quick_sort_array(int **array, size_t size, size_t pivot)
{
	size_t	low;
	size_t	high;

	if (size == pivot)
		return ;
	low = pivot;
	high = size;
	while (low <= high && low < size && high > pivot)
	{
		if ((*array)[low] > (*array)[pivot] &&
			(*array)[high] < (*array)[pivot])
			ft_swap_array_values(array, low, high);
		if ((*array)[low] <= (*array)[pivot])
			low++;
		if ((*array)[high] > (*array)[pivot])
			high--;
	}
	if (pivot < high)
		ft_swap_array_values(array, pivot, high);
	ft_quick_sort_array(array, high, pivot);
	ft_quick_sort_array(array, size, low);
}

static size_t	*ft_make_bigger_size_array(int **array, size_t size)
{
	size_t	*result;

	result = (size_t *)malloc(sizeof(size_t) * size);
	if (result == 0)
	{
		free(*array);
		ft_print_error_and_exit();
	}
	return (result);
}

size_t	*ft_simplify_array(int **array, size_t size)
{
	size_t	array_i;
	size_t	sort_array_i;
	int		*sort_array;
	size_t	*result;

	array_i = 0;
	sort_array = ft_duplicate_array(array, size);
	result = ft_make_bigger_size_array(array, size);
	ft_quick_sort_array(&sort_array, size - 1, 0);
	while (array_i < size)
	{
		sort_array_i = 0;
		while (sort_array_i < size)
		{
			if ((*array)[array_i] == sort_array[sort_array_i])
				result[array_i] = sort_array_i;
			sort_array_i++;
		}
		array_i++;
	}
	free(sort_array);
	free(*array);
	return (result);
}
