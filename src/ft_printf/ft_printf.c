/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 13:09:33 by bohlee            #+#    #+#             */
/*   Updated: 2023/05/23 11:21:37 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	char	*res;
	ssize_t	res_i;
	size_t	fmt_i;
	va_list	vars;

	if (format == 0)
		return (-1);
	res_i = 0;
	fmt_i = 0;
	res = 0;
	va_start(vars, format);
	while (format[fmt_i] && res_i >= 0)
	{
		if (format[fmt_i] == '%')
		{
			res = ft_conv_var(&res, (char *)(&format[fmt_i]), &res_i, &vars);
			fmt_i += 2;
		}
		if (format[fmt_i] && res_i >= 0)
			res = ft_make_str(&res, (char *)format, &fmt_i, &res_i);
	}
	va_end(vars);
	if (res == 0 && (fmt_i || res_i < 0))
		return (-1);
	return (ft_putstr_free(&res, res_i));
}
