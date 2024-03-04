/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_checks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:42:04 by cgray             #+#    #+#             */
/*   Updated: 2024/03/04 17:10:20 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* prints error and exits program */
void	error_bad_args(void)
{
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}

/* case that av is entered as one string */
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
		if (valid_ps_int(str_nums[i]))
			error_bad_args();
		num_array[i] = ft_atoi(str_nums[i]);
		free(str_nums[i]);
		printf("i:%d - %d\n", i, num_array[i]);
		i++;
	}
	num_array[i] = '\0';
	// free(str_nums);
	return (num_array);
}

/* iterates thru array, returning 1 if duplicate found */
int	duplicate_check(int *num_array)
{
	int	i;
	int	temp;

	i = 0;
	while (num_array[i + 1])
	{
		temp = num_array[i];
		if (temp == num_array[i + 1])
			return (1);
		i++;
	}
	return (0);
}

/* checks that arguments are a valid int
(can contain '-' for negative nums) */
int	valid_ps_int(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			i++;
		else
			return (1);
	}
	return (0);
}

// /* iterates through string checking if  */
// int	args_valid(char *str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i])
// 	{
// 		if (valid_ps_int(str))
// 			i++;
// 		else
// 			return (0);
// 	}
// 	return (1);
// }
