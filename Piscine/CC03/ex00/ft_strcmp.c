/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:39:09 by cgray             #+#    #+#             */
/*   Updated: 2023/09/21 14:15:08 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
// #include <stdio.h>

// int	main(void)
// {
// 	char	s1[] = "helloo";
// 	char	s2[] = "hello";

// 	printf("s1: %s | s2: %s\n strcmp: %d\n", s1, s2, ft_strcmp(s1, s2));
// }
