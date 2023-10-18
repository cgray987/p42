/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 22:15:59 by cgray             #+#    #+#             */
/*   Updated: 2023/09/21 22:53:12 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_fibonacci(int index)
{
	int	f;

	f = 0;
	if (index < 0)
		f = -1;
	if (index == 0)
		f = 0;
	if (index == 1)
		f = 1;
	if (index > 1)
		f = ft_fibonacci(index - 1) + ft_fibonacci(index -2);
	return (f);
}
// #include <stdio.h>
// int	main(void)
// {
// 	int i = 17;
// 	printf("index %d is %d in sequence\n", i, ft_fibonacci(i));
// }
