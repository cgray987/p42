/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:34:04 by cgray             #+#    #+#             */
/*   Updated: 2024/03/06 13:43:00 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/* all of these functions are silly. I should have made one error function
that can handle all error cases, instead I'm lazy and had space for extra
functions, but not extra lines in the functions which call them ¯\_(ツ)_/¯ */

void	error_int(void)
{
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
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
