/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:10:53 by cgray             #+#    #+#             */
/*   Updated: 2024/01/24 14:51:28 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* returns vector multiplied by an integer */
t_3d_vector	multiply_vector_x_constant(t_3d_vector v, int n)
{
	v.x = n * v.x;
	v.y = n * v.y;
	v.z = n * v.z;
	return (v);
}

/* returns vector product of vector x matrix */
t_3d_vector	multiply_vector_x_matrix(t_3d_vector v, t_3d_matrix m)
{
	double	*lv;

	lv = (double [3]){v.x, v.y, v.z};
	v.x = lv[0] * m.i.x + lv[1] * m.i.y + lv[2] * m.i.z;
	v.y = lv[0] * m.j.x + lv[1] * m.j.y + lv[2] * m.j.z;
	v.z = lv[0] * m.k.x + lv[1] * m.k.y + lv[2] * m.k.z;
	return (v);
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

/* t_3d_vector	sub_vector(t_3d_vector v1, t_3d_vector v2)
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
} */
