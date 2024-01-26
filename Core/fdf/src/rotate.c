/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:18:25 by cgray             #+#    #+#             */
/*   Updated: 2024/01/26 16:43:45 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	make_point(int x, int y, int z)
{
	t_point	p;

	p.x = x;
	p.y = y;
	p.z = z;
	return (p);
}

t_point	rotate_x(t_point p, t_fdf *data)
{
	float	t_z;
	float	t_y;

	t_z = p.z;
	t_y = p.y;
	p.y = t_y * cos(data->rotate_x) + t_z * sin(data->rotate_x);
	p.z = -t_y * sin(data->rotate_x) + t_z * cos(data->rotate_x);
	return (p);
}

t_point	rotate_y(t_point p, t_fdf *data)
{
	float	t_z;
	float	t_x;

	t_z = p.z;
	t_x = p.x;
	p.x = t_x * cos(data->rotate_y) + t_z * sin(data->rotate_y);
	p.z = -t_x * sin(data->rotate_y) + t_z * cos(data->rotate_y);
	return (p);
}

t_point	rotate_z(t_point p, t_fdf *data)
{
	float	t_x;
	float	t_y;

	t_x = p.x;
	t_y = p.y;
	p.x = t_x * cos(data->rotate_z) - t_y * sin(data->rotate_z);
	p.y = t_x * sin(data->rotate_z) + t_y * cos(data->rotate_z);
	return (p);
}

t_point	rotate_all(t_point p, t_fdf *data)
{
	p.x -= data->center.x;
	p.y -= data->center.y;
	p.z -= data->center.z;
	p = rotate_z(p, data);
	p = rotate_x(p, data);
	p = rotate_y(p, data);
	p.x += data->center.x;
	p.y += data->center.y;
	p.z += data->center.z;
	return (p);
}
