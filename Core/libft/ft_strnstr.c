/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 10:33:55 by cgray             #+#    #+#             */
/*   Updated: 2023/10/20 15:28:08 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* i is big index; j is little index
loop thru big, loop thru little inside,
search for little in big
*/
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int		i;
	char	*found;

	i = 0;
	found = (char *)big;
	if (*little == '\0')
		return (found);
	while (*found != '\0')
	{
		i = 0;
		while (little[i] == *(found + i) && (size_t)i < len)
			i++;
		if (little[i] == '\0')
			return (found);
		found++;
	}
	return ('\0');
}
