/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:02:02 by cgray             #+#    #+#             */
/*   Updated: 2023/12/06 17:11:52 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char **av)
{
	char *str;
	int	i = 0;

	if (ac == 2)
	{
		str = av[1];
		while (str[i])
		{
			if (str[i] >= 'a' && str[i] <= 'z')
				str[i] = 219 - str[i]; // have 'a' 97 need 'z'122; x - 97 = 122; x = 219
			else if (str[i] >= 'A' && str[i] <= 'Z')
				str[i] = 155 - str[i]; // have 'A'65 need 'Z'90; x - 65 = 90; x = 155
			write(1, &str[i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
