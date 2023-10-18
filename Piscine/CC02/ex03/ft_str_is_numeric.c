/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:57:03 by cgray             #+#    #+#             */
/*   Updated: 2023/09/18 17:21:02 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] < '0' || str[i] > '9'))
			return (0);
		i++;
	}
	return (1);
}
// #include <stdio.h>
// int	main(void)
// {
// 	printf("return: %d\n", ft_str_is_numeric("TEST"));
// 	printf("return: %d\n", ft_str_is_numeric("hello world"));
// 	printf("return: %d\n", ft_str_is_numeric("HelloWorld"));
// 	printf("return: %d\n", ft_str_is_numeric("abc123"));
// 	printf("return: %d\n", ft_str_is_numeric("4242424242"));
// 	printf("return: %d\n", ft_str_is_numeric("!@#$^#"));
// 	printf("return: %d\n", ft_str_is_numeric(" "));
// 	printf("return: %d\n", ft_str_is_numeric("\0"));
// }
