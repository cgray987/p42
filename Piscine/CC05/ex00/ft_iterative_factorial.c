/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 20:06:26 by cgray             #+#    #+#             */
/*   Updated: 2023/09/21 21:23:35 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	res;
	int	i;

	i = nb - 1;
	res = 1;
	while (i > 1)
	{
		nb = nb * i;
		i--;
	}
	if (nb == 0 || nb == 1)
		return (1);
	if (nb <= 0)
		return (0);
	return (nb);
}
// #include <stdio.h>
// int	main(void)
// {
// 	int n = 4;
// 	printf("%d factorial = %d\n", n, ft_iterative_factorial(n));
// }
