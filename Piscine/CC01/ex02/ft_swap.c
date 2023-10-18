/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 19:17:15 by cgray             #+#    #+#             */
/*   Updated: 2023/09/10 19:30:44 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_swap(int *a, int*b)
{
	int	t;

	t = *a;
	*a = *b;
	*b = t;
}

/*
int	main(void)
{
	int	a;
	int	b;

	a = 1;
	b = 2;

	printf ("before swap\na=%d, b=%d\n", a, b);
	ft_swap(&a, &b);
	printf ("after swap\na=%d, b=%d\n", a, b);
}
*/
