/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stranger <stranger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 14:35:25 by ahoward           #+#    #+#             */
/*   Updated: 2026/02/03 19:59:33 by stranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include "ft_printf.h"
# include "libft.h"

# ifndef ERROR
#  define ERROR "Error"
# endif

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
	int				push_cost;
	bool			cheapest;
	bool			above_median;
	struct s_stack	*target_node;
}			t_stack;

void	into_stack(t_stack **a, char **argv);
int		repetitions(t_stack *a, int n);
int		syntax_check(char *argv);
void	free_stack(t_stack **stack);
void	free_errors(t_stack **stack);
void	pa(t_stack **a, t_stack **b, bool print);
void	pb(t_stack **b, t_stack **a, bool print);
void	sa(t_stack **a, bool print);
void	sb(t_stack **b, bool print);
void	ss(t_stack **a, t_stack **b, bool print);
void	rra(t_stack **a, bool print);
void	rrb(t_stack **b, bool print);
void	ra(t_stack **a, bool print);
void	rb(t_stack **b, bool print);
void	rrr(t_stack **a, t_stack **b, bool print);
void	rr(t_stack **a, t_stack **b, bool print);
t_stack	*last_node(t_stack *stack);
bool	is_sorted(t_stack *stack);
t_stack	*find_biggest(t_stack *stack);
int		stack_len(t_stack *stack);
void	triple_sort(t_stack **a);
void	stack_sort(t_stack **a, t_stack **b);
t_stack	*find_smallest(t_stack *stack);
void	current_index(t_stack *stack);
void	a_to_b(t_stack *a, t_stack *b);
void	b_to_a(t_stack *a, t_stack *b);
void	move_a_to_b(t_stack **a, t_stack **b);
void	move_b_to_a(t_stack **a, t_stack **b);
void	current_index(t_stack *stack);
void	set_cheapest(t_stack *stack);
t_stack	*find_cheapest(t_stack *stack);
void	different_median(t_stack **stack, t_stack *top_node, char stack_name);

#endif