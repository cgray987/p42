/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:19:42 by cgray             #+#    #+#             */
/*   Updated: 2023/09/27 18:38:17 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	s;

	s = 0;
	while (src[s] != '\0' && s < size - 1)
	{
		dest[s] = src[s];
		s++;
	}
	dest[s] = '\0';
	return (s);
}
// #include <stdio.h>
// int main(void)
// {
// 	char a[] = "test";
// 	char b[] = "123456789";
// 	printf("size: %d\n cpy b into a: %s\n ", ft_strlcpy(a, b, 6), a);
// }
