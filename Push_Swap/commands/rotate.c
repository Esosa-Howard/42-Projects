/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoward <ahoward@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 11:40:46 by ahoward           #+#    #+#             */
/*   Updated: 2025/11/13 17:40:03 by ahoward          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack	*rotated_node;
	t_stack	*tail;

	if (!*stack || !(*stack)->next)
		return ;
	tail = last_node(*stack);
	rotated_node = *stack;
	(*stack)->next->prev = NULL;
	*stack = (*stack)->next;
	tail->next = rotated_node;
	rotated_node->prev = tail;
	rotated_node->next = NULL;
}

void	ra(t_stack **a, bool print)
{
	rotate(a);
	if (!print)
		ft_printf("%s\n", "ra");
}

void	rb(t_stack **b, bool print)
{
	rotate(b);
	if (!print)
		ft_printf("%s\n", "rb");
}

void	rr(t_stack **a, t_stack **b, bool print)
{
	rotate(a);
	rotate(b);
	if (!print)
		ft_printf("%s\n", "rr");
}
