/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:48:17 by cgray             #+#    #+#             */
/*   Updated: 2024/01/19 17:47:40 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_3d_vector	sub_vector(t_3d_vector v1, t_3d_vector v2)
{
	t_3d_vector	sub;

	sub.x = v1.x - v2.x;
	sub.y = v1.y - v2.y;
	sub.z = v1.z - v2.z;
	return (sub);
}

t_3d_vector	add_vector(t_3d_vector v1, t_3d_vector v2)
{
	t_3d_vector	add;

	add.x = v1.x + v2.x;
	add.y = v1.y + v2.y;
	add.z = v1.z + v2.z;
	return (add);
}

t_3d_vector	multiply_vector_x_matrix(t_3d_vector v, t_3d_matrix m)
{
	double	*lv;

	lv = (double [3]){v.x, v.y, v.z};
	v.x = lv[0] * m.i.x + lv[1] * m.i.y + lv[2] * m.i.z;
	v.y = lv[0] * m.j.x + lv[1] * m.j.y + lv[2] * m.j.z;
	v.z = lv[0] * m.k.x + lv[1] * m.k.y + lv[2] * m.k.z;
	return (v);
}

double	rad(double deg)
{
	return (deg * 3.14 / 180);
}

/*returns 3d rotation matrix given rotation angle and the axis to
rotate about
 */
t_3d_matrix	rotation_matrix(double deg, char axis)
{
	if (axis == 'x')
		return ((t_3d_matrix){
			(t_3d_vector){1, 0, 0, 0},
			(t_3d_vector){0, cos(deg), -sin(deg), 0},
			(t_3d_vector){0, sin(deg), cos(deg), 0}});
	if (axis == 'y')
		return ((t_3d_matrix){
			(t_3d_vector){cos(deg), 0, -sin(deg), 0},
			(t_3d_vector){0, 1, 0, 0},
			(t_3d_vector){sin(deg), 0, cos(deg), 0}});
	if (axis == 'z')
		return ((t_3d_matrix){
			(t_3d_vector){cos(deg), -sin(deg), 0, 0},
			(t_3d_vector){sin(deg), cos(deg), 0, 0},
			(t_3d_vector){0, 0, 1, 0}});
	else
		return ((t_3d_matrix){
			(t_3d_vector){1, 0, 0, 0},
			(t_3d_vector){0, 1, 0, 0},
			(t_3d_vector){0, 0, 1, 0}});
}


// t_3d_vector	iso_proj(t_3d_vector vec, t_fdf *data)
// {
// 	// double	x_deg;
// 	// double	z_deg;

// 	// z_deg = -rad(45);
// 	// x_deg = atan(sqrt(2));
// 	// vec = multiply_vector_x_matrix(vec, rotation_matrix(z_deg, 'z'));
// 	// vec = multiply_vector_x_matrix(vec, rotation_matrix(x_deg, 'x'));
// 	data->rotate_x = atan(sqrt(2));
// 	data->rotate_y = 0;
// 	data->rotate_z = -rad(45);
// 	vec = angular_proj(vec, data);
// 	return (vec);
// }

// t_3d_vector	para_proj(t_3d_vector vec)
// {
// 	vec = multiply_vector_x_matrix(vec, rotation_matrix(0, 'z'));
// 	vec = multiply_vector_x_matrix(vec, rotation_matrix(0, 'y'));
// 	vec = multiply_vector_x_matrix(vec, rotation_matrix(rad(90), 'x'));
// 	return (vec);
// }

// t_3d_vector	flat_proj(t_3d_vector vec)
// {
// 	vec = multiply_vector_x_matrix(vec, rotation_matrix(0, 'z'));
// 	vec = multiply_vector_x_matrix(vec, rotation_matrix(0, 'y'));
// 	vec = multiply_vector_x_matrix(vec, rotation_matrix(0, 'x'));
// 	return (vec);
// }


