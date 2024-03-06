/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_cases.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:12:20 by cgray             #+#    #+#             */
/*   Updated: 2024/03/06 15:55:53 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	array_len(int *array)
{
	int	i;

	i = 0;
	while (*array)
	{
		array++;
		i++;
	}
	return (i);
}

/* sort stack with two numbers (one rotation) */
void	two_num_sort(t_stack **a)
{
	if (!stack_sorted(*a))
		return ;
	ra(a);
}

/* simple alg for three numbers
case 1: 3 2 1
case 2: 2 1 3
case 3: 3 1 2
case 4: 1 3 2
case 5: 2 3 1 */
void	three_num_sort(t_stack **stack)
{
	int	a;
	int	b;
	int	c;

	a = (*stack)->number;
	b = (*stack)->next->number;
	c = (*stack)->next->next->number;
	if (a > b && b > c && a > c)
	{
		ra(stack);
		sa(stack);
	}
	else if (a > b && b < c && a < c)
		sa(stack);
	else if (a > b && b < c && a > c)
		ra(stack);
	else if (a < b && b > c && a < c)
	{
		sa(stack);
		ra(stack);
	}
	else if (a < b && b > c && a > c)
		rra(stack);
}
