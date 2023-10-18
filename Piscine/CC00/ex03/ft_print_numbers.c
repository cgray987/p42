/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 17:01:11 by cgray             #+#    #+#             */
/*   Updated: 2023/09/08 10:58:24 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
// x will be displayed; i will iterate thru loop
//init x = 0; i = 0
// run while 0<=x<=9
//display x and iterate+1

void	ft_print_numbers(void)
{
	char	x;

	x = '0';
	while (x >= '0' && x <= '9')
	{
		write (1, &x, 1);
		x = x + 1;
	}
}
/*/ main function to be commented out to submit
int main(void)
{
    ft_print_numbers();
    return 0;
}
*/
