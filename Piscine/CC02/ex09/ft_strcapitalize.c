/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 18:34:28 by cgray             #+#    #+#             */
/*   Updated: 2023/09/28 13:28:47 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	capital;

	i = 0;
	capital = 1;
	while (str[i] != '\0')
	{
		if (capital == 1 && str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] -= 32;
			capital = 0;
		}
		else
		{
			capital = 0;
		}
		if (str[i] >= ' ' && str[i] <= '/')
			capital = 1;
		i++;
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
	}
	return (str);
}
#include <stdio.h>
int	main(void)
{
	char s[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
	printf("%s\n", ft_strcapitalize(s));
}
