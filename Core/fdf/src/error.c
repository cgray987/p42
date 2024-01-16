/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:32:40 by cgray             #+#    #+#             */
/*   Updated: 2024/01/15 15:37:34 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
/*Puts mlx error msg to terminal*/

void	ft_error(void)
{
	ft_putstr_fd((char *)mlx_strerror(mlx_errno), 2);
	exit(EXIT_FAILURE);
}
/*
Checks that fd has '.fdf' file extension
 */

int	filename_error(char *fd)
{
	size_t	filename_len;

	filename_len = ft_strlen(fd);
	if (filename_len < 4)
		return (1);
	if (ft_strncmp(&fd[filename_len - 4], ".fdf", 4))
		return (1);
	return (0);
}
