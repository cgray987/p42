/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 13:25:29 by cgray             #+#    #+#             */
/*   Updated: 2024/01/24 14:55:17 by cgray            ###   ########.fr       */
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
# define WIDTH 1920
# define HEIGHT 1080
# define PI 3.14159265359
# define PI_2 6.28318530718

typedef struct s_point
{
	double	x;
	double	y;
}	t_point;

typedef struct s_map
{
	int			x;
	int			y;
	int			z;
	uint32_t	color;
}	t_map;
/*
	{x, y, z, color}
 */
typedef struct s_3d_vector
{
	double		x;
	double		y;
	double		z;
	uint32_t	color;
}	t_3d_vector;

typedef struct s_fdf
{
	int			width;
	int			height;
	t_3d_vector	center;
	int			**z_matrix;
	int			z_max;
	int			z_min;
	int			zoom;
	int			shift_x;
	int			shift_y;
	int			translate;
	double		rotate_x;
	double		rotate_y;
	double		rotate_z;
	int			axis;
	int			color;
	int			**color_matrix;
	char		project;

	mlx_t		*mlx_ptr;
	mlx_image_t	*img_ptr;
	mlx_image_t	*img_menu;

}	t_fdf;

/*
	i- {x, y, z, color;
	j-  x, y, z, color;
	k-  x, y, z, color};
 */
typedef struct s_3d_matrix
{
	t_3d_vector	i;
	t_3d_vector	j;
	t_3d_vector	k;
}	t_3d_matrix;

typedef struct s_color
{
	uint32_t	r;
	uint32_t	g;
	uint32_t	b;
	uint32_t	a;
}	t_color;

void		read_file(char *file_name, t_fdf *data);
int			map_height(char *file_name);
int			map_width(char *file_name);
void		fill_matrix(int *z_matrix_line, int *color_mat_line, char *line);

void		bresenham(t_3d_vector vec, t_3d_vector vec1, t_fdf *data);
void		zoom_scroll_hook(double xdelta, double ydelta, t_fdf *data);
void		key_hook_fdf(mlx_key_data_t keydata, t_fdf *data);
void		draw(t_fdf *data);
int			color_from_str(char *str);
t_color		split_color(uint32_t rgba);
int			merge_color(int r, int g, int b, int a);

uint32_t	ft_grad_pt(t_3d_vector start, t_3d_vector end, t_3d_vector curr);
t_3d_vector	angular_proj(t_3d_vector vec, t_fdf *data);
void		init_fdf(t_fdf *data, char *str);
void		reset_window(t_fdf *data);
int			filename_error(char *fd);
void		ft_error(void);

void		menu_hook(t_fdf *data);
void		data_limits(t_fdf *data);

t_3d_vector	multiply_vector_x_matrix(t_3d_vector v, t_3d_matrix m);
t_3d_vector	multiply_vector_x_constant(t_3d_vector v, int n);
t_3d_matrix	rotation_matrix(double deg, char axis);
double		rad(double deg);
double		deg(double rad);

#endif
