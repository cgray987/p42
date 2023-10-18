/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 10:19:35 by cgray             #+#    #+#             */
/*   Updated: 2023/10/18 10:46:51 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
works like memset but does not return the string
note that when setting ANY value to 0 in a string
results in an empty string
*/
void	*ft_bzero(void *str, size_t len)
{
	unsigned char	*add_v;

	add_v = (unsigned char *)str;
	while (len-- > 0)
	{
		*add_v = '\0';
		add_v++;
	}
	return (0);
}
