/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 13:27:56 by cgray             #+#    #+#             */
/*   Updated: 2024/01/19 17:42:50 by cgray            ###   ########.fr       */
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
			ft_strjoin("FDF - ", str + 5), true);
	data->img_ptr = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
}

