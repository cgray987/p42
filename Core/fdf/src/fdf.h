/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 13:25:29 by cgray             #+#    #+#             */
/*   Updated: 2024/01/12 15:29:10 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*
|-----------Program Structrure---------------|
	1. read map
		- get height of map -- how many lines
		- get width of map -- how many numbers in each line
		- allocate mem for int matrix using H x W
		- read map and place into matrix
			--ft_split && ft_atoi
	2. Bresenham alg to find points to draw
	3. Draw function to draw lines between each point
	4. Convert to 3D
		-isometric formulas:
			x' = (x - y) * cos(theta);
			y' = (x + y) * sin(theta) - z;
		-x' and y' are 3D transformed coords
		-theta is viewing angle
		-z is height
	5. Key/mouse input
		- base just requires ESC to close window
		- bonus to use arrow keys/WASD
		- scroll wheel for zoom level
		- mouse for rotation? maybe Q/E to rotate around center
	6. Bonuses
		-extra projection -- parallel/conic
		-zoom in and out
		-translation
		-rotation
		-another bonus? colors?
|-----------------------------------------------|
*/
#ifndef FDF_H
# define FDF_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include "../lib/mlx/include/MLX42/MLX42.h"
# include "../lib/libft/includes/libft.h"
# define WIDTH 1280
# define HEIGHT 720


typedef struct
{
	int			width;
	int			height;
	int			**z_matrix;
	int			zoom;
	int			shift_x;
	int			shift_y;
	int			translate;
	int			rotate;
	int			axis;
	int			color;

	mlx_t		*mlx_ptr;
	mlx_image_t	*img_ptr;

}	t_fdf;


void	read_file(char *file_name, t_fdf *data);
void	bresenham(float x0, float y0, float x1, float y1, t_fdf *data);
void	zoom_scroll_hook(double xdelta, double ydelta, t_fdf *data);
void	key_hook_fdf(mlx_key_data_t keydata, t_fdf *data);
void	draw(t_fdf *data);

#endif
