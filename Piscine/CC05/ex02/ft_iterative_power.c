/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 21:44:50 by cgray             #+#    #+#             */
/*   Updated: 2023/09/21 21:55:51 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	res;
	int	i;

	res = 1;
	i = power;
	while (i > 0)
	{
		res *= nb;
		i--;
	}
	if (power == 0)
		return (1);
	if (power < 0)
		return (0);
	return (res);
}
// #include <stdio.h>
// int	main(void)
// {
// 	int n = 4;
// 	int p = 4;
// 	printf("%d to the power of %d = %d\n", n, p, ft_iterative_power(n, p));
// }
