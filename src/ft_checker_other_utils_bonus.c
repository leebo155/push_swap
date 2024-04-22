/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_other_utils_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 17:00:06 by bohlee            #+#    #+#             */
/*   Updated: 2023/06/27 19:06:07 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	ft_delete_content(void *content)
{
	free(content);
}

static void	ft_free_and_exit(size_t **array, t_list **head, void (*del)(void *))
{
	free(*array);
	ft_lstclear(head, del);
	ft_print_error_and_exit();
}

t_list	*ft_convert_array_into_stack(size_t **array, size_t size)
{
	size_t	index;
	size_t	*content;
	t_list	*head;
	t_list	*new;

	index = 0;
	head = 0;
	while (index < size)
	{
		content = (size_t *)malloc(sizeof(size_t));
		if (content == 0)
			ft_free_and_exit(array, &head, &ft_delete_content);
		*content = (*array)[index++];
		new = ft_lstnew(content);
		if (new == 0)
			ft_free_and_exit(array, &head, &ft_delete_content);
		ft_lstadd_back(&head, new);
	}
	free(*array);
	return (head);
}

void	ft_remove_stack(t_list **head)
{
	ft_lstclear(head, &ft_delete_content);
	*head = 0;
}

int	ft_is_complete(t_list *stack_a, t_list *stack_b)
{
	t_list	*tail;
	t_list	*body;

	if (stack_b)
		return (0);
	body = stack_a;
	while (body->next)
	{
		tail = body->next;
		if (*((size_t *)body->content) > *((size_t *)tail->content))
			return (0);
		body = tail;
	}
	return (1);
}
