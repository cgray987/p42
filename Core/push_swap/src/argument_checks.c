/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_checks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:42:04 by cgray             #+#    #+#             */
/*   Updated: 2024/03/05 18:44:06 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* prints error and exits program
frees rest of **str_nums*/
void	error_bad_args(char **str_nums, int i)
{
	while (str_nums[i])
	{
		free(str_nums[i++]);
	}
	free(str_nums);
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}

void	error_duplicate(int *num_array)
{
	free(num_array);
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}

/* case that av is entered as one string */
int	*one_argument(char **av)
{
	char	**str_nums;
	int		*num_array;
	int		i;
	int		size;

	i = 0;
	size = ft_count_words(av[1], ' ');
	num_array = malloc(size * sizeof(int));
	if (!num_array)
		return (NULL);
	str_nums = ft_split(av[1], ' ');
	while (str_nums[i])
	{
		if (valid_ps_int(str_nums[i]))
		{
			free(num_array);
			error_bad_args(str_nums, i);
		}
		num_array[i] = ft_atoi(str_nums[i]);
		free(str_nums[i]);
		i++;
	}
	free(str_nums);
	num_array[i - 1] = '\0';
	if (duplicate_check(num_array, size))
		error_duplicate(num_array);
	return (num_array);
}

/* iterates thru array, returning 1 if duplicate found */
int	duplicate_check(int *num_array, int size)
{
	int	i;
	int	temp;

	if (!num_array || size < 2)
		return (1);
	i = 0;
	temp = 0;
	while (i < size - 1)
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
