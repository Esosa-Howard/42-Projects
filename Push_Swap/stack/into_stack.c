/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   into_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stranger <stranger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 14:35:17 by ahoward           #+#    #+#             */
/*   Updated: 2026/02/03 19:59:21 by stranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	append_node(t_stack **stack, int n)
{
	t_stack	*tmp;
	t_stack	*end;

	if (!stack)
		return ;
	tmp = malloc(sizeof (t_stack));
	if (!tmp)
		return ;
	tmp->value = n;
	tmp->next = NULL;
	tmp->prev = NULL;
	if (!(*stack))
	{
		*stack = tmp;
	}
	else
	{
		end = last_node(*stack);
		end->next = tmp;
		tmp->prev = end;
	}
}

void	into_stack(t_stack **a, char **argv)
{
	long	n;
	int		i;

	i = 0;
	n = ft_atol(argv[i]);
	while (argv[i])
	{
		if (syntax_check(argv[i]))
			free_errors(a);
		n = ft_atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			free_errors(a);
		if (repetitions(*a, (int)n))
			free_errors(a);
		append_node(a, (int)n);
		i++;
	}
}
