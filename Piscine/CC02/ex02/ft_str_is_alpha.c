/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:57:03 by cgray             #+#    #+#             */
/*   Updated: 2023/09/18 17:21:06 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
			return (0);
		i++;
	}
	return (1);
}
// #include <stdio.h>
// int	main(void)
// {
// 	printf("return: %d\n", ft_str_is_alpha("TEST"));
// 	printf("return: %d\n", ft_str_is_alpha("hello world"));
// 	printf("return: %d\n", ft_str_is_alpha("HelloWorld"));
// 	printf("return: %d\n", ft_str_is_alpha("abc123"));
// 	printf("return: %d\n", ft_str_is_alpha("4242424242"));
// 	printf("return: %d\n", ft_str_is_alpha("!@#$^#"));
// 	printf("return: %d\n", ft_str_is_alpha(" "));
// 	printf("return: %d\n", ft_str_is_alpha("\0"));
// }
