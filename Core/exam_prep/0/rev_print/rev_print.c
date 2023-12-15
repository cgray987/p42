/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:57:23 by cgray             #+#    #+#             */
/*   Updated: 2023/12/14 18:01:08 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include <unistd.h>

int	main(int ac, char **av)
{
	char	*str;
	int		i = 0;

	if (ac == 2)
	{
		str = av[1];
		while (str[i])
			++i;
		i--;
		while (i >= 0)
		{
			write(1, &str[i], 1);
			i--;
		}
	}
	write(1, "\n", 1);
}
