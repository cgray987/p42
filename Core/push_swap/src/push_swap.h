/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:22:37 by cgray             #+#    #+#             */
/*   Updated: 2024/02/21 14:45:33 by cgray            ###   ########.fr       */
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
void	pb(t_stack **a, t_stack **b);
/* |--------------------swap.c-------------------| */
void	swap(t_stack **stack);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
/* |--------------------rotate.c-------------------| */
void	rotate(t_stack **stack);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
/* |--------------------rev_rotate.c-------------------| */
void	rev_rotate(t_stack **stack);
void	rra(t_stack **a);
void	rrb(t_stack **a);
void	rrr(t_stack **a, t_stack **b);
/* |--------------------stack_utils.c-------------------| */
void	stack_add_back(t_stack **stack, t_stack *new);
t_stack	*last_stack(t_stack *stack);
t_stack	*stack_new(int num);
void	clear_stack(t_stack **stack);
int		stack_sorted(t_stack *stack);
/* |--------------------stack_utils2.c-------------------| */
int		stack_len(t_stack *stack);
int		stack_min(t_stack *stack);
int		stack_max(t_stack *stack);
/* |--------------------small_cases.c-------------------| */
void	two_num_sort(t_stack **a);
void	three_num_sort(t_stack **a);
/* |--------------------small_cases.c-------------------| */
int		*one_argument(char **av);
int		duplicate_check(int *num_array);
int		valid_ps_int(char *str);
void	error_bad_args(void);


#endif
