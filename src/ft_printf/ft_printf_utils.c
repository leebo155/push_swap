/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 14:26:58 by bohlee            #+#    #+#             */
/*   Updated: 2023/05/23 11:45:58 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_check_var(char *str, size_t start)
{
	size_t	index;

	index = 0;
	while (str[index + start])
	{
		if (str[index + start] == '%')
			return (index);
		index++;
	}
	return (index);
}

ssize_t	ft_putstr_free(char **str, ssize_t str_size)
{
	ssize_t	index;
	ssize_t	write_length;
	ssize_t	size;

	if ((int)str_size < 0)
	{
		ft_free_and_clean(str);
		return (-1);
	}
	index = 0;
	size = str_size;
	while (index < str_size)
	{
		write_length = write(1, &(*str)[index++], 1);
		if (write_length < 0)
		{
			size = write_length;
			break ;
		}
	}
	ft_free_and_clean(str);
	return (size);
}

void	*ft_free_and_clean(char **str)
{
	if (*str)
	{
		free(*str);
		*str = 0;
	}
	return (*str);
}

char	*ft_conv_var(char **src, char *buf, ssize_t *src_size, va_list *vars)
{
	char	*dst;
	int		type_num;

	type_num = 0;
	while (type_num < 9 && "cspdiuxX%"[type_num] != buf[1])
		type_num++;
	if (type_num > 8)
		return (ft_free_and_clean(src));
	if (type_num == 0 || type_num == 8)
		dst = ft_conv_char(vars, type_num);
	else if (type_num == 1)
		dst = ft_conv_str(vars);
	else if (type_num == 2)
		dst = ft_conv_address(vars);
	else if (type_num == 5)
		dst = ft_conv_pos_number(vars);
	else
		dst = ft_conv_number(vars, type_num);
	return (ft_strjoin_free(src, &dst, type_num, src_size));
}

char	*ft_make_str(char **src, char *buf,
		size_t *buf_index, ssize_t *src_size)
{
	char	*dst;
	size_t	dst_size;
	size_t	dst_index;

	if (buf[*buf_index] == '%')
		return (*src);
	dst_index = 0;
	dst_size = ft_check_var(buf, *buf_index);
	if (dst_size == 0)
		return (*src);
	dst = (char *)malloc(sizeof(char) * (dst_size + 1));
	if (dst == 0)
	{
		*src_size = -1;
		return (ft_free_and_clean(src));
	}
	while (dst_index < dst_size)
		dst[dst_index++] = buf[(*buf_index)++];
	dst[dst_index] = 0;
	return (ft_strjoin_free(src, &dst, 1, src_size));
}
