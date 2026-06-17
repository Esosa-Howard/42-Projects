/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoward <ahoward@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:22:20 by ahoward           #+#    #+#             */
/*   Updated: 2025/11/17 19:15:24 by ahoward          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	min_on_top(t_stack **a);

void	triple_sort(t_stack **a)
{
	t_stack	*biggest;

	biggest = find_biggest(*a);
	while (!is_sorted(*a))
	{
		if ((*a) == biggest)
			ra(a, false);
		if ((*a)->value > (*a)->next->value)
			sa(a, false);
		if ((*a)->next == biggest)
			rra(a, false);
	}
}

void	stack_sort(t_stack **a, t_stack **b)
{
	int	a_len;

	a_len = stack_len(*a);
	if (a_len > 3 && !is_sorted(*a))
		pb(a, b, false);
	a_len--;
	if (a_len > 3 && !is_sorted(*a))
		pb(a, b, false);
	a_len--;
	while (a_len > 3 && !is_sorted(*a))
	{
		a_to_b(*a, *b);
		move_a_to_b(a, b);
		a_len--;
	}
	triple_sort(a);
	while (*b)
	{
		b_to_a(*b, *a);
		move_b_to_a(b, a);
	}
	current_index(*a);
	min_on_top(a);
}

static void	min_on_top(t_stack **a)
{
	t_stack	*smallest;

	smallest = find_smallest(*a);
	while (smallest->index != 0)
	{
		if (smallest->above_median)
		{
			ra(a, false);
			current_index(*a);
		}
		else
		{
			rra(a, false);
			current_index(*a);
		}
	}
}
