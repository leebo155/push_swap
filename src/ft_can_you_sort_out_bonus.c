/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_can_you_sort_out_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 17:18:13 by bohlee            #+#    #+#             */
/*   Updated: 2023/06/27 19:14:22 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	ft_check_wrong_command(char *str)
{
	if (ft_strlen(str) > 4 || ft_strlen(str) < 3)
		return (1);
	if (ft_strncmp(str, "sa\n", ft_strlen(str)) == 0
		|| ft_strncmp(str, "sb\n", ft_strlen(str)) == 0
		|| ft_strncmp(str, "ss\n", ft_strlen(str)) == 0
		|| ft_strncmp(str, "pa\n", ft_strlen(str)) == 0
		|| ft_strncmp(str, "pb\n", ft_strlen(str)) == 0
		|| ft_strncmp(str, "ra\n", ft_strlen(str)) == 0
		|| ft_strncmp(str, "rb\n", ft_strlen(str)) == 0
		|| ft_strncmp(str, "rr\n", ft_strlen(str)) == 0
		|| ft_strncmp(str, "rra\n", ft_strlen(str)) == 0
		|| ft_strncmp(str, "rrb\n", ft_strlen(str)) == 0
		|| ft_strncmp(str, "rrr\n", ft_strlen(str)) == 0)
		return (0);
	else
		return (1);
}

static char	*ft_convert_command(char **str)
{
	char	*result;
	int		index;

	if (ft_check_wrong_command(*str))
	{
		free(*str);
		return (0);
	}
	index = 0;
	result = (char *)malloc(sizeof(char) * ft_strlen(*str));
	if (result == 0)
		return (0);
	while ((*str)[index] != '\n')
	{
		result[index] = (*str)[index];
		index++;
	}
	result[index] = 0;
	free(*str);
	return (result);
}

void	ft_can_you_sort_out(t_list **stack_a, t_list **stack_b)
{
	char	*str;
	char	*command;

	while (1)
	{
		str = get_next_line(0);
		if (str == 0)
			break ;
		command = ft_convert_command(&str);
		if (command == 0)
		{
			ft_remove_stack(stack_a);
			ft_remove_stack(stack_b);
			ft_print_error_and_exit();
		}
		ft_do_action_stack(stack_a, stack_b, command);
		free(command);
	}
}
