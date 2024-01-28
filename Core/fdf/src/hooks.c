/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:30:52 by cgray             #+#    #+#             */
/*   Updated: 2024/01/28 19:31:54 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* Creates and displays string to show zoom level and rotations.
	has weird issues if calling mlx_put_string multiple times
	hence why i create one long string. would like to improve
*/
void	menu_hook(t_fdf *data)
{
	char	*menu;

	menu = "WASD: Shift x/y | ";
	menu = ft_strjoin(menu, "Mousewheel: Zoom - ");
	menu = ft_strjoin(menu, ft_itoa(data->zoom));
	menu = ft_strjoin(menu, " | Rotate (x, y, z): ");
	menu = ft_strjoin(menu, ft_strjoin("( ", ft_itoa(deg(data->rotate_x))));
	menu = ft_strjoin(menu, ft_strjoin(", ", ft_itoa(deg(data->rotate_y))));
	menu = ft_strjoin(menu, ft_strjoin(", ", ft_itoa(deg(data->rotate_z))));
	menu = ft_strjoin(menu, " )");
	menu = ft_strjoin(menu, " | -/+: Change z-mod");
	if (data->img_menu != NULL)
		mlx_delete_image(data->mlx_ptr, data->img_menu);
	data->img_menu = mlx_put_string(data->mlx_ptr, menu, 5, 5);
	free(menu);
}

/* uses MLX ydelta mouse info to inc/dec zoom level */
mlx_scrollfunc	zoom_scroll_hook(double xdelta, double ydelta, t_fdf *data)
{
	clean_img(data);
	(void)xdelta;
	if (ydelta > 0)
		data->zoom += 1;
	if (ydelta < 0)
		data->zoom -= 1;
	data_limits(data);
	draw(data);
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
	if (keydata.key == MLX_KEY_MINUS
		&& (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
		data->z_mod += .1;
	if (keydata.key == MLX_KEY_EQUAL
		&& (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
		data->z_mod -= .1;
	data_limits(data);
}

/* Hook for changing projections
	1 = ISOMETRIC
	2 = PARALLEL
	3 = FRONT
	4 = TOP
	5 = SIDE (right)
 */
void	key_proj(mlx_key_data_t keydata, t_fdf *data)
{
	if (keydata.key == MLX_KEY_1 && keydata.action == MLX_PRESS)
	{
		data->projection = 'I';
		clear_rot(data);
	}
	if (keydata.key == MLX_KEY_2 && keydata.action == MLX_PRESS)
	{
		data->projection = 'P';
		clear_rot(data);
	}
	if (keydata.key == MLX_KEY_3 && keydata.action == MLX_PRESS)
	{
		data->projection = 'F';
		clear_rot(data);
	}
	if (keydata.key == MLX_KEY_4 && keydata.action == MLX_PRESS)
	{
		data->projection = 'T';
		clear_rot(data);
	}
	if (keydata.key == MLX_KEY_5 && keydata.action == MLX_PRESS)
	{
		data->projection = 'R';
		clear_rot(data);
	}
}

/* Hook to change rotation in each axis. Uses Numpad keys.
			+	-
	X axis:	5	8
	Y axis:	4	6
	Z axis:	7	9
	(keydata.action == MLX_REPEAT ||
 */
mlx_keyfunc	key_hook_fdf(mlx_key_data_t keydata, t_fdf *data)
{
	call_keys(keydata, data);
	if (keydata.key == MLX_KEY_KP_5
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
	draw(data);
	return (0);
}
