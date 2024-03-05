/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:47:30 by cgray             #+#    #+#             */
/*   Updated: 2024/03/05 17:57:43 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/* Adapted from https://medium.com/@ayogun/push-swap-c1f5d2d41e97

0)	initialize variables
1)	Push 2 nums from top of stack a into b
2)	Find number requiring least amount of operations (get_cost)
	to push into correct position in b
	-calculate num of operations it takes to push into correct position in b
	-count every number in a to find cheapest push
3)	repeat until 3 nums left in a
4)	sort a
5)	check top number in b to see where it fits into a (prep_push)
6)	if needed, rotate a until it is ready for top b number (prep_push)
7)	repeat until stack b is empty
8)	rotate a if needed to sort (put min on top)
*/

/* resets index after rotating stack */
void	rotate_index(t_stack **a, t_stack **b, t_stack *cheapest, int rev)
{
	while (*b != cheapest->target_node && *a != cheapest)
	{
		if (!rev)
			rr(a, b);
		else
			rrr(a, b);
	}
	get_index(*a);
	get_index(*b);
}

/* iterates stack to find cheapest flag */
t_stack	*find_cheapest(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

/* finds target node in a to push from b back to a */
void	move_b(t_stack **a, t_stack **b)
{
	prep_push(a, (*b)->target_node, 'a');
	pa(a, b);
}

/* finds cheapest node to move from a to b */
void	move_cheapest_a(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;

	cheapest = find_cheapest(*a);
	if (cheapest->above_median
		&& cheapest->target_node->above_median)
		rotate_index(a, b, cheapest, 0);
	else if (!cheapest->above_median
		&& !cheapest->target_node->above_median)
		rotate_index(a, b, cheapest, 1);
	prep_push(a, cheapest, 'a');
	prep_push(b, cheapest->target_node, 'b');
	pb(b, a);
}

/* sorts according to turk algorithm, see top comment */
void	turk_algorithm(t_stack **a, t_stack **b)
{
	int	len_a;

	len_a = stack_len(*a);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb(b, a);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb(b, a);
	while (len_a-- > 3 && !stack_sorted(*a))
	{
		init_a(*a, *b);
		move_cheapest_a(a, b);
	}
	three_num_sort(a);
	while (*b)
	{
		init_b(*a, *b);
		move_b(a, b);
	}
	get_index(*a);
	put_min_on_top(a);
}
