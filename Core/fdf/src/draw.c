/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:48:17 by cgray             #+#    #+#             */
/*   Updated: 2024/01/23 17:10:08 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* multiplies vector {x,y,z,} by 3x3 rotation matrix for each axis */
t_3d_vector	angular_proj(t_3d_vector vec, t_fdf *data)
{
	vec = multiply_vector_x_matrix(vec, rotation_matrix(data->rotate_z, 'z'));
	vec = multiply_vector_x_matrix(vec, rotation_matrix(data->rotate_y, 'y'));
	vec = multiply_vector_x_matrix(vec, rotation_matrix(data->rotate_x, 'x'));
	return (vec);
}

/* given two sets of coords, find fastest way to draw from one to the other.
before drawing:
	-find corresponding z altitude/color
	-multiply by zoom value
	-add shift value
*/
void	bresenham(double x, double y, double x1, double y1, t_fdf *data)
{
	double		x_step;
	double		y_step;
	double		max;
	double		z;
	double		z1;
	t_3d_vector	vec;
	t_3d_vector	vec1;

	z = (double)data->z_matrix[(int)y][(int)x];
	z1 = (double)data->z_matrix[(int)y1][(int)x1];

	//--------------color---------

	if (data->color_matrix[(int)y][(int)x])
		data->color = data->color_matrix[(int)y][(int)x];
	// need to control this by input
	else if (z > 0 || z1 > 0)
		data->color = 0x99C28FFF;
	else if (z < 0 || z1 < 0)
		data->color = 0xC28F8FFF;
	else
		data->color = 0xFFFFFFFF;


	// //--------------zoom---------

	x *= data->zoom;
	y *= data->zoom;
	x1 *= data->zoom;
	y1 *= data->zoom;
	z *= data->zoom / data->z_max;
	z1 *= data->zoom / data->z_max;


	//-------------projection/rotation-----
	vec = (t_3d_vector){x, y, z, data->color};
	vec1 = (t_3d_vector){x1, y1, z1, data->color};

	vec = angular_proj(vec, data);
	vec1 = angular_proj(vec1, data);

	x = vec.x;
	y = vec.y;
	z = vec.z;
	x1 = vec1.x;
	y1 = vec1.y;
	z1 = vec1.z;

	// //-------------shift---------

	x += data->shift_x;
	y += data->shift_y;
	x1 += data->shift_x;
	y1 += data->shift_y;

	x_step = x1 - x;
	y_step = y1 - y;

	max = ft_max(ft_abs(x_step), ft_abs(y_step));
	x_step /= max;
	y_step /= max;
//(int)(x - x1) || (int)(y - y1)
	while ((int)(x - x1) || (int)(y - y1))
	{
		if ((x > 0 && y > 0) && (x < WIDTH && y < HEIGHT))
		{
			printf("x: %f y: %f ", x, y);
			mlx_put_pixel(data->img_ptr, x, y, data->color);
		}
		x += x_step;
		y += y_step;
	}
}

void	draw(t_fdf *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
				bresenham(x, y, x + 1, y, data);
			if (y < data->height - 1)
				bresenham(x, y, x, y + 1, data);
			x++;
		}
		y++;
	}
}

// t_3d_vector	spherical_proj(t_3d_vector vec)
// {
// 	double	r;
// 	double	theta;
// 	double	phi;
// 	double	x2;
// 	double	y2;
// 	double	z2;

// 	x2 = vec.x * vec.x;
// 	y2 = vec.y * vec.y;
// 	z2 = vec.z * vec.z;

// 	r = sqrt(x2 + y2 + z2);
// 	theta = atan2(vec.y, vec.x);
// 	phi = atan(sqrt(x2 + y2) / vec.z);

// 	vec.x = r * sin(phi) * cos(theta);
// 	vec.y = r * sin(phi) * sin(theta);
// 	vec.z = r * cos(phi);
// 	return (vec);
// }
