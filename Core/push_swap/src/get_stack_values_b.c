/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stack_values_b.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:33:23 by cgray             #+#    #+#             */
/*   Updated: 2024/03/05 17:59:10 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* sets target a for b to push into */
void	get_target_b(t_stack *a, t_stack *b)
{
	t_stack	*current_a;
	t_stack	*target;
	int		best_match;

	while (b)
	{
		best_match = INT_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->number > b->number
				&& current_a->number < best_match)
			{
				best_match = current_a->number;
				target = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match == INT_MAX)
			b->target_node = stack_min(a);
		else
			b->target_node = target;
		b = b->next;
	}
}

/* prepares nodes and sets variables in t_stack */
void	init_b(t_stack *a, t_stack *b)
{
	get_index(a);
	get_index(b);
	get_target_b(a, b);
}
