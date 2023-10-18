/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 16:08:52 by cgray             #+#    #+#             */
/*   Updated: 2023/09/14 17:59:59 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
// #include <stdio.h>

// int	main(void)
// {
// 	char	dest[] = "hello";
// 	char	src[] = "Hello test";

// 	printf("dest = %s\n", dest);
// 	ft_strcpy(dest, src);
// 	printf("dest = %s\n", dest);
// }
