/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:34:04 by cgray             #+#    #+#             */
/*   Updated: 2024/03/07 13:46:33 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/* all of these functions are silly. I should have made one error function
that can handle all error cases, instead I'm lazy and had space for extra
functions, but not extra lines in the functions which call them ¯\_(ツ)_/¯ */

/* if temp doesn't fit inside int return error, otherwise return int */
int	error_int(long temp)
{
	if (temp > INT_MAX || temp < INT_MIN)
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		return ((int)temp);
	}
}

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

void	error_one_arg(char **str_nums, int i, int *num_array)
{
	while (str_nums[i])
	{
		free(str_nums[i++]);
	}
	free(str_nums);
	free(num_array);
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}
