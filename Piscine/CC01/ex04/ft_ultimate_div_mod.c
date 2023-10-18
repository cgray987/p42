/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 19:42:28 by cgray             #+#    #+#             */
/*   Updated: 2023/09/10 19:49:30 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	t;

	t = *a;
	*a = t / *b;
	*b = t % *b;
}

/*
int	main(void)
{
	int	a;
	int	b;

	a = 42;
	b = 4;
	printf("before div: %d %d\n", a, b);
	ft_ultimate_div_mod(&a, &b);
	printf("after div: %d %d\n", a, b);
}
*/
