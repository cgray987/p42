/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 12:49:48 by cgray             #+#    #+#             */
/*   Updated: 2023/10/18 13:15:31 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	offset;

	offset = 0;
	while (src[offset] != '\0' && offset < size)
	{
		dest[offset] = src[offset];
		offset++;
	}
	dest[offset] = '\0';
	while (src[offset] != '\0')
		offset++;
	return (offset);
}
