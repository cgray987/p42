/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:57:03 by cgray             #+#    #+#             */
/*   Updated: 2023/09/18 19:25:30 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] < ' ' || str[i] > '~'))
			return (0);
		i++;
	}
	return (1);
}
// #include <stdio.h>
// int	main(void)
// {
// 	printf("return: %d\n", ft_str_is_printable("TEST"));
// 	printf("return: %d\n", ft_str_is_printable("test"));
// 	printf("return: %d\n", ft_str_is_printable("hello world"));
// 	printf("return: %d\n", ft_str_is_printable("HelloWorld"));
// 	printf("return: %d\n", ft_str_is_printable("abc123"));
// 	printf("return: %d\n", ft_str_is_printable("4242424242"));
// 	printf("return: %d\n", ft_str_is_printable("!@#$^#~"));
// 	printf("return: %d\n", ft_str_is_printable(" "));
// 	printf("return: %d\n", ft_str_is_printable("\n"));
// 	printf("return: %d\n", ft_str_is_printable("\0"));
// }
