/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_action_stack_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 17:01:44 by bohlee            #+#    #+#             */
/*   Updated: 2023/06/27 19:15:58 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	ft_stack_node_swap(t_list **stack)
{
	t_list	*head;
	t_list	*tail;

	if (*stack == 0)
		return ;
	if ((*stack)->next == 0)
		return ;
	head = *stack;
	tail = (*stack)->next;
	head->next = tail->next;
	*stack = tail;
	(*stack)->next = head;
}

static void	ft_stack_node_push(t_list **act, t_list **pas)
{
	t_list	*tmp;

	if (*act == 0)
		return ;
	tmp = *act;
	*act = (*act)->next;
	tmp->next = *pas;
	*pas = tmp;
}

void	ft_do_action_stack(t_list **stack_a, t_list **stack_b, char *str)
{
	if (str[0] == 's')
	{
		if (str[1] == 'a')
			ft_stack_node_swap(stack_a);
		else if (str[1] == 'b')
			ft_stack_node_swap(stack_b);
		else if (str[1] == 's')
		{
			ft_stack_node_swap(stack_a);
			ft_stack_node_swap(stack_b);
		}
	}
	else if (str[0] == 'p')
	{
		if (str[1] == 'a')
			ft_stack_node_push(stack_b, stack_a);
		else if (str[1] == 'b')
			ft_stack_node_push(stack_a, stack_b);
	}
	else if (str[0] == 'r')
		ft_do_action_stack_extend(stack_a, stack_b, str);
}
