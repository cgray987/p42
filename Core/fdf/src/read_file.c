/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:50:59 by cgray             #+#    #+#             */
/*   Updated: 2024/01/26 16:18:59 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//reads map and places into fdf data matrix
void	find_origin(t_fdf *data)
{
	t_point	center;

	center.x = data->width / 2;
	center.y = data->height / 2;
	center.z = (data->z_max - data->z_min) / 2;
	// center.color = 0xFFFFFFFF;
	data->center = center;
}

void	z_lim(t_fdf *data)
{
	int	max;
	int	min;
	int	i;
	int	j;

	max = 0;
	min = 0;
	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			if (data->z_matrix[i][j] > max)
				max = data->z_matrix[i][j];
			if (data->z_matrix[i][j] < min)
				min = data->z_matrix[i][j];
			j++;
		}
		i++;
	}
	data->z_max = max;
	data->z_min = min;
}

void	read_malloc(char *file_name, t_fdf *data)
{
	int	i;

	data->height = map_height(file_name);
	data->width = map_width(file_name);
	data->z_matrix = (int **)malloc(sizeof(int *) * (data->height + 1));
	data->color_matrix = (int **)malloc(sizeof(int *) * (data->height + 1));
	i = 0;
	while (i < data->height)
	{
		data->z_matrix[i] = (int *)malloc(sizeof(int) * (data->width + 1));
		data->color_matrix[i] = (int *)malloc(sizeof(int) * (data->width + 1));
		i++;
	}
}

void	read_file(char *file_name, t_fdf *data)
{
	int		fd;
	char	*line;
	int		i;

	read_malloc(file_name, data);
	i = 0;
	fd = open(file_name, O_RDONLY, 0);
	while (i < data->height)
	{
		line = get_next_line(fd);
		fill_matrix(data->z_matrix[i], data->color_matrix[i], line);
		free(line);
		i++;
	}
	close(fd);
	data->z_matrix[i] = '\0';
	data->color_matrix[i] = '\0';
	z_lim(data);
	find_origin(data);
}
