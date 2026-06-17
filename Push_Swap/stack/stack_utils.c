/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoward <ahoward@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 15:10:17 by ahoward           #+#    #+#             */
/*   Updated: 2025/11/17 18:52:01 by ahoward          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	current_index(t_stack *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = stack_len(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		i++;
		stack = stack->next;
	}
}

void	set_cheapest(t_stack *stack)
{
	long	cheapest;
	t_stack	*tmp;

	if (!stack)
		return ;
	tmp = stack;
	cheapest = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < cheapest)
		{
			cheapest = stack->push_cost;
			tmp = stack;
		}
		else
			stack->cheapest = false;
		stack = stack->next;
	}
	tmp->cheapest = true;
}

t_stack	*find_cheapest(t_stack *stack)
{
	t_stack	*cheapest_node;

	cheapest_node = stack;
	while (stack)
	{
		if (stack->cheapest)
			cheapest_node = stack;
		stack = stack->next;
	}
	return (cheapest_node);
}

void	min_on_top(t_stack *a)
{
	t_stack	*smallest;

	smallest = a;
	while (a)
	{
		if (a->value < smallest->value)
			smallest = a;
		a = a->next;
	}
}

void	different_median(t_stack **stack, t_stack *top_node, char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ra(stack, false);
			else if (!(top_node->above_median))
				rra(stack, false);
		}
		if (stack_name == 'b')
		{
			if (top_node->above_median)
				rb(stack, false);
			else if (!(top_node->above_median))
				rrb(stack, false);
		}
	}
}
