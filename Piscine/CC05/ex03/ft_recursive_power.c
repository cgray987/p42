/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 21:56:12 by cgray             #+#    #+#             */
/*   Updated: 2023/09/21 22:15:15 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	int	res;

	res = nb;
	if (power > 1)
		return (nb * ft_recursive_power(nb, power - 1));
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
// 	printf("%d to the power of %d = %d\n", n, p, ft_recursive_power(n, p));
// }
