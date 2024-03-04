/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stack_values_b.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:33:23 by cgray             #+#    #+#             */
/*   Updated: 2024/03/04 14:10:28 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_target_b(t_stack *a, t_stack *b)
{
	t_stack	*current_a;
	t_stack	*target;
	int		best_match;

	while (b)
	{
		best_match = INT_MIN;
		current_a = a;
		while (current_a)
		{
			if (current_a->number > b->number
				&& current_a->number < best_match)
			{
				best_match = current_a->number;
				target = current_a->target_node;
			}
			current_a = current_a->next;
		}
		if (best_match == INT_MIN)
			b->target_node = stack_min(a);
		else
			b->target_node = target;
		b = b->next;
	}
}

void	init_b(t_stack *a, t_stack *b)
{
	get_index(a);
	get_index(b);
	get_target_b(a, b);
}
