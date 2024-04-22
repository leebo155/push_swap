/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stack_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 12:21:45 by bohlee            #+#    #+#             */
/*   Updated: 2023/06/26 14:28:26 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_revers_rotate_both_extend(t_list **stack_a, t_list **stack_b,
			size_t low, size_t high)
{
	t_list			*tail_a;
	t_list			*tail_b;
	static int		flag;
	static size_t	max;

	if (flag == 0)
	{
		max = high;
		flag = 1;
	}
	tail_a = ft_lstlast(*stack_a);
	tail_b = ft_lstlast(*stack_b);
	while (*((size_t *)tail_a->content) < high && max != high
		&& *((size_t *)tail_a->content) >= low)
	{
		ft_do_action_stack(stack_a, stack_b, "rra");
		tail_a = ft_lstlast(*stack_a);
	}
	while (*((size_t *)tail_b->content) >= low && low)
	{
		ft_do_action_stack(stack_a, stack_b, "rrb");
		tail_b = ft_lstlast(*stack_b);
	}
}

void	ft_revers_rotate_both(t_list **stack_a, t_list **stack_b,
			size_t low, size_t high)
{
	t_list			*tail_a;
	t_list			*tail_b;
	static int		flag;
	static size_t	max;

	if (flag == 0)
	{
		max = high;
		flag = 1;
	}
	tail_a = ft_lstlast(*stack_a);
	tail_b = ft_lstlast(*stack_b);
	while (*((size_t *)tail_a->content) < high && max != high
		&& *((size_t *)tail_a->content) >= low
		&& *((size_t *)tail_b->content) >= low && low)
	{
		ft_do_action_stack(stack_a, stack_b, "rrr");
		tail_a = ft_lstlast(*stack_a);
		tail_b = ft_lstlast(*stack_b);
	}
	ft_revers_rotate_both_extend(stack_a, stack_b, low, high);
}

int	ft_is_stack_aligned(t_list **stack_a, size_t size)
{
	t_list	*tail;
	t_list	*body;
	size_t	index;

	index = 0;
	body = *stack_a;
	while (body->next && index < size)
	{
		tail = body->next;
		if (*((size_t *)body->content) > *((size_t *)tail->content))
			return (0);
		body = tail;
		index++;
	}
	return (1);
}

int	ft_is_complete(t_list **stack_a, t_list **stack_b)
{
	t_list	*tail;
	t_list	*body;

	if (*stack_b)
		return (0);
	body = *stack_a;
	while (body->next)
	{
		tail = body->next;
		if (*((size_t *)body->content) > *((size_t *)tail->content))
			return (0);
		body = tail;
	}
	return (1);
}
