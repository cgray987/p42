/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:22:37 by cgray             #+#    #+#             */
/*   Updated: 2024/02/16 15:04:23 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/libft/includes/libft.h"
# include <limits.h>

typedef struct stack
{
	struct stack	*next;
	int				number;
}				t_stack;

/* |--------------------push.c-------------------| */
void	push(t_stack **stack_a, t_stack **stack_b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack**b);
/* |--------------------swap.c-------------------| */
void	swap(t_stack **stack);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
/* |--------------------rotate.c-------------------| */
t_stack	*last_stack(t_stack *stack);
void	rotate(t_stack **stack);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
/* |--------------------rev_rotate.c-------------------| */
void	rev_rotate(t_stack **stack);
void	rra(t_stack **a);
void	rrb(t_stack **a);
void	rrr(t_stack **a, t_stack **b);



#endif
