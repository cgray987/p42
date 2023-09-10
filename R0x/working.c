/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   working.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 13:00:51 by cgray             #+#    #+#             */
/*   Updated: 2023/09/10 17:30:10 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	rush(int a, int b)
{
	int i;
	int j;

	i = 1;
	j = 1;
	while (j <= b)
	{
		while (i <= a)
		{
			if (i == 1 && j == 1 || i == a && j == 1)
			{
				ft_putchar ('A');
			}
			else if (i == 1 && j == b || i == a && j == b)
			{
				ft_putchar('C');
			}
			else if (i == 1 || j == 1 || i == a || j == b)
			{
				ft_putchar ('B');
			}
			else
			{
				ft_putchar (32);
			}
			i++;
		}
			j++;
			i = 1;
			ft_putchar ('\n');
		}
	}

int	main(void)
{
	rush(1, 1);
	return (0);
}
