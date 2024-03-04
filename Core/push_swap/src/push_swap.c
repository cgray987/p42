/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:22:52 by cgray             #+#    #+#             */
/*   Updated: 2024/03/04 16:54:53 by cgray            ###   ########.fr       */
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

void	enter_stack(t_stack **stack, int *array)
{
	int		i;

	i = 0;
	while (array[i])
	{
		stack_add_back(stack, array[i]);
		i++;
	}
}

int	*get_nums(int ac, char **av)
{
	int	*num_array;
	int	i;

	if (ac == 2)
		num_array = one_argument(av);
	else if (ac > 2)
	{
		i = 0;
		num_array = malloc(sizeof(int) * ac - 1);
		while (av[i + 1])
		{
			if (valid_ps_int(av[i + 1]))
				error_bad_args();
			num_array[i] = ft_atoi(av[i + 1]);
			i++;
		}
		num_array[i] = '\0';
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

	a = NULL;
	b = NULL;
	num_array = get_nums(ac, av);
	if (!num_array)
		return (1);
	enter_stack(&a, num_array);
	printf("stack len %d\n", stack_len(a));
	if (stack_len(a) == 2)
		two_num_sort(&a);
	else if (stack_len(a) == 3)
		three_num_sort(&a);
	else if (stack_len(a) > 3)
		turk_algorithm(&a, &b);
	if (stack_sorted(a))
		ft_printf("stack sorted\n");
	while (a)
	{
		printf("%d\n", a->number);
		a = a->next;
	}

}

/**/
