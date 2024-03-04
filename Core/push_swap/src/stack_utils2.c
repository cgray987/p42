/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:45:52 by cgray             #+#    #+#             */
/*   Updated: 2024/03/04 14:16:06 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_min_on_top(t_stack **a)
{
	while ((*a)->number != stack_min(*a)->number)
	{
		if (stack_min(*a)->above_median)
			ra(a);
		else
			rra(a);
	}
}

void	prep_push(t_stack **stack, t_stack *top, char a_or_b)
{
	while (*stack != top)
	{
		if (a_or_b == 'a')
		{
			if (top->above_median)
				ra(stack);
			else
				rra(stack);
		}
		else if (a_or_b == 'b')
		{
			if (top->above_median)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

/* returns length of stack */
int	stack_len(t_stack *stack)
{
	int	len;

	if (!stack)
		return (0);
	len = 0;
	while (stack)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}

/* returns minimum number found in stack */
t_stack	*stack_min(t_stack *stack)
{
	int	min;
	t_stack	*min_node;

	min = INT_MAX;
	while (stack)
	{
		if (stack->number < min)
		{
			min = stack->number;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}

/* returns maximum number found in stack */
t_stack	*stack_max(t_stack *stack)
{
	int		max;
	t_stack	*max_node;

	max = INT_MIN;
	while (stack)
	{
		if (stack->number > max)
		{
			max = stack->number;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}
