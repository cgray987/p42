/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:50:59 by cgray             #+#    #+#             */
/*   Updated: 2024/01/05 16:34:18 by cgray            ###   ########.fr       */
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

//fills z_matrix from map data
void	fill_matrix(int *z_matrix_line, char *line)
{
	char	**matrix;
	int		i;

	i = 0;
	matrix = ft_split(line, ' ');
	while (matrix[i])
	{
		z_matrix_line[i] = ft_atoi(matrix[i]);
		free(matrix[i]);
		i++;
	}
	free(matrix);
}
//reads map and places into fdf data matrix

void	read_file(char *file_name, t_fdf *data)
{
	int		fd;
	char	*line;
	int		i;

	data->height = map_height(file_name);
	data->width = map_width(file_name);
	data->z_matrix = (int **)malloc(sizeof(int *) * (data->height + 1));
	i = 0;
	while (i < data->height)
		{
			data->z_matrix[i] = (int *)malloc(sizeof(int) * (data->width + 1));
			i++;
		}
	i = 0;
	fd = open(file_name, O_RDONLY, 0);
	while (i < data->height)
	{
		line = get_next_line(fd);
		fill_matrix(data->z_matrix[i], line);
		free(line);
		i++;
	}
	close(fd);
	data->z_matrix[i] = '\0';
}
