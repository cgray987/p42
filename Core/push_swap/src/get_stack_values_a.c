/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stack_values_a.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:15:51 by cgray             #+#    #+#             */
/*   Updated: 2024/03/05 18:02:19 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* sets stack->index for each node in stack and sets
stack->above_median = 1 if position is above median*/
void	get_index(t_stack *stack)
{
	int	median;
	int	i;

	i = 0;
	if (!stack)
		return ;
	median = stack_len(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = 1;
		else
			stack->above_median = 0;
		stack = stack->next;
		++i;
	}
}

/* sets a->cost for each node based on position (above or below median)
of node in a */
void	get_cost(t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (a)
	{
		a->cost = a->index;
		if (!a->above_median)
			a->cost = len_a - (a->index);
		if (a->target_node->above_median == 1)
			a->cost += a->target_node->index;
		else
			a->cost += len_b - (a->target_node->index);
		a = a->next;
	}
}

/* iterates through stack finding cheapest cost found in get_cost */
void	get_cheapest(t_stack *stack)
{
	int		cheapest;
	t_stack	*cheapest_node;

	if (!stack)
		return ;
	cheapest = INT_MAX;
	while (stack)
	{
		if (stack->cost < cheapest)
		{
			cheapest = stack->cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = 1;
}

/* gets a's target node from b */
void	get_target_a(t_stack *a, t_stack *b)
{
	t_stack	*current_b;
	t_stack	*target;
	int		best_match;

	while (a)
	{
		best_match = INT_MIN;
		current_b = b;
		while (current_b)
		{
			if (current_b->number < a->number && current_b->number > best_match)
			{
				best_match = current_b->number;
				target = current_b;
			}
			current_b = current_b->next;
		}
		if (best_match == INT_MIN)
			a->target_node = stack_max(b);
		else
			a->target_node = target;
		a = a->next;
	}
}

/* calls above functions to set values in stack */
void	init_a(t_stack *a, t_stack *b)
{
	get_index(a);
	get_index(b);
	get_target_a(a, b);
	get_cost(a, b);
	get_cheapest(a);
}
