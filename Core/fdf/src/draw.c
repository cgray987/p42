/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:48:17 by cgray             #+#    #+#             */
/*   Updated: 2024/01/12 17:57:59 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
R_x(t) =   {1		0		0
 			0		cos(t)	-sin(t)
			0		sin(t)	cos(t)}

R_y(t) =   {cos(t)	0		sin(t)
 			0		1		0
			-sin(t)	0		1}

R_z(t) =   {cos(t)	-sin(t)	0
 			sin(t)	cos(t)	0
			0		0		1}
*/

void	iso_proj(float *x, float *y, float *z, float theta, int axis)
{


	if (!theta)
		theta = 45;
	theta = theta * 3.14 / 180;
	if (!axis)
		axis = 0;

	// *x = (*x - *y) * cos(theta);
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
}


void	bresenham(float x, float y, float x1, float y1, t_fdf *data)
{
	float	x_step;
	float	y_step;
	int	max;
	float	z;
	float	z1;

	z = (float)data->z_matrix[(int)y][(int)x];
	z1 = (float)data->z_matrix[(int)y1][(int)x1];

	//--------------zoom---------
	if (!data->zoom)
		data->zoom = 15;
	x *= data->zoom;
	y *= data->zoom;
	x1 *= data->zoom;
	y1 *= data->zoom;
	// z1 *= data->zoom;
	// z1 *= data->zoom;
	//--------------color---------
	if (z > 0 || z1 > 0)
		data->color = 0xFF0000FF;
	else if (z < 0 || z1 < 0)
		data->color = 0x00FF00FF;
	else
		data->color = 0xFFFFFFFF;

	//-------------projection-----

	iso_proj(&x, &y, &z, data->rotate, data->axis);
	iso_proj(&x1, &y1, &z1, data->rotate, data->axis);

	//-------------shift---------

	if (!data->shift_x)
		data->shift_x = 300;
	if (!data->shift_y)
		data->shift_y = 300;
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
