/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 15:40:06 by bohlee            #+#    #+#             */
/*   Updated: 2023/06/27 19:28:26 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	char	**arguments;
	size_t	size;
	size_t	*array_a;
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc - 1 == 0)
		return (1);
	size = ft_count_separted_pieces(argv, argc);
	if (size == 0)
		ft_print_error_and_exit();
	stack_b = 0;
	arguments = ft_make_clear_arguments(argv, argc);
	array_a = ft_make_array(size, &arguments);
	stack_a = ft_convert_array_into_stack(&array_a, size);
	ft_sort_out_stack(&stack_a, &stack_b, 0, size);
	ft_remove_stack(&stack_a);
	ft_remove_stack(&stack_b);
	return (0);
}
