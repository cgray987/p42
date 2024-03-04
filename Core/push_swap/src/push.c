/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:28:22 by cgray             #+#    #+#             */
/*   Updated: 2024/03/04 17:34:11 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* pushes first element in src and pushes it to the
top of dest */
void	push(t_stack **dest, t_stack **src)
{
	t_stack	*temp;

	if (!src)
		return ;
	temp = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	temp->prev = NULL;
	if (!*dest)
	{
		*dest = temp;
		temp->next = NULL;
	}
	else
	{
		temp->next = *dest;
		temp->next->prev = temp;
		*dest = temp;
	}
}

/* take first b and put into top a */
void	pa(t_stack **a, t_stack **b)
{
	push(a, b);
	ft_printf("pa\n");
}

/* take first a and put into top b */
void	pb(t_stack **b, t_stack **a)
{
	push(b, a);
	ft_printf("pb\n");
}
