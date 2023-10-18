/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:00:14 by cgray             #+#    #+#             */
/*   Updated: 2023/10/17 15:27:44 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *string, int search)
{
	const char	*found;

	found = '\0';
	while (*(char *)string != '\0')
	{
		if (*(char *)string == (char)search)
			found = (char *)string;
		string++;
	}
	if (*found != '\0')
		return ((char *) found);
	if (search == '\0')
		return ('\0');
	return ('\0');
}
