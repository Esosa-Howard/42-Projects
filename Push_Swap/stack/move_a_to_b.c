/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoward <ahoward@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 18:09:07 by ahoward           #+#    #+#             */
/*   Updated: 2025/11/17 19:08:33 by ahoward          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	above_median_a(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (*a != cheapest && *b != cheapest->target_node)
	{
		rr(a, b, false);
	}
	current_index(*a);
	current_index(*b);
}

static void	below_median_a(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (*a != cheapest && *b != cheapest->target_node)
	{
		rrr(a, b, false);
	}
	current_index(*a);
	current_index(*b);
}

void	move_a_to_b(t_stack **a, t_stack **b)
{
	t_stack	*cheapest_a;

	cheapest_a = find_cheapest(*a);
	if (cheapest_a->above_median && cheapest_a->target_node->above_median)
		above_median_a(a, b, cheapest_a);
	else if (!(cheapest_a->above_median)
		&& !(cheapest_a->target_node->above_median))
		below_median_a(a, b, cheapest_a);
	different_median(a, cheapest_a, 'a');
	different_median(b, cheapest_a->target_node, 'b');
	pb(a, b, false);
}
