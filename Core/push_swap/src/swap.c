/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:42:17 by cgray             #+#    #+#             */
/*   Updated: 2024/02/16 13:52:04 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* swaps first two elements in stack */
void	swap(t_stack **stack)
{
	int	temp;

	temp = *stack->number;
	(*stack)->number = ((*stack)->next)->number;
	((*stack)->next)->number = temp;
}

/* swaps first two elements in stack a */
void	sa(t_stack **a)
{
	swap(a);
	ft_printf("sa\n");
}

/* swaps first two elements in stack b */
void	sb(t_stack **b)
{
	swap(b);
	ft_printf("sb\n");
}

/* swaps first two elements in both stacks */
void	ss(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
	ft_printf("ss\n");
}
