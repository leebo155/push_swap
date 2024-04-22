/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 15:34:02 by bohlee            #+#    #+#             */
/*   Updated: 2024/04/22 11:19:43 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"

char	**ft_make_clear_arguments(char **strs, int strs_size);
size_t	ft_count_separted_pieces(char **strs, int strs_size);
char	**ft_separte_pieces(char ***result, char **strs, int strs_size);
size_t	*ft_make_array(size_t amount, char ***strs);
int		ft_atoi_include_exit(char *str, int **array,
			size_t amount, char ***strs);
size_t	*ft_simplify_array(int **array, size_t size);
t_list	*ft_convert_array_into_stack(size_t **array, size_t size);
void	ft_free_arguments(size_t amount, char ***strs);
void	ft_do_action_stack(t_list **stack_a, t_list **stack_b, char *str);
void	ft_do_action_stack_extend(t_list **stack_a, t_list **stack_b,
			char *str);
void	ft_sort_out_stack(t_list **stack_a, t_list **stack_b, size_t low,
			size_t high);
int		ft_is_stack_aligned(t_list **stack_a, size_t size);
int		ft_is_complete(t_list **stack_a, t_list **stack_b);
void	ft_revers_rotate_both(t_list **stack_a, t_list **stack_b,
			size_t low, size_t high);
void	ft_sort_out(t_list **stack_a, t_list **stack_b, size_t size);
void	ft_print_error_and_exit(void);
void	ft_remove_stack(t_list **head);

#endif
