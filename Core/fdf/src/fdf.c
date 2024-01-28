/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 11:55:02 by cgray             #+#    #+#             */
/*   Updated: 2024/01/28 19:15:03 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	show_controls_terminal(void)
{
	ft_printf("Translate:\t\tWASD\n");
	ft_printf("Zoom:\t\t\tMousewheel\n");
	ft_printf("Colors:\t\t\tZ, X, C, V\n");
	ft_printf("Raise/Lower Height:\t-/+\n");
	ft_printf("Projections: \n\tISOMETRIC:\t1\n");
	ft_printf("\tPARALLEL:\t2\n");
	ft_printf("\tFRONT VIEW:\t3\n");
	ft_printf("\tTOP VIEW:\t4\n");
	ft_printf("\tSIDE VIEW:\t5\n");
	ft_printf("Rotations:\t\t(NUMPAD KEYS)\n");
	ft_printf("\t\t\t(-)\t(+)\n");
	ft_printf("\tX-AXIS:\t\t5\t8\n");
	ft_printf("\tY-AXIS:\t\t4\t6\n");
	ft_printf("\tZ-AXIS:\t\t7\t9\n");
}

int	main(int argc, char **argv)
{
	t_fdf	*data;

	if (argc == 2)
	{
		if (filename_error(argv[1]) == 1)
			return (1);
		show_controls_terminal();
		data = (t_fdf *)malloc(sizeof(t_fdf));
		read_file(argv[1], data);
		init_fdf(data, argv[1]);
		draw(data);
		mlx_scroll_hook(data->mlx_ptr, &zoom_scroll_hook, data);
		mlx_key_hook(data->mlx_ptr, &key_hook_fdf, data);
		mlx_loop(data->mlx_ptr);
		mlx_terminate(data->mlx_ptr);
		return (0);
	}
	else
	{
		ft_printf("Not enough arguments.\n");
		return (1);
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
