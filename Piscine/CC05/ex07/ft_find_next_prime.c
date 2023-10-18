/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 22:40:33 by cgray             #+#    #+#             */
/*   Updated: 2023/09/24 15:28:17 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;

	i = 5;
	if (nb == 2 || nb == 3)
		return (1);
	if (nb <= 1 || nb % 2 == 0 || nb % 3 == 0)
		return (0);
	while (i * i <= nb)
	{
		if (nb % i == 0 || nb % (i + 2) == 0)
			return (0);
		i += 6;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	int	prime;
	int	find;

	prime = nb;
	find = 1;
	if (nb <= 1)
		return (2);
	while (find != 0)
	{
		if (ft_is_prime(prime) == 1)
		{
			find = 0;
			return (prime);
		}
		prime++;
	}
	return (0);
}
// #include <stdio.h>
// int	main(void)
// {
// 	int i = 1000;
// 	printf("next prime to %d is %d\n", i, ft_find_next_prime(i));
// }
