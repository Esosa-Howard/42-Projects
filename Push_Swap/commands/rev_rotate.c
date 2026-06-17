/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoward <ahoward@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 22:44:55 by ahoward           #+#    #+#             */
/*   Updated: 2025/11/13 17:46:05 by ahoward          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	reverse_rotate(t_stack **stack)
{
	t_stack	*rotated_node;

	if (!*stack || !(*stack)->next)
		return ;
	rotated_node = last_node(*stack);
	rotated_node->prev->next = NULL;
	rotated_node->prev = NULL;
	rotated_node->next = *stack;
	rotated_node->next->prev = rotated_node;
	*stack = rotated_node;
}

void	rra(t_stack **a, bool print)
{
	reverse_rotate(a);
	if (!print)
		ft_printf("%s\n", "rra");
}

void	rrb(t_stack **b, bool print)
{
	reverse_rotate(b);
	if (!print)
		ft_printf("%s\n", "rrb");
}

void	rrr(t_stack **a, t_stack **b, bool print)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (!print)
		ft_printf("%s\n", "rrr");
}
