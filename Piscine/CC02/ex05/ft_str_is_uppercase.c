/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:57:03 by cgray             #+#    #+#             */
/*   Updated: 2023/09/18 17:23:47 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] < 'A' || str[i] > 'Z'))
			return (0);
		i++;
	}
	return (1);
}
// #include <stdio.h>
// int	main(void)
// {
// 	printf("return: %d\n", ft_str_is_uppercase("TEST"));
// 	printf("return: %d\n", ft_str_is_uppercase("test"));
// 	printf("return: %d\n", ft_str_is_uppercase("hello world"));
// 	printf("return: %d\n", ft_str_is_uppercase("HelloWorld"));
// 	printf("return: %d\n", ft_str_is_uppercase("abc123"));
// 	printf("return: %d\n", ft_str_is_uppercase("4242424242"));
// 	printf("return: %d\n", ft_str_is_uppercase("!@#$^#"));
// 	printf("return: %d\n", ft_str_is_uppercase(" "));
// 	printf("return: %d\n", ft_str_is_uppercase("\0"));
// }
