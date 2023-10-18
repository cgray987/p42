/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:25:35 by cgray             #+#    #+#             */
/*   Updated: 2023/09/13 16:34:52 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	r_i;
	int	rev;

	i = 0;
	r_i = size - 1;
	while (i < (size / 2))
	{
		rev = tab[i];
		tab[i] = tab[r_i];
		tab[r_i] = rev;
		i++;
		r_i--;
	}
}
// int	main()
// {
// 	int arr[] = {1, 2, 3, 4};
// 	int i;
// 	int length = sizeof(arr) / sizeof(arr[0]);
// 	for(i = 0; i < length; i++)
// 		printf("%d ", arr[i]);
// 	printf("\n");
// 	ft_rev_int_tab(arr, length);
// 	for(i = 0; i < length; i++)
// 		printf("%d ", arr[i]);
// 	printf("\n");
// }
