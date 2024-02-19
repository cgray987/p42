/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:45:52 by cgray             #+#    #+#             */
/*   Updated: 2024/02/19 15:51:15 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
int	stack_min(t_stack *stack)
{
	int	min;

	min = stack->number;
	while (stack)
	{
		if (min > stack->number)
			min = stack->number;
	}
	return (min);
}

/* returns maximum number found in stack */
int	stack_max(t_stack *stack)
{
	int	max;

	max = stack->number;
	while (stack)
	{
		if (max < stack->number)
			max = stack->number;
	}
	return (max);
}
