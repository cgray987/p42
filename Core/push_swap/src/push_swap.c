/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:22:52 by cgray             #+#    #+#             */
/*   Updated: 2024/03/06 13:00:28 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* function to free stack memory */
void	free_stack(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*current;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		temp = current->next;
		current->number = 0;
		free(current);
		current = temp;
	}
	*stack = NULL;
}

/* takes int array and places into stack */
void	enter_stack(t_stack **stack, int *array)
{
	int		i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
	{
		stack_add_back(stack, array[i]);
		i++;
	}
}

/* puts numbers into int array from arguments */
int	*get_nums(int ac, char **av)
{
	int	*num_array;
	int	i;

	if (ac == 2)
		num_array = one_argument(av);
	else if (ac > 2)
	{
		i = 0;
		num_array = malloc(sizeof(int) * (ac - 1) + 4);
		if (!num_array)
			return (NULL);
		while (av[i + 1])
		{
			if (valid_ps_int(av[i + 1]))
				error_duplicate(num_array);
			num_array[i] = ft_atoi(av[i + 1]);
			i++;
		}
		num_array[i - 1] = '\0';
	}
	if (duplicate_check(num_array, ac - 1) && ac > 2)
		error_duplicate(num_array);
	return (num_array);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		*num_array;
	int		stack_size;

	a = NULL;
	b = NULL;
	num_array = get_nums(ac, av);
	enter_stack(&a, num_array);
	stack_size = stack_len(a);
	if (stack_size == 2)
		two_num_sort(&a);
	else if (stack_size == 3)
		three_num_sort(&a);
	else if (stack_size > 3)
		turk_algorithm(&a, &b);
	free(num_array);
	free_stack(&a);
	free_stack(&b);
}

/**/
