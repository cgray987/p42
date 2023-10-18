/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:37:21 by cgray             #+#    #+#             */
/*   Updated: 2023/09/28 13:04:16 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_char(char c)
{
	write(1, &c, 1);
}

void	comb_n(int start, int places)
{
	int	i;

	if (places == 0)
	{
		ft_print_char(',');
		ft_print_char(' ');
		return ;
	}
	i = start + 1;
	while (i < 10)
	{
		ft_print_char(start + '0');
		ft_print_char(i + '0');
		comb_n(i, places - 1);
		i++;
	}
}

void	ft_print_combn(int n)
{
	comb_n(0, n);
}

int	main(void)
{
	ft_print_combn(2);
}
