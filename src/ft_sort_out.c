/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_out.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 17:41:45 by bohlee            #+#    #+#             */
/*   Updated: 2023/06/26 16:15:04 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_triple_sort_out_extra_extend(t_list **stack_a, t_list **stack_b,
			int flag, char *str)
{
	if (str[0] == '0' && str[1] == '2' && flag)
	{
		ft_do_action_stack(stack_a, stack_b, "rra");
		ft_do_action_stack(stack_a, stack_b, "sa");
	}
}

static void	ft_triple_sort_out_extend(t_list **stack_a, t_list **stack_b,
			int flag, char *str)
{
	if (str[0] == '2' && str[1] == '0' && !flag)
	{
		ft_do_action_stack(stack_a, stack_b, "pb");
		ft_do_action_stack(stack_a, stack_b, "ra");
		ft_do_action_stack(stack_a, stack_b, "ra");
		ft_do_action_stack(stack_a, stack_b, "pa");
		ft_do_action_stack(stack_a, stack_b, "rra");
		ft_do_action_stack(stack_a, stack_b, "rra");
	}
	else if (str[0] == '2' && str[1] == '0' && flag)
		ft_do_action_stack(stack_a, stack_b, "ra");
	else if (str[0] == '1' && str[1] == '2' && !flag)
	{
		ft_do_action_stack(stack_a, stack_b, "pb");
		ft_do_action_stack(stack_a, stack_b, "pb");
		ft_do_action_stack(stack_a, stack_b, "ra");
		ft_do_action_stack(stack_a, stack_b, "pa");
		ft_do_action_stack(stack_a, stack_b, "pa");
		ft_do_action_stack(stack_a, stack_b, "rra");
	}
	else if (str[0] == '1' && str[1] == '2' && flag)
		ft_do_action_stack(stack_a, stack_b, "rra");
	else
		ft_triple_sort_out_extra_extend(stack_a, stack_b, flag, str);
}

static void	ft_triple_sort_out(t_list **stack_a, t_list **stack_b, int flag,
			char *str)
{
	if (str[0] == '2' && str[1] == '1' && flag)
	{
		ft_do_action_stack(stack_a, stack_b, "ra");
		ft_do_action_stack(stack_a, stack_b, "sa");
	}
	else if (str[0] == '2' && str[1] == '1' && !flag)
	{
		ft_do_action_stack(stack_a, stack_b, "pb");
		ft_do_action_stack(stack_a, stack_b, "ra");
		ft_do_action_stack(stack_a, stack_b, "pb");
		ft_do_action_stack(stack_a, stack_b, "sb");
		ft_do_action_stack(stack_a, stack_b, "pa");
		ft_do_action_stack(stack_a, stack_b, "rra");
		ft_do_action_stack(stack_a, stack_b, "pa");
	}
	else if (str[0] == '1' && str[1] == '0')
		ft_do_action_stack(stack_a, stack_b, "sa");
	else if (str[0] == '0' && str[1] == '2' && !flag)
	{
		ft_do_action_stack(stack_a, stack_b, "ra");
		ft_do_action_stack(stack_a, stack_b, "sa");
		ft_do_action_stack(stack_a, stack_b, "rra");
	}
	else
		ft_triple_sort_out_extend(stack_a, stack_b, flag, str);
}

static void	ft_triple_sort(t_list **stack_a, t_list **stack_b,	int flag)
{
	t_list	*body;
	t_list	*tail;

	body = (*stack_a)->next;
	tail = body->next;
	if (*((size_t *)(*stack_a)->content) > *((size_t *)body->content))
	{
		if (*((size_t *)(*stack_a)->content) > *((size_t *)tail->content))
		{
			if (*((size_t *)body->content) > *((size_t *)tail->content))
				ft_triple_sort_out(stack_a, stack_b, flag, "210");
			else
				ft_triple_sort_out(stack_a, stack_b, flag, "201");
		}
		else
			ft_triple_sort_out(stack_a, stack_b, flag, "102");
	}
	else
	{
		if (*((size_t *)(*stack_a)->content) > *((size_t *)tail->content))
			ft_triple_sort_out(stack_a, stack_b, flag, "120");
		else
			ft_triple_sort_out(stack_a, stack_b, flag, "021");
	}
}

void	ft_sort_out(t_list **stack_a, t_list **stack_b, size_t size)
{
	int	flag;

	if (ft_is_stack_aligned(stack_a, size))
		return ;
	flag = 0;
	if (ft_lstsize(*stack_a) == size)
		flag = 1;
	if (size < 2)
		return ;
	else if (size == 2)
		ft_do_action_stack(stack_a, stack_b, "sa");
	else
		ft_triple_sort(stack_a, stack_b, flag);
}
