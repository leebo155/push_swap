/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 14:16:07 by bohlee            #+#    #+#             */
/*   Updated: 2023/05/19 13:56:03 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_strjoin_char(char *src, char *dst, ssize_t *src_size)
{
	char	*result;
	ssize_t	index;

	index = 0;
	result = (char *)malloc(sizeof(char) * (*src_size + 2));
	if (result == 0)
		return (result);
	while (index < *src_size)
	{
		result[index] = src[index];
		index++;
	}
	result[(*src_size)++] = dst[0];
	result[*src_size] = 0;
	return (result);
}

static char	*ft_strjoin_length(char *src, char *dst, ssize_t *src_size)
{
	char	*result;
	ssize_t	res_size;
	ssize_t	index;

	index = 0;
	res_size = ft_strlen(dst) + *src_size;
	result = (char *)malloc(sizeof(char) * (res_size + 1));
	if (result == 0)
		return (result);
	while (index < *src_size)
	{
		result[index] = src[index];
		index++;
	}
	index = 0;
	while (*src_size < res_size)
		result[(*src_size)++] = dst[index++];
	result[*src_size] = 0;
	return (result);
}

char	*ft_strjoin_free(char **src, char **dst, int type, ssize_t *src_size)
{
	char	*result;

	result = 0;
	if (*dst)
	{
		if (type == 0 || type == 8)
			result = ft_strjoin_char(*src, *dst, src_size);
		else
			result = ft_strjoin_length(*src, *dst, src_size);
	}
	ft_free_and_clean(dst);
	ft_free_and_clean(src);
	if (result == 0)
		*src_size = -1;
	return (result);
}
