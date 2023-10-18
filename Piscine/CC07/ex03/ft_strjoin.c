/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 16:44:50 by cgray             #+#    #+#             */
/*   Updated: 2023/09/27 18:13:16 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	char	*res;

	if (size == 0)
	{
		res = malloc(sizeof(char));
		*res = 0;
		return (res);
	}
	res = malloc(sizeof(char) * (sizeof(strs)));
	if (!(res))
		return (NULL);
	*res = 0;
	i = 0;
	while (i < size)
	{
		ft_strcat(res, strs[i]);
		if (i < size -1)
			ft_strcat(res, sep);
		i++;
	}
	return (res);
}
// #include <stdio.h>
// int	main(void)
// {
// 	char *d[4];
// 	char *s[2];
// 	d[0] = "-";
// 	d[1] = " ";
// 	d[2] = "_";
// 	d[3] = " ";
// 	s[0] = "hello";
// 	s[1] = "world";
// 	printf("%s\n", ft_strjoin(2, s, d));
// }
