/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:04:47 by cgray             #+#    #+#             */
/*   Updated: 2024/03/06 17:07:25 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Adds the node at the end of the list 'stack'*/
void	stack_add_back(t_stack **stack, int nbr)
{
	t_stack	*node;
	t_stack	*last_node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack));
	if (!node)
		return ;
	node->next = NULL;
	node->number = nbr;
	node->cheapest = 0;
	if (!(*stack))
	{
		*stack = node;
		node->prev = NULL;
		return ;
	}
	else
	{
		last_node = last_stack(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

/* goes to last node in stack */
t_stack	*last_stack(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

/* creates a new stack with the given number as node */
t_stack	*stack_new(int num)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->number = num;
	new_node->next = NULL;
	return (new_node);
}

/* removes all nodes from a stack and sets to NULL */
void	clear_stack(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*current;

	if (!*stack || !stack)
		return ;
	current = *stack;
	while (current)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
	*stack = NULL;
}

/* returns 1 if the stack is sorted from smallest to largest */
int	stack_sorted(t_stack *stack)
{
	int	temp;

	if (!stack)
		return (0);
	temp = stack->number;
	while (stack)
	{
		if (temp > stack->number)
			return (0);
		temp = stack->number;
		stack = stack->next;
	}
	return (1);
}
