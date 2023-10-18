/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:06:11 by cgray             #+#    #+#             */
/*   Updated: 2023/09/24 15:16:05 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	d;
	unsigned int	s;

	d = 0;
	s = 0;
	while (dest[d] != '\0')
		d++;
	if (size < 1)
		return (d);
	while (src[s] != '\0' && s < size)
	{
		dest[d + s] = src[s];
		s++;
	}
	dest[d + s] = '\0';
	return (d + s);
}
// #include <stdio.h>
// int main(void)
// {
// 	char a[] = "test";
// 	char b[] = "12356";
// 	char	c = ft_strlcat(a,b,6);
// 	printf("size: %d\n cat a: %s\n ", c, a);
// }
