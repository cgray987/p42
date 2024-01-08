/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:48:17 by cgray             #+#    #+#             */
/*   Updated: 2024/01/08 17:11:31 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	iso_proj(float *x, float *y, int z)
{
	float	theta;

	theta = 3.14 / 4;

	*x = (*x - *y) * cos(theta);
	*y = (*x + *y) * sin(theta) - z;
}


void	bresenham(float x, float y, float x1, float y1, t_fdf *data)
{
	float	x_step;
	float	y_step;
	int	max;
	int	z;
	int	z1;
	int shift;

	z = data->z_matrix[(int)y][(int)x];
	z1 = data->z_matrix[(int)y1][(int)x1];

	//--------------zoom---------
	x *= data->zoom;
	y *= data->zoom;
	x1 *= data->zoom;
	y1 *= data->zoom;
	//--------------color---------
	if (z > 0 || z1 > 0)
		data->color = 0xFF0000FF;
	else if (z < 0 || z1 < 0)
		data->color = 0x00FF00FF;
	else
		data->color = 0xFFFFFFFF;
	//-------------projection-----
	iso_proj(&x, &y, z);
	iso_proj(&x1, &y1, z1);

	//-------------shift---------
	shift = 300;
	x += shift;
	y += shift;
	x1 += shift;
	y1 += shift;

	x_step = x1 - x;
	y_step = y1 - y;
	// printf("x_step: %f y_step: %f\n", x_step, y_step);
	max = ft_max(ft_abs(x_step), ft_abs(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(x - x1) || (int)(y - y1))
	{
		mlx_put_pixel(data->img_ptr, (uint32_t)x, (uint32_t)y, data->color);
		printf("x-x1: %d y-y1: %d\n", (int)(x - x1), (int)(y - y1));
		printf("x: %f y: %f\n", x, y);
		printf("x_step1: %f y_step1: %f\n", x_step, y_step);
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
