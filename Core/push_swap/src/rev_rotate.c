/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:31:54 by cgray             #+#    #+#             */
/*   Updated: 2024/02/19 14:22:58 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* shift all elements in stack down,
last element becoming the first.
	-go to second to last element, store it
	-detach last element
	-move last element to top of orig stack
	-update stack to point to new head*/
void	rev_rotate(t_stack **stack)
{
	t_stack	*second_last;
	t_stack	*last;

	second_last = *stack;
	if (!second_last->next || !second_last)
		return ;
	while ((second_last->next)->next)
		second_last = second_last->next;
	last = second_last->next;
	second_last->next = NULL;
	last->next = *stack;
	*stack = last;
}

/* reverse rotate stack a */
void	rra(t_stack **a)
{
	rev_rotate(a);
	ft_printf("rra\n");
}

/* reverse rotate stack b */
void	rrb(t_stack **b)
{
	rev_rotate(b);
	ft_printf("rrb\n");
}

/* reverse rotate stack a and b */
void	rrr(t_stack **a, t_stack **b)
{
	rev_rotate(a);
	rev_rotate(b);
	ft_printf("rrr\n");
}
