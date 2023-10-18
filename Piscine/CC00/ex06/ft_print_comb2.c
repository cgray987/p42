/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:12:43 by cgray             #+#    #+#             */
/*   Updated: 2023/09/28 12:31:29 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_char(char c)
{
	write(1, &c, 1);
}

void	ft_int_char(int c)
{
	char tens;
	char ones;

	tens = 0;
	ones = 0;
	if (c < 10)
	{
		ft_print_char('0');
		ft_print_char(c + '0');
	}
	else
	{
		tens = c / 10 + '0';
		ones = c % 10 + '0';
		ft_print_char(tens);
		ft_print_char(ones);
	}
}

void	ft_print_comb2(void)
{
	int	i;
	int	j;

	i = 0;
	j= 0;
	while (i <= 99)
	{
		j = i + 1;
		while (j <= 99)
		{
			ft_int_char(i);
			ft_print_char(' ');
			ft_int_char(j);
			if (i < 98)
			{
				ft_print_char(',');
				ft_print_char(' ');
			}
			j++;
		}
		i++;
	}
}
// #include <stdlib.h>
// int	main(void)
// {
// 	ft_print_comb2();
// }
