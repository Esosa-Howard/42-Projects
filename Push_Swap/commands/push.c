/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoward <ahoward@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 11:41:06 by ahoward           #+#    #+#             */
/*   Updated: 2025/11/15 05:15:41 by ahoward          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//from the top of b to a
void	pa(t_stack **b, t_stack **a, bool print)
{
	t_stack	*tmp;

	if (!*b)
		return ;
	tmp = *b;
	*b = (*b)->next;
	if (*b)
		(*b)->prev = NULL;
	if (!*a)
	{
		*a = tmp;
		tmp->next = NULL;
		tmp->prev = NULL;
	}
	else
	{
		tmp->next = *a;
		tmp->next->prev = tmp;
		tmp->prev = NULL;
		*a = tmp;
	}
	if (!print)
		ft_printf("%s\n", "pa");
}

//from the top of a to b
void	pb(t_stack **a, t_stack **b, bool print)
{
	t_stack	*tmp;

	if (!*a)
		return ;
	tmp = *a;
	*a = (*a)->next;
	if (*a)
		(*a)->prev = NULL;
	if (!*b)
	{
		*b = tmp;
		tmp->next = NULL;
		tmp->prev = NULL;
	}
	else
	{
		tmp->next = *b;
		tmp->next->prev = tmp;
		tmp->prev = NULL;
		*b = tmp;
	}
	if (!print)
		ft_printf("%s\n", "pb");
}
