/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoward <ahoward@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 16:48:18 by ahoward           #+#    #+#             */
/*   Updated: 2025/11/13 14:42:38 by ahoward          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*last_node(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
	{
		stack = stack->next;
	}
	return (stack);
}

bool	is_sorted(t_stack *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}

t_stack	*find_biggest(t_stack *stack)
{
	t_stack	*biggest;

	if (!stack)
		return (NULL);
	biggest = stack;
	while (stack)
	{
		if (stack->value > biggest->value)
		{
			biggest = stack;
		}
		stack = stack->next;
	}
	return (biggest);
}

int	stack_len(t_stack *stack)
{
	int	len;

	len = 1;
	if (!stack)
		return (0);
	while (stack->next)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}

t_stack	*find_smallest(t_stack *stack)
{
	t_stack	*smallest;

	if (!stack)
		return (NULL);
	smallest = stack;
	while (stack)
	{
		if (stack->value < smallest->value)
			smallest = stack;
		stack = stack->next;
	}
	return (smallest);
}
