/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:22:52 by cgray             #+#    #+#             */
/*   Updated: 2024/02/21 15:08:33 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* iterates through tab, freeing each element and the whole tab */
void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

t_stack	*enter_stack(int *array)
{
	int		i;
	t_stack	*stack;

	i = 0;
	stack = NULL;
	while (array[i])
		stack_add_back(&stack, stack_new(array[i++]));
	return (stack);
}

int	*get_nums(int ac, char **av)
{
	int	*num_array;
	int	i;

	if (ac == 2)
		num_array = one_argument(av);
	else if (ac > 2)
	{
		i = 1;
		num_array = malloc(sizeof(int) * ac - 1);
		while (av[i])
		{
			if (valid_ps_int(av[i]))
				error_bad_args();
			num_array[i - 1] = ft_atoi(av[i]);
			i++;
		}
		num_array[i - 1] = '\0';
	}
	if (duplicate_check(num_array))
		error_bad_args();
	return (num_array);
}

int	main(int ac, char **av)
{
	int	*num_array;
	t_stack	*a;
	t_stack	*b;

	num_array = get_nums(ac, av);
	if (!num_array)
		return (1);
	a = enter_stack(num_array);
	if (stack_len(a) == 2)
		two_num_sort(&a);
	else if (stack_len(a) == 3)
		three_num_sort(&a);
	// else
	// 	turk_algorithm(&a, &b);
	if (stack_sorted(a))
		ft_printf("stack sorted\n");
	while (a)
	{
		ft_printf("%d\n", a->number);
		a = a->next;
	}
}
