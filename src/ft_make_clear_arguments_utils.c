/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_clear_arguments_utils.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:14:12 by bohlee            #+#    #+#             */
/*   Updated: 2023/06/02 16:46:28 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_is_whitespace(char **strs, int str_index, size_t char_index)
{
	if (strs[str_index][char_index] &&
			((9 <= strs[str_index][char_index] &&
			strs[str_index][char_index] <= 13) ||
			strs[str_index][char_index] == 32))
		return (1);
	else
		return (0);
}

size_t	ft_count_separted_pieces(char **strs, int strs_size)
{
	int		str_index;
	size_t	char_index;
	size_t	count;

	str_index = 1;
	count = 0;
	while (str_index < strs_size)
	{
		char_index = 0;
		while (strs[str_index][char_index])
		{
			while (ft_is_whitespace(strs, str_index, char_index))
				char_index++;
			if (strs[str_index][char_index])
				count++;
			while (strs[str_index][char_index] &&
					!ft_is_whitespace(strs, str_index, char_index))
				char_index++;
		}
		str_index++;
	}
	return (count);
}

static char	*ft_make_pieces(char *str, size_t start)
{
	char	*result;
	size_t	char_index;
	size_t	size;

	char_index = 0;
	size = 0;
	while (str[start + size] && !ft_is_whitespace(&str, 0,
			start + size))
		size++;
	result = (char *)malloc(sizeof(char) * (size + 1));
	if (result == 0)
		return (0);
	while (char_index < size)
	{
		result[char_index] = str[start + char_index];
		char_index++;
	}
	result[char_index] = 0;
	return (result);
}

static void	ft_free_and_exit(char ***result, size_t res_index)
{
	size_t	index;

	index = 0;
	while (index + 1 < res_index)
		free((*result)[index++]);
	free(*result);
	ft_print_error_and_exit();
}

char	**ft_separte_pieces(char ***result, char **strs, int strs_size)
{
	int		str_i;
	size_t	char_i;
	size_t	res_i;

	res_i = 0;
	str_i = 0;
	while (++str_i < strs_size)
	{
		char_i = 0;
		while (strs[str_i][char_i])
		{
			while (ft_is_whitespace(strs, str_i, char_i))
				char_i++;
			if (strs[str_i][char_i])
			{
				(*result)[res_i] = ft_make_pieces(strs[str_i], char_i);
				if ((*result)[res_i++] == 0)
					ft_free_and_exit(result, res_i);
			}
			while (strs[str_i][char_i] &&
					!ft_is_whitespace(strs, str_i, char_i))
				char_i++;
		}
	}
	return (*result);
}
