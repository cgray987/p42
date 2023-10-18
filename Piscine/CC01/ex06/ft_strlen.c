/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:05:12 by cgray             #+#    #+#             */
/*   Updated: 2023/09/28 13:17:02 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*str != '\0')
	{
		len++;
		str++;
	}
	return (len);
}
// #include <stdio.h>

// int	main(void)
// {
// 	int	len;
// 	char	a[] = "test";

// 	len = ft_strlen(&a[0]);
// 	printf("%d/n",len);
// }
