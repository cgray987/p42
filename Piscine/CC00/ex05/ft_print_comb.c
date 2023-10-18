/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 18:53:03 by cgray             #+#    #+#             */
/*   Updated: 2023/09/08 11:13:58 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
declare i,j,k increment variables
init i as ASCII 0
ijk, ijk, ijk, ... etc
first digit will go from 0:7
second digit will go from 1:8, increment from i
third digit will go from 2:9, increment from j
writes ijk, k will be first iteration
after writing digit, if i, j, or k,
equals 7, 8, or 9, then delineate
increment k
increment j
increment i
*/

void	ft_print_comb(void)
{
	int	i;
	int	j;
	int	k;

	i = '0';
	while (i <= '7')
	{
		j = i + 1;
		while (j <= '8')
		{
			k = j + 1;
			while (k <= '9')
			{
				write (1, &i, 1);
				write (1, &j, 1);
				write (1, &k, 1);
				if (i != '7' || j != '8' || k != '9')
					write (1, ", ", 2);
				k = k + 1;
			}
			j = j + 1;
		}
		i = i + 1;
	}
}

//main to be commented out to submit project
/*
int main(void)
{
    ft_print_comb();
    return 0;
}
*/
