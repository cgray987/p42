/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:22:37 by cgray             #+#    #+#             */
/*   Updated: 2024/03/05 18:03:22 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/libft/includes/libft.h"
# include <limits.h> // for INT_MAX and INT_MIN

/*
	-number:		the number itself in stack
	-index:			the number's position in stack
	-cost:			set by 'get_cost', represents how many moves
					it will take to sort this number in stack
	-above_median:	set by get_index, tracks if number is above middle
	-cheapest:		set by get_cheapest, tracks if number is cheapest to push
	-*target_node	set by get_target_(a/b), finds best node to push to
 */
typedef struct stack
{
	int				number;
	int				index;
	int				cost;
	int				above_median;
	int				cheapest;
	struct stack	*next;
	struct stack	*target_node;
	struct stack	*prev;
}				t_stack;

/* |---------------argument_checks.c-------------------| */
void	error_bad_args(char **str_nums, int i);
void	error_duplicate(int *num_array);
int		*one_argument(char **av);
int		duplicate_check(int *num_array, int size);
int		valid_ps_int(char *str);
/* |---------------get_stack_values_a.c----------------| */
void	get_index(t_stack *stack);
void	get_cost(t_stack *a, t_stack *b);
void	get_cheapest(t_stack *stack);
void	get_target_a(t_stack *a, t_stack *b);
void	init_a(t_stack *a, t_stack *b);
/* |---------------get_stack_values_b.c----------------| */
void	get_target_b(t_stack *a, t_stack *b);
void	init_b(t_stack *a, t_stack *b);
/* |--------------------push.c-------------------------| */
void	push(t_stack **stack_a, t_stack **stack_b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
/* |--------------------rev_rotate.c-------------------| */
void	rev_rotate(t_stack **stack);
void	rra(t_stack **a);
void	rrb(t_stack **a);
void	rrr(t_stack **a, t_stack **b);
/* |--------------------rotate.c------------------------| */
void	rotate(t_stack **stack);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
/* |--------------------small_cases.c-------------------| */
void	two_num_sort(t_stack **a);
void	three_num_sort(t_stack **a);
int		array_len(int *array);
/* |--------------------stack_utils.c-------------------| */
void	stack_add_back(t_stack **stack, int nbr);
t_stack	*last_stack(t_stack *stack);
t_stack	*stack_new(int num);
void	clear_stack(t_stack **stack);
int		stack_sorted(t_stack *stack);
/* |--------------------stack_utils2.c-------------------| */
void	put_min_on_top(t_stack **a);
void	prep_push(t_stack **stack, t_stack *top, char a_or_b);
int		stack_len(t_stack *stack);
t_stack	*stack_min(t_stack *stack);
t_stack	*stack_max(t_stack *stack);
/* |--------------------swap.c----------------------------| */
void	swap(t_stack **stack);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
/* |--------------------turk_algorithm.c-------------------| */
void	rotate_index(t_stack **a, t_stack **b, t_stack *cheapest, int rev);
t_stack	*find_cheapest(t_stack *stack);
void	move_b(t_stack **a, t_stack **b);
void	move_cheapest_a(t_stack **a, t_stack **b);
void	turk_algorithm(t_stack **a, t_stack **b);
#endif
