/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:30:52 by cgray             #+#    #+#             */
/*   Updated: 2024/01/24 15:10:18 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* Creates and displays string to show zoom level and rotations.*/
void	menu_hook(t_fdf *data)
{
	char	*zoom;

	zoom = ft_strjoin("Zoom: ", ft_itoa(data->zoom));
	zoom = ft_strjoin(zoom, " Rotate (x, y, z): ");
	zoom = ft_strjoin(zoom, ft_strjoin("( ", ft_itoa(deg(data->rotate_x))));
	zoom = ft_strjoin(zoom, ft_strjoin(", ", ft_itoa(deg(data->rotate_y))));
	zoom = ft_strjoin(zoom, ft_strjoin(", ", ft_itoa(deg(data->rotate_z))));
	zoom = ft_strjoin(zoom, " )");
	if (data->img_menu != NULL)
		mlx_delete_image(data->mlx_ptr, data->img_menu);
	data->img_menu = mlx_put_string(data->mlx_ptr, zoom, 5, 5);
	free(zoom);
}

/* uses MLX ydelta mouse info to inc/dec zoom level */
mlx_scrollfunc	zoom_scroll_hook(double xdelta, double ydelta, t_fdf *data)
{
	(void)xdelta;
	if (ydelta > 0)
		data->zoom += 1;
	if (ydelta < 0)
		data->zoom -= 1;
	data_limits(data);
	reset_window(data);
	return (0);
}

/* Hooks for WASD to shift map */
void	key_shift(mlx_key_data_t keydata, t_fdf *data)
{
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
	data_limits(data);
	reset_window(data);
}

/* Hook for changing projections
	1 = ISOMETRIC
	2 = PARALLEL
	3 = FLAT
 */
void	key_proj(mlx_key_data_t keydata, t_fdf *data)
{
	if (keydata.key == MLX_KEY_1 && keydata.action == MLX_PRESS)
	{
		data->rotate_x = atan(sqrt(2));
		data->rotate_z = -rad(45);
		data->rotate_y = 0;
	}
	if (keydata.key == MLX_KEY_2 && keydata.action == MLX_PRESS)
	{
		data->rotate_x = rad(90);
		data->rotate_z = 0;
		data->rotate_y = 0;
	}
	if (keydata.key == MLX_KEY_3 && keydata.action == MLX_PRESS)
	{
		data->rotate_x = 0;
		data->rotate_z = 0;
		data->rotate_y = 0;
	}
	reset_window(data);
}

/* Hook to change rotation in each axis. Uses Numpad keys.
			+	-
	X axis:	2	8
	Y axis:	4	6
	Z axis:	7	9
	(keydata.action == MLX_REPEAT ||
 */
mlx_keyfunc	key_hook_fdf(mlx_key_data_t keydata, t_fdf *data)
{
	key_shift(keydata, data);
	key_proj(keydata, data);
	if (keydata.key == MLX_KEY_KP_2
		&& (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
		data->rotate_x -= rad(5);
	if (keydata.key == MLX_KEY_KP_8
		&& (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
		data->rotate_x += rad(5);
	if (keydata.key == MLX_KEY_KP_4
		&& (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
		data->rotate_y -= rad(5);
	if (keydata.key == MLX_KEY_KP_6
		&& (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
		data->rotate_y += rad(5);
	if (keydata.key == MLX_KEY_KP_7
		&& (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
		data->rotate_z -= rad(5);
	if (keydata.key == MLX_KEY_KP_9
		&& (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
		data->rotate_z += rad(5);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(data->mlx_ptr);
	data_limits(data);
	reset_window(data);
	return (0);
}
