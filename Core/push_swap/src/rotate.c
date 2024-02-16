/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:56:17 by cgray             #+#    #+#             */
/*   Updated: 2024/02/16 14:11:52 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*last_stack(t_stack *stack)
{
	while(stack->next)
		stack = stack->next;
	return (stack);
}

/* shift all elements up one, first becoming last */
void	rotate(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*current;

	temp = *stack;
	current = last_stack(*stack);
	*stack = (*stack)->next;
	temp->next = NULL;
	current->next = temp;
}

/* shift all elements in a up one */
void	ra(t_stack **a)
{
	rotate(*a);
	ft_printf("ra\n");
}

/* shift all elements in b up one */
void	rb(t_stack **b)
{
	rotate(*b);
	ft_printf("rb\n");
}

/* shift all elements in both stacks up one */
void	rr(t_stack **a, t_stack **b)
{
	rotate(*a);
	rotate(*b);
	ft_printf("rr\n");
}
