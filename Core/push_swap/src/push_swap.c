/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:22:52 by cgray             #+#    #+#             */
/*   Updated: 2024/02/19 18:08:13 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*enter_stack(int *array)
{
	int		i;
	t_stack	*stack;

	i = 0;
	stack = NULL;
	while (array[i])
	{
		stack_add_back(&stack, stack_new(array[i++]));
	}
	return (stack);
}

int	*one_argument(char **av)
{
	char	**str_nums;
	int		*num_array;
	int		i;

	i = 0;
	num_array = malloc(ft_count_words(av[1], ' ') * sizeof(int));
	str_nums = ft_split(av[1], ' ');
	while (str_nums[i])
	{
		num_array[i] = ft_atoi(str_nums[i]);
		free(str_nums[i]);
		i++;
	}
	num_array[i] = '\0';
	free(str_nums);
	return (num_array);
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
			num_array[i - 1] = ft_atoi(av[i]);
			i++;
		}
		num_array[i - 1] = '\0';
	}
	return (num_array);
}

int	main(int ac, char **av)
{
	int	*num_array;
	t_stack	*a;

	num_array = get_nums(ac, av);
	//need integer check
	//need duplicate check
	a = enter_stack(num_array);
	if (stack_len(a) == 2)
		two_num_sort(&a);
	else if (stack_len(a) == 3)
		three_num_sort(&a);
	if (stack_sorted(a))
		ft_printf("stack sorted\n");
	while (a)
	{
		ft_printf("%d\n", a->number);
		a = a->next;
	}
}