t_3d_vector	angular_proj(t_3d_vector vec, t_fdf *data)
{

	// vec = sub_vector(data->center, vec);

	// if (!data->rotate_x)
	// 	data->rotate_x = atan(sqrt(2));
	// if (!data->rotate_y)
	// 	data->rotate_y = 0;
	// if (!data->rotate_z)
	// 	data->rotate_z = -rad(45);
	vec = multiply_vector_x_matrix(vec, rotation_matrix(data->rotate_z, 'z'));
	vec = multiply_vector_x_matrix(vec, rotation_matrix(data->rotate_y, 'y'));
	vec = multiply_vector_x_matrix(vec, rotation_matrix(data->rotate_x, 'x'));
	// vec = add_vector(vec, data->center);
	return (vec);
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

/* 	// *x = (*x - *y) * cos(theta);
	// *y = (*x + *y) * sin(theta) - *z;

	if (axis == 1)
	{
		*x = (*x);
		*y = (*y) * cos(theta) - *z * sin(theta);
		// *z = *y * sin(theta) + *z * cos(theta);
	}
	else if (axis == 2)
	{
		*x = *z * sin(theta) + *x * cos(theta);
		*y = *y;
		// *z = *y * cos(theta) - *x * sin(theta);
	}
	else if (axis == 3)
	{
		*x = *x * cos(theta) - *y * sin(theta);
		*y = *x * sin(theta) + *y * cos(theta);
		*z = *z;
	}
 */

void	bresenham(double x, double y, double x1, double y1, t_fdf *data)
{
	double	x_step;
	double	y_step;
	int	max;
	double	z;
	double	z1;
	double	z_max;
	t_3d_vector	vec;
	t_3d_vector	vec1;

	z = (double)data->z_matrix[(int)y][(int)x];
	z1 = (double)data->z_matrix[(int)y1][(int)x1];

	//--------------color---------

	if (data->color_matrix[(int)y][(int)x] != 0)
		data->color = data->color_matrix[(int)y][(int)x];
	// need to control this by input
	else if (z > 0 || z1 > 0)
		data->color = 0x99C28FFF;
	else if (z < 0 || z1 < 0)
		data->color = 0xC28F8FFF;
	else
		data->color = 0xFFFFFFFF;


	//--------------zoom---------

	x *= data->zoom;
	y *= data->zoom;
	x1 *= data->zoom;
	y1 *= data->zoom;
	z *= data->zoom / 10;
	z1 *= data->zoom / 10;


	//-------------projection-----
	vec = (t_3d_vector){x, y, z, data->color};
	vec1 = (t_3d_vector){x1, y1, z1, data->color};


	vec = angular_proj(vec, data);
	vec1 = angular_proj(vec1, data);

	// if (data->project == 'I')
	// {
	// 	vec = iso_proj(vec, data);
	// 	vec1 = iso_proj(vec1, data);
	// }
	// if (data->project == 'P')
	// {
	// 	vec = para_proj(vec);
	// 	vec1 = para_proj(vec1);
	// }
	// if (data->project == 'F')
	// {
	// 	vec = flat_proj(vec);
	// 	vec1 = flat_proj(vec1);
	// }

	x = vec.x;
	y = vec.y;
	z = vec.z;
	x1 = vec1.x;
	y1 = vec1.y;
	z1 = vec1.z;

	//-------------shift---------

	if (data->shift_x > WIDTH)
		data->shift_x = WIDTH - 2;
	if (data->shift_y > HEIGHT)
		data->shift_y = HEIGHT - 2;
	if (data->shift_x <= 30)
		data->shift_x = 30;
	if (data->shift_y <= 30)
		data->shift_y = 30;
	x += data->shift_x;
	y += data->shift_y;
	x1 += data->shift_x;
	y1 += data->shift_y;


	x_step = x1 - x;
	y_step = y1 - y;

	max = ft_max(ft_abs(x_step), ft_abs(y_step));
	x_step /= max;
	y_step /= max;
	// ft_printf("x: %d y: %d\n", x, y);
	while ((int)(x - x1) || (int)(y - y1))
	{
		if (x > 0 && y > 0 && x < WIDTH && y < HEIGHT)
		{
			mlx_put_pixel(data->img_ptr, (uint32_t)x, (uint32_t)y, data->color);
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
			// ft_printf("x: %d y: %d\n", x, y);
			x++;
		}
		y++;
	}
}
