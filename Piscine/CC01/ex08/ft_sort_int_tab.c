/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:35:38 by cgray             #+#    #+#             */
/*   Updated: 2023/09/13 17:09:08 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	rev;
	int	next;

	i = 0;
	while (i < size)
	{
		next = i + 1;
		while (next < size)
		{
			if (tab[i] > tab[next])
			{
				rev = tab[next];
				tab[next] = tab[i];
				tab[i] = rev;
			}
			else
				next++;
		}
		i++;
	}
}
// int	main(void)
// {
// 	int	arr[] = {42, 34, 64, 92, 2, 14};
// 	int	i = 0;
// 	int	size = sizeof(arr)/sizeof(arr[0]);

// 	while (i < size)
// 	{
// 		printf("%d ", arr[i]);
// 		i++;
// 	}
// 	i = 0;
// 	ft_sort_int_tab(arr, size);
// 	printf("\n");
// 	while (i < size)
// 	{
// 		printf("%d ", arr[i]);
// 		i++;
// 	}

// }
