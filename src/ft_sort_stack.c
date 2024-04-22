/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 15:26:09 by bohlee            #+#    #+#             */
/*   Updated: 2023/06/26 14:19:52 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_move_on_stack_a(t_list **stack_a, t_list **stack_b,
			size_t low, size_t high)
{
	int		flag;
	size_t	count;

	flag = 0;
	if (*stack_b == 0)
		flag = 1;
	count = 0;
	while (count < (high - low) * 2)
	{
		if (*((size_t *)(*stack_a)->content) >= high)
			ft_do_action_stack(stack_a, stack_b, "ra");
		else
		{
			ft_do_action_stack(stack_a, stack_b, "pb");
			if (flag && *((size_t *)(*stack_b)->content) < low &&
					ft_lstsize(*stack_b))
				ft_do_action_stack(stack_a, stack_b, "rb");
			else if (!flag && *((size_t *)(*stack_b)->content) >= low &&
					ft_lstsize(*stack_b))
				ft_do_action_stack(stack_a, stack_b, "rb");
			count++;
		}
	}
}

static int	ft_separate_stack_a(t_list **stack_a, t_list **stack_b,
			size_t low, size_t high)
{
	size_t	size;
	size_t	low_p;
	size_t	high_p;

	size = high - low;
	if (ft_is_stack_aligned(stack_a, size))
		return (1);
	if (size <= 3)
	{
		ft_sort_out(stack_a, stack_b, size);
		return (1);
	}
	low_p = low + (size / 3);
	high_p = low + ((size / 3) * 2);
	ft_move_on_stack_a(stack_a, stack_b, low_p, high_p);
	ft_revers_rotate_both(stack_a, stack_b, low, high);
	ft_sort_out_stack(stack_a, stack_b, high_p, high);
	return (0);
}

static void	ft_move_on_stack_b(t_list **stack_a, t_list **stack_b,
			size_t low, size_t high)
{
	size_t	count;
	size_t	size;
	size_t	pivot;

	count = 0;
	size = (high - low) / 3;
	pivot = low + size;
	while (count < (high - low) - size)
	{
		if (*((size_t *)(*stack_b)->content) < pivot)
			ft_do_action_stack(stack_a, stack_b, "rb");
		else
		{
			ft_do_action_stack(stack_a, stack_b, "pa");
			if (*((size_t *)(*stack_a)->content) < pivot + size)
				ft_do_action_stack(stack_a, stack_b, "ra");
			count++;
		}
	}
	ft_sort_out_stack(stack_a, stack_b, pivot + size, high);
	ft_revers_rotate_both(stack_a, stack_b, low, pivot + size);
	ft_sort_out_stack(stack_a, stack_b, pivot, pivot + size);
	count = 0;
	while (count++ < size)
		ft_do_action_stack(stack_a, stack_b, "pa");
}

static void	ft_separate_stack_b(t_list **stack_a, t_list **stack_b,
			size_t low, size_t high)
{
	size_t	pivot;
	size_t	size;
	size_t	count;

	if (*stack_b == 0)
		return ;
	count = 0;
	size = (high - low) / 3;
	if (size <= 3)
	{
		while (count < size * 2)
		{
			count++;
			ft_do_action_stack(stack_a, stack_b, "pa");
			if (count % size == 0)
				ft_sort_out(stack_a, stack_b, size);
		}
		return ;
	}
	pivot = low + size;
	ft_move_on_stack_b(stack_a, stack_b, pivot, pivot + size);
	ft_sort_out_stack(stack_a, stack_b, pivot, pivot + (size / 3));
	ft_move_on_stack_b(stack_a, stack_b, low, pivot);
	ft_sort_out_stack(stack_a, stack_b, low, low + (size / 3));
}

void	ft_sort_out_stack(t_list **stack_a, t_list **stack_b, size_t low,
			size_t high)
{
	int	flag;

	if (ft_is_complete(stack_a, stack_b))
		return ;
	flag = ft_separate_stack_a(stack_a, stack_b, low, high);
	if (flag)
		return ;
	ft_separate_stack_b(stack_a, stack_b, low, high);
}
