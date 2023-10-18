/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:43:23 by cgray             #+#    #+#             */
/*   Updated: 2023/09/21 14:18:56 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] < s2[i])
			return (-1);
		if (s1[i] > s2[i])
			return (1);
		i++;
	}
	if (n <= 0)
		return (0);
	else
		return (0);
}
// #include <stdio.h>

// int	main(void)
// {
// 	char	s1[] = "hel";
// 	char	s2[] = "hello";

// 	printf("s1: %s | s2: %s\n strncmp: %d\n", s1, s2, ft_strncmp(s1, s2, 3));
// }
