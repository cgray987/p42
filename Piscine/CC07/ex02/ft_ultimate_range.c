/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 16:03:08 by cgray             #+#    #+#             */
/*   Updated: 2023/09/27 16:31:14 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	size;
	int	*res;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	size = max - min;
	res = (int *)malloc(sizeof(int) * (size));
	i = 0;
	*range = res;
	while (max > min)
	{
		res[i] = min;
		i++;
		min++;
	}
	return (i);
}
// #include <stdio.h>
// int	main(void)
// {
// 	int min = 1;
// 	int max = -10;
// 	int i = 0;
// 	int *range;
// 	int size;
// 	size = ft_ultimate_range(&range, min, max);
// 	while (i < size)
// 	{
// 		printf("%d\n", range[i]);
// 		i++;
// 	}
// 	printf("array size: %d\n", ft_ultimate_range(&range, min, max));
// }
