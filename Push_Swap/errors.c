/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoward <ahoward@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 12:19:00 by ahoward           #+#    #+#             */
/*   Updated: 2025/11/17 22:47:15 by ahoward          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	repetitions(t_stack *a, int n)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->value == n)
			return (1);
		a = a->next;
	}
	return (0);
}

int	syntax_check(char *argv)
{
	if (!((*argv == '+' || *argv == '-') || (*argv >= '0' && *argv <= '9')))
		return (1);
	if ((*argv == '+' || *argv == '-') && (!(argv[1] >= '0' && argv[1] <= '9')))
		return (1);
	while (*++argv)
	{
		if (!(*argv >= '0' && *argv <= '9'))
			return (1);
	}
	return (0);
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*node;

	if (!stack)
		return ;
	node = *stack;
	while (node)
	{
		tmp = node->next;
		free(node);
		node = tmp;
	}
	*stack = NULL;
}

void	free_errors(t_stack **stack)
{
	free_stack(stack);
	printf("%s/n", ERROR);
	exit(1);
}
