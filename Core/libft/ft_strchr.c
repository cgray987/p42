/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:21:40 by cgray             #+#    #+#             */
/*   Updated: 2023/10/17 13:49:38 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *string, int search)
{
	while (*(char *)string != '\0')
	{
		if (*(char *)string == (char)search)
			return ((char *)string);
		string++;
	}
	if (search == '\0')
		return ('\0');
	return ('\0');
}
