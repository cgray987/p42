/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 14:41:05 by cgray             #+#    #+#             */
/*   Updated: 2023/11/02 13:47:26 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*Allocates memory from count*size and returns ptr to it
setting the memory to zero.
*/
void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	max;

	if (count <= 0 || size <= 0)
		return (NULL);
	max = count * size;
	if (max / count != size)
		return (NULL);
	ptr = malloc(max * sizeof(size_t));
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, max);
	return (ptr);
}
