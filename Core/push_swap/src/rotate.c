/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:56:17 by cgray             #+#    #+#             */
/*   Updated: 2024/02/19 15:06:33 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* shift all elements up one, first becoming last */
void	rotate(t_stack **stack)
{
	t_stack	*current;
	t_stack	*last;

	current = *stack;
	last = last_stack(*stack);
	*stack = (*stack)->next;
	current->next = NULL;
	last->next = current;
}

/* shift all elements in a up one */
void	ra(t_stack **a)
{
	rotate(a);
	ft_printf("ra\n");
}

/* shift all elements in b up one */
void	rb(t_stack **b)
{
	rotate(b);
	ft_printf("rb\n");
}

/* shift all elements in both stacks up one */
void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}
