/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:57:03 by cgray             #+#    #+#             */
/*   Updated: 2023/09/18 17:20:59 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] < 'a' || str[i] > 'z'))
			return (0);
		i++;
	}
	return (1);
}
// #include <stdio.h>
// int	main(void)
// {
// 	printf("return: %d\n", ft_str_is_lowercase("TEST"));
// 	printf("return: %d\n", ft_str_is_lowercase("test"));
// 	printf("return: %d\n", ft_str_is_lowercase("hello world"));
// 	printf("return: %d\n", ft_str_is_lowercase("HelloWorld"));
// 	printf("return: %d\n", ft_str_is_lowercase("abc123"));
// 	printf("return: %d\n", ft_str_is_lowercase("4242424242"));
// 	printf("return: %d\n", ft_str_is_lowercase("!@#$^#"));
// 	printf("return: %d\n", ft_str_is_lowercase(" "));
// 	printf("return: %d\n", ft_str_is_lowercase("\0"));
// }
