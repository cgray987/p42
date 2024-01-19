/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:50:59 by cgray             #+#    #+#             */
/*   Updated: 2024/01/19 17:45:41 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
//counts number of rows in map
int	map_height(char *file_name)
{
	int		fd;
	int		height;

	fd = open(file_name, O_RDONLY, 0);
	height = 0;
	while (get_next_line(fd))
		height++;
	close(fd);
	return (height);
}

//counts number of columns in map (assumes map size is rectangular)
int	map_width(char *file_name)
{
	char	*line;
	int		fd;
	int		width;

	fd = open(file_name, O_RDONLY, 0);
	line = get_next_line(fd);
	width = ft_count_words(line, ' ');
	free(line);
	close(fd);
	return (width);
}

//fills z_matrix and color matrix from map data
void	fill_matrix(int *z_matrix_line, int *color_mat_line,
			char *line, t_fdf *data)
{
	char	**matrix;
	int		i;
	int		max;
	char	**element;

	i = 0;
	matrix = ft_split(line, ' ');
	while (matrix[i])
	{
		element = ft_split(matrix[i], ',');
		if (element[1])
			color_mat_line[i] = color_from_str(element[1]);
		z_matrix_line[i] = ft_atoi(matrix[i]);
		free(matrix[i]);
		free(element);
		i++;
	}
	free(matrix);
}

//reads map and places into fdf data matrix
void	find_origin(t_fdf *data)
{
	t_3d_vector	center;

	center.x = data->width / 2;
	center.y = data->height / 2;
	center.z = (data->z_max - data->z_min) / 2;
	center.color = 0xFFFFFFFF;
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

void	read_file(char *file_name, t_fdf *data)
{
	int		fd;
	char	*line;
	int		i;

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
	i = 0;
	fd = open(file_name, O_RDONLY, 0);
	while (i < data->height)
	{
		line = get_next_line(fd);
		// ft_printf("%d: ", i);
		fill_matrix(data->z_matrix[i], data->color_matrix[i], line, data);
		free(line);
		i++;
	}
	close(fd);
	data->z_matrix[i] = '\0';
	data->color_matrix[i] = '\0';
	z_lim(data);
	find_origin(data);
}
