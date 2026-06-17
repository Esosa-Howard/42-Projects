/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   from_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoward <ahoward@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 16:33:25 by ahoward           #+#    #+#             */
/*   Updated: 2025/11/17 18:51:20 by ahoward          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	set_target_b(t_stack *b, t_stack *a)
{
	long	current_target;
	t_stack	*a_tmp;
	t_stack	*final_target;

	while (b)
	{
		a_tmp = a;
		current_target = LONG_MAX;
		while (a_tmp)
		{
			if (b->value < a_tmp->value && a_tmp->value < current_target)
			{
				current_target = a_tmp->value;
				final_target = a_tmp;
			}
			a_tmp = a_tmp->next;
		}
		if (current_target == LONG_MAX)
			b->target_node = find_smallest(a);
		else
			b->target_node = final_target;
		b = b->next;
	}
}

static void	set_cost_b(t_stack *b, t_stack *a)
{
	int	b_len;
	int	a_len;

	a_len = stack_len(a);
	b_len = stack_len(b);
	while (b)
	{
		b->push_cost = b->index;
		if (!(b->above_median))
			b->push_cost = b_len - b->index;
		if (b->target_node->above_median)
			b->push_cost += b->target_node->index;
		else
			b->push_cost += a_len - b->target_node->index;
		b = b->next;
	}
}

void	b_to_a(t_stack *b, t_stack *a)
{
	current_index(b);
	current_index(a);
	set_target_b(b, a);
	set_cost_b(b, a);
	set_cheapest(b);
}
