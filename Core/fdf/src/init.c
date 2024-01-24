/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 13:27:56 by cgray             #+#    #+#             */
/*   Updated: 2024/01/24 12:49:51 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
	Set initial variable values, initialize window/image, zoom/rotation, shift
 */
void	init_fdf(t_fdf *data, char *str)
{
	data->zoom = WIDTH / (data->width + 20);
	data->shift_x = (WIDTH / 2) - (.5 * data->width * data->zoom);
	data->shift_y = HEIGHT / 2;
	data->rotate_x = atan(sqrt(2));
	data->rotate_z = -rad(45);
	data->rotate_y = 0;
	data->mlx_ptr = mlx_init(WIDTH, HEIGHT,
			ft_strjoin("FDF - ", str + 5), false);
	data->img_ptr = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
}

void	data_limits(t_fdf *data)
{
	if (data->rotate_x > PI_2 || data->rotate_x < -PI_2)
		data->rotate_x = 0;
	if (data->rotate_y > PI_2 || data->rotate_y < -PI_2)
		data->rotate_y = 0;
	if (data->rotate_z > PI_2 || data->rotate_z < -PI_2)
		data->rotate_z = 0;
	if (data->zoom <= 2)
		data->zoom = 2;
	if (data->zoom > 100)
		data->zoom = 100;
	if (data->shift_x > WIDTH)
		data->shift_x = WIDTH;
	if (data->shift_y > HEIGHT)
		data->shift_y = HEIGHT;
	if (data->shift_x < 2)
		data->shift_x = 2;
	if (data->shift_y < 2)
		data->shift_y = 2;
}

void	reset_window(t_fdf *data)
{
	mlx_delete_image(data->mlx_ptr, data->img_ptr);
	mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	draw(data);
	mlx_image_to_window(data->mlx_ptr, data->img_ptr, 0, 0);
}
