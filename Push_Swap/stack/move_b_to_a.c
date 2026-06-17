/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoward <ahoward@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 07:26:02 by ahoward           #+#    #+#             */
/*   Updated: 2025/11/17 19:08:29 by ahoward          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	above_median_b(t_stack **b, t_stack **a, t_stack *cheapest)
{
	while (*a != cheapest && *a != cheapest->target_node)
	{
		rr(a, b, false);
	}
	current_index(*a);
	current_index(*b);
}

static void	below_median_b(t_stack **b, t_stack **a, t_stack *cheapest)
{
	while (*b != cheapest && *a != cheapest->target_node)
	{
		rrr(a, b, false);
	}
	current_index(*a);
	current_index(*b);
}

void	move_b_to_a(t_stack **b, t_stack **a)
{
	t_stack	*cheapest_b;

	cheapest_b = find_cheapest(*b);
	if (cheapest_b->above_median && cheapest_b->target_node->above_median)
		above_median_b(b, a, cheapest_b);
	else if (!(cheapest_b->above_median)
		&& !(cheapest_b->target_node->above_median))
		below_median_b(b, a, cheapest_b);
	different_median(b, cheapest_b, 'b');
	different_median(a, cheapest_b->target_node, 'a');
	pa(b, a, false);
}
