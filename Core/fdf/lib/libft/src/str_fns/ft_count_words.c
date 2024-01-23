/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 15:05:28 by cgray             #+#    #+#             */
/*   Updated: 2024/01/23 14:18:27 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libft.h"
/*Function to count number of words in a given string.
	a word is at the start/end of a string seperated by
	delineator character
*/
int	ft_count_words(char *str, char delin)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (str[i])
	{
		while (str[i] != delin && str[i])
			i++;
		if (str[i])
			words++;
		if (str[i] == '\0')
			break ;
		while (str[i] == delin && str[i])
			i++;
	}
	return (words + 1);
}
