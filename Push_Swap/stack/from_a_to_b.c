/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   from_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoward <ahoward@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 20:07:37 by ahoward           #+#    #+#             */
/*   Updated: 2025/11/17 18:39:33 by ahoward          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	set_target_a(t_stack *a, t_stack *b)
{
	long	current_target;
	t_stack	*tmp_b;
	t_stack	*final_target;

	while (a)
	{
		current_target = LONG_MIN;
		tmp_b = b;
		while (tmp_b)
		{
			if (a->value > tmp_b->value && tmp_b->value > current_target)
			{
				current_target = tmp_b->value;
				final_target = tmp_b;
			}
			tmp_b = tmp_b->next;
		}
		if (current_target == LONG_MIN)
			a->target_node = find_biggest(b);
		else
			a->target_node = final_target;
		a = a->next;
	}
}

static void	set_cost_a(t_stack *a, t_stack *b)
{
	int	a_len;
	int	b_len;

	a_len = stack_len(a);
	b_len = stack_len(b);
	while (a)
	{
		a->push_cost = a->index;
		if (!(a->above_median))
			a->push_cost = a_len - (a->index);
		if (a->target_node->above_median)
			a->push_cost += a->target_node->index;
		else
			a->push_cost += b_len - a->target_node->index;
		a = a->next;
	}
}

void	a_to_b(t_stack *a, t_stack *b)
{
	current_index(a);
	current_index(b);
	set_target_a(a, b);
	set_cost_a(a, b);
	set_cheapest(a);
}
