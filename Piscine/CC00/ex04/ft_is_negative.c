/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 18:30:17 by cgray             #+#    #+#             */
/*   Updated: 2023/09/08 11:01:23 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

//if n is positive write "P", else write "N"
void	ft_is_negative(int n)
{
	if (n >= 0)
	{
		write(1, "P", 1);
	}
	else
	{
		write(1, "N", 1);
	}
}
/*/ main to be commented out before submission
int main(void)
{
    ft_is_negative(-42);
    ft_is_negative(0);
    ft_is_negative(42);
    return 0;
}
*/
