/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:39:45 by cgray             #+#    #+#             */
/*   Updated: 2023/09/27 16:02:15 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*range;
	int	i;
	int	size;

	if (min >= max)
		return (NULL);
	i = 0;
	size = max - min;
	range = (int *)malloc(sizeof(int) * (size));
	if (range == NULL)
		return (NULL);
	while (max > min)
	{
		range[i] = min;
		i++;
		min++;
	}
	return (range);
}
// #include <stdio.h>
// int	main(void)
// {
// 	int min = 1;
// 	int max = 10;
// 	int i = 0;
// 	int *range;

// 	range = ft_range(min, max);
// 	while (max > min)
// 	{
// 		printf("%d\n", range[i]);
// 		i++;
// 		min++;
// 	}
// }
