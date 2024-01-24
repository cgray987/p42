/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:48:17 by cgray             #+#    #+#             */
/*   Updated: 2024/01/24 17:29:50 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	multiply_matrix_x_matrix(int m1[4][4], int m2[4][4], int res[4][4])
{
	int			i;
	int			j;
	int			k;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			res[i][j] = 0;
			k = 0;
			while (k < 4)
			{
				res[i][j] += m1[i][k] * m2[k][j];
				k++;
			}
			j++;
		}
		i++;
	}
}

/* multiplies vector {x,y,z,} by 3x3 rotation matrix for each axis */
t_3d_vector	angular_proj(t_3d_vector vec, t_fdf *data)
{
	int		center[4][4];
	int		neg_center[4][4];
	int		rotation[4][4]
	int		res[4][4];


	center = {{1, 0, 0, data->center.x}
	{0, 1, 0, data->center.y}
	{0, 0, 1, data->center.z}
	{0, 0, 0, 1}};
	neg_center = {{1, 0, 0, -data->center.x}
	{0, 1, 0, -data->center.y}
	{0, 0, 1, -data->center.z}
	{0, 0, 0, 1}};

	// vec1 = multiply_vector_x_matrix(vec, rotation_matrix(data->rotate_z, 'z'));
	// vec2 = multiply_vector_x_matrix(vec, rotation_matrix(data->rotate_x, 'x'));
	// vec3 = multiply_vector_x_matrix(vec, rotation_matrix(data->rotate_y, 'y'));

	rotation = {multiply_vector_x_matrix(vec, rotation_matrix(data->rotate_z, 'z')),
		multiply_vector_x_matrix(vec, rotation_matrix(data->rotate_x, 'x')),
		multiply_vector_x_matrix(vec, rotation_matrix(data->rotate_y, 'y')),
		{0, 0, 0, 1}};
	res = multiply_matrix_x_matrix(center, rotation, res);
	res = multiply_matrix_x_matrix(res, neg_center, res);


	return (vec);
}

void	get_color(t_3d_vector vec, t_3d_vector vec1, t_fdf *data)
{
	if (data->color_matrix[(int)vec.y][(int)vec.x])
		vec.color = data->color_matrix[(int)vec.y][(int)vec.x];
	else if (vec.z > 0 || vec1.z > 0)
		data->color = 0x99C28FFF;
	else if (vec.z < 0 || vec1.z < 0)
		data->color = 0xC28F8FFF;
	else
		data->color = 0xFFFFFFFF;
}

/* adds hook shift x */
t_3d_vector	shift_x_y(t_3d_vector vec, t_fdf *data)
{
	vec.x = vec.x + data->shift_x;
	vec.y = vec.y + data->shift_y;
	return (vec);
}

/* given two sets of coords, find fastest way to draw from one to the other.
before drawing:
	-find corresponding z altitude/color
	-multiply by zoom value
	-add shift value
*/
void	bresenham(t_3d_vector vec, t_3d_vector vec1, t_fdf *data)
{
	double		x_step;
	double		y_step;
	double		max;

	vec.z = (double)data->z_matrix[(int)vec.y][(int)vec.x];
	vec1.z = (double)data->z_matrix[(int)vec1.y][(int)vec1.x];
	get_color(vec, vec1, data);
	vec = multiply_vector_x_constant(vec, data->zoom);
	vec1 = multiply_vector_x_constant(vec1, data->zoom);
	vec = angular_proj(vec, data);
	vec1 = angular_proj(vec1, data);
	vec = shift_x_y(vec, data);
	vec1 = shift_x_y(vec1, data);
	x_step = vec1.x - vec.x;
	y_step = vec1.y - vec.y;
	max = ft_max(ft_abs(x_step), ft_abs(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(vec.x - vec1.x) || (int)(vec.y - vec1.y))
	{
		if (((uint32_t)vec.x > 0 && (uint32_t)vec.y > 0) && ((uint32_t)vec.x < WIDTH && (uint32_t)vec.y < HEIGHT))
			mlx_put_pixel(data->img_ptr, vec.x, vec.y, data->color);
		vec.x += x_step;
		vec.y += y_step;
	}
}

void	draw(t_fdf *data)
{
	t_3d_vector	p0;
	t_3d_vector	p1_x;
	t_3d_vector	p1_y;

	p0 = (t_3d_vector){0, 0, 0, 0};
	while (p0.y < data->height)
	{
		p0.x = 0;
		while (p0.x < data->width)
		{
			p1_x = (t_3d_vector){p0.x + 1, p0.y, 0, 0};
			p1_y = (t_3d_vector){p0.x, p0.y + 1, 0, 0};
			if (p1_x.x < data->width)
				bresenham(p0, p1_x, data);
			if (p1_y.y < data->height)
				bresenham(p0, p1_y, data);
			p0.x++;
		}
		p0.y++;
	}
}
/*
t_3d_vector	spherical_proj(t_3d_vector vec)
{
	double	r;
	double	theta;
	double	phi;
	double	x2;
	double	y2;
	double	z2;

	x2 = vec.x * vec.x;
	y2 = vec.y * vec.y;
	z2 = vec.z * vec.z;

	r = sqrt(x2 + y2 + z2);
	theta = atan2(vec.y, vec.x);
	phi = atan(sqrt(x2 + y2) / vec.z);

	vec.x = r * sin(phi) * cos(theta);
	vec.y = r * sin(phi) * sin(theta);
	vec.z = r * cos(phi);
	return (vec);
}
 */
