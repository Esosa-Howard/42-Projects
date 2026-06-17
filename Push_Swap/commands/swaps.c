/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoward <ahoward@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 11:40:23 by ahoward           #+#    #+#             */
/*   Updated: 2025/11/13 14:47:56 by ahoward          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	swap(t_stack **head)
{
	t_stack	*tmp;

	if (!*head || !(*head)->next)
		return ;
	tmp = *head;
	*head = (*head)->next;
	if ((*head)->next)
	{
		tmp->next = (*head)->next;
		tmp->next->prev = tmp;
	}
	else
	{
		tmp->next = NULL;
	}
	(*head)->next = tmp;
	(*head)->next->prev = *head;
	(*head)->prev = NULL;
}

void	sa(t_stack **a, bool print)
{
	swap(a);
	if (!print)
		ft_printf("%s\n", "sa");
}

void	sb(t_stack **b, bool print)
{
	swap(b);
	if (!print)
		ft_printf("%s\n", "sb");
}

void	ss(t_stack **a, t_stack **b, bool print)
{
	swap(a);
	swap(b);
	if (!print)
		ft_printf("%s\n", "ss");
}
