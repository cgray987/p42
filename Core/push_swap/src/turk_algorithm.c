/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:47:30 by cgray             #+#    #+#             */
/*   Updated: 2024/02/21 15:19:31 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/* Adapted from https://medium.com/@ayogun/push-swap-c1f5d2d41e97

0)	initialize variables
1)	Push 2 nums from top of stack a into b
2)	Find cheapest number
	-calculate num of operations it takes to push into correct position in b
	-count every number in a to find cheapest push
3)	repeat until 3 nums left in a
4)	sort a
5)	check top number in b to see where it fits into a
6)	if needed, rotate a until it is ready for top b number
7)	repeat until stack b is empty
8)	rotate a if needed to sort
*/

void	find_and_push(t_stack **a, t_stack **b)
{

}

void	turk_algorithm(t_stack **a, t_stack **b)
{
	pb(a, b);
	pb(a, b);
	find_and_push(a, b);
}
