/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 11:55:02 by cgray             #+#    #+#             */
/*   Updated: 2024/01/24 12:40:45 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// -----------------------------------------------------------------------------
// mlx_keyfunc *ft_hook(void* param)
// {
// 	mlx_t* mlx = param;

// 	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
// 		mlx_close_window(mlx);
// 	if (mlx_is_key_down(mlx, MLX_KEY_UP))
// 		image->instances[0].y -= 5;
// 	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
// 		image->instances[0].y += 5;
// 	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
// 		image->instances[0].x -= 5;
// 	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
// 		image->instances[0].x += 5;
// }
// static void	ft_hook(void *param)
// {
// 	const mlx_t	*mlx = param;

// 	ft_printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
// }

// -----------------------------------------------------------------------------
int	main(int argc, char **argv)
{
	t_fdf	*data;

	if (argc == 2)
	{
		if (filename_error(argv[1]) == 1)
			return (EXIT_FAILURE);
		data = (t_fdf *)malloc(sizeof(t_fdf));
		read_file(argv[1], data);
		init_fdf(data, argv[1]);
		draw(data);
		mlx_loop_hook(data->mlx_ptr, &menu_hook, data);
		mlx_scroll_hook(data->mlx_ptr, &zoom_scroll_hook, data);
		mlx_key_hook(data->mlx_ptr, &key_hook_fdf, data);
		mlx_image_to_window(data->mlx_ptr, data->img_ptr, 0, 0);
		mlx_loop(data->mlx_ptr);
		mlx_terminate(data->mlx_ptr);
		return (EXIT_SUCCESS);
	}
}
/* print map
	int i;
	int j;

	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			printf("%3d", data->z_matrix[i][j]);
			j++;
		}
		printf("\n");
		i++;
	} */
