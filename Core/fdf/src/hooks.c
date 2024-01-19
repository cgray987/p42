/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:30:52 by cgray             #+#    #+#             */
/*   Updated: 2024/01/19 17:44:15 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// typedef struct
// {
// 	int zoom_2;
// } t_zoom;


void	zoom_scroll_hook(double xdelta, double ydelta, t_fdf *data)
{
	if (ydelta > 0)
	{
		if (data->zoom > 100)
			data->zoom = 100;
		data->zoom += 1;
		// data->zoom = zoom_2;
	}
	if (ydelta < 0)
	{
		if (data->zoom <= 2)
			data->zoom = 2;
		data->zoom -= 1;
		// data->zoom = zoom_2;
	}
	ft_printf("Zoom: %d\n", data->zoom);
	mlx_delete_image(data->mlx_ptr, data->img_ptr);
	mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	draw(data);
	mlx_image_to_window(data->mlx_ptr, data->img_ptr, 0, 0);
}

void	key_hook_fdf(mlx_key_data_t keydata, t_fdf *data)
{
	// data->rotate_x = 180;
	// data->rotate_y = 180;
	// data->rotate_z = 180;
	// if (data->shift_x <= 1)
	// 	data->shift_x = WIDTH;
	// if (data->shift_y <= 1)
	// 	data->shift_y = HEIGHT;
	if (keydata.key == MLX_KEY_A
		&& (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
		data->shift_x -= 20;
	if (keydata.key == MLX_KEY_D
		&& (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
		data->shift_x += 20;
	if (keydata.key == MLX_KEY_W
		&& (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
		data->shift_y -= 20;
	if (keydata.key == MLX_KEY_S
		&& (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
		data->shift_y += 20;
	if (keydata.key == MLX_KEY_KP_2
		&& (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
	{
		data->rotate_x -= rad(5);
	}
	if (keydata.key == MLX_KEY_KP_8
		&& (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
	{
		data->rotate_x += rad(5);
	}
	if (keydata.key == MLX_KEY_KP_4
		&& (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
	{
		data->rotate_y -= rad(5);
	}
	if (keydata.key == MLX_KEY_KP_6
		&& (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
	{
		data->rotate_y += rad(5);
	}
	if (keydata.key == MLX_KEY_KP_7
		&& (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
	{
		data->rotate_z -= rad(5);
	}
	if (keydata.key == MLX_KEY_KP_9
		&& (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
	{
		data->rotate_z += rad(5);
	}
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(data->mlx_ptr);
	if (keydata.key == MLX_KEY_1 && keydata.action == MLX_PRESS)
	{
		data->project = 'A';
		data->rotate_x = atan(sqrt(2));
		data->rotate_z = -rad(45);
		data->rotate_y = 0;
	}
	if (keydata.key == MLX_KEY_2 && keydata.action == MLX_PRESS)
	{
		data->project = 'P';
		data->rotate_x = rad(90);
		data->rotate_z = 0;
		data->rotate_y = 0;
	}
	if (keydata.key == MLX_KEY_3 && keydata.action == MLX_PRESS)
	{
		data->project = 'F';
		data->rotate_x = 0;
		data->rotate_z = 0;
		data->rotate_y = 0;
	}
	mlx_delete_image(data->mlx_ptr, data->img_ptr);
	mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	draw(data);
	mlx_image_to_window(data->mlx_ptr, data->img_ptr, 0, 0);
}
