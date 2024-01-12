/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:30:52 by cgray             #+#    #+#             */
/*   Updated: 2024/01/12 17:36:23 by cgray            ###   ########.fr       */
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
		if (data->zoom >= 40)
			data->zoom = 40;
		data->zoom += 1;
		// data->zoom = zoom_2;
	}
	if (ydelta < 0)
	{
		if (data->zoom < 1)
			data->zoom = 1;
		data->zoom -= 1;
		// data->zoom = zoom_2;
	}
	mlx_delete_image(data->mlx_ptr, data->img_ptr);
	mlx_new_image(data->mlx_ptr, 1024, 1024);
	draw(data);
	mlx_image_to_window(data->mlx_ptr, data->img_ptr, 0, 0);
}

void	key_hook_fdf(mlx_key_data_t keydata, t_fdf *data)
{
	if (data->shift_x < 50)
		data->shift_x = 50;
	if (data->shift_y < 50)
		data->shift_y = 50;
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		data->shift_x -= 20;
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		data->shift_x += 20;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		data->shift_y -= 20;
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		data->shift_y += 20;
	if (keydata.key == MLX_KEY_Q && keydata.action == MLX_PRESS)
	{
		data->rotate -= 5;
		data->axis = 1;
	}
	if (keydata.key == MLX_KEY_E && keydata.action == MLX_PRESS)
	{
		data->rotate += 5;
		data->axis = 1;
	}
	if (keydata.key == MLX_KEY_1 && keydata.action == MLX_PRESS)
	{
		data->rotate -= 5;
		data->axis = 2;
	}
	if (keydata.key == MLX_KEY_3 && keydata.action == MLX_PRESS)
	{
		data->rotate += 5;
		data->axis = 2;
	}
	if (keydata.key == MLX_KEY_Z && keydata.action == MLX_PRESS)
	{
		data->rotate -= 5;
		data->axis = 3;
	}
	if (keydata.key == MLX_KEY_C && keydata.action == MLX_PRESS)
	{
		data->rotate += 5;
		data->axis = 3;
	}
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(data->mlx_ptr);
	mlx_delete_image(data->mlx_ptr, data->img_ptr);
	mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	draw(data);
	mlx_image_to_window(data->mlx_ptr, data->img_ptr, 0, 0);
}
