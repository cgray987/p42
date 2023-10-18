/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:31:23 by cgray             #+#    #+#             */
/*   Updated: 2023/09/21 18:47:45 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	putchar(char c)
{
	write(1, &c, 1);
}

void	print(char *str)
{
	while (*str != '\0')
	{
		putchar(*str);
		str++;
	}
}

int	main(int argc, char **argv)
{
	int	i;

	i = argc -1;
	while (i > 0)
	{
		print(argv[i]);
		write(1, "\n", 1);
		i--;
	}
	return (0);
}
