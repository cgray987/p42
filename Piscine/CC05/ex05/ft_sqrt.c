/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 22:27:57 by cgray             #+#    #+#             */
/*   Updated: 2023/09/27 15:35:56 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	res;

	res = 2;
	if (nb <= 0)
		return (0);
	if (nb == 1)
		return (1);
	if (nb >= 2)
	{
		while (res * res <= nb)
		{
			if (res * res == nb)
				return (res);
			res++;
		}
	}
	return (0);
}
// #include <stdio.h>
// int	main(void)
// {
// 	int i = 256;
// 	printf("sqrt of %d is %d\n", i, ft_sqrt(i));
// }
