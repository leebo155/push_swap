/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_action_stack_extend.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 13:37:05 by bohlee            #+#    #+#             */
/*   Updated: 2023/06/25 14:32:08 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_stack_node_rotate(t_list **stack)
{
	t_list	*body;
	t_list	*tail;

	if (*stack == 0)
		return ;
	if ((*stack)->next == 0)
		return ;
	tail = ft_lstlast(*stack);
	body = (*stack)->next;
	(*stack)->next = 0;
	tail->next = *stack;
	*stack = body;
}

static void	ft_stack_node_revers_rotate(t_list **stack)
{
	t_list	*tail;
	t_list	*body;

	if (*stack == 0)
		return ;
	if ((*stack)->next == 0)
		return ;
	tail = ft_lstlast(*stack);
	body = *stack;
	if (body->next == 0)
		return ;
	while (body->next != tail)
		body = body->next;
	body->next = 0;
	tail->next = *stack;
	*stack = tail;
}

void	ft_do_action_stack_extend(t_list **stack_a, t_list **stack_b, char *str)
{
	if (str[1] == 'a')
		ft_stack_node_rotate(stack_a);
	else if (str[1] == 'b')
		ft_stack_node_rotate(stack_b);
	else if (str[1] == 'r')
	{
		if (str[2] == 0)
		{
			ft_stack_node_rotate(stack_a);
			ft_stack_node_rotate(stack_b);
		}
		else if (str[2] == 'a')
			ft_stack_node_revers_rotate(stack_a);
		else if (str[2] == 'b')
			ft_stack_node_revers_rotate(stack_b);
		else if (str[2] == 'r')
		{
			ft_stack_node_revers_rotate(stack_a);
			ft_stack_node_revers_rotate(stack_b);
		}
	}
}
