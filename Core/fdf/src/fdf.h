/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 13:25:29 by cgray             #+#    #+#             */
/*   Updated: 2024/01/28 19:16:00 by cgray            ###   ########.fr       */
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
# define PI 3.14159265359
# define PI_2 6.28318530718

/* 3 colors based on input flag */
typedef struct s_color_scheme
{
	int			flag;
	uint32_t	high;
	uint32_t	neutral;
	uint32_t	low;
}	t_color_scheme;

/*
	{x, y, z, color}
 */
typedef struct s_3d_vector
{
	float		x;
	float		y;
	float		z;
	uint32_t	color;
}	t_3d_vector;

typedef struct s_color
{
	uint32_t	r;
	uint32_t	g;
	uint32_t	b;
	uint32_t	a;
}	t_color;

typedef struct s_fdf
{
	int				width;
	int				height;
	t_3d_vector		center;
	int				**z_matrix;
	int				z_max;
	int				z_min;
	int				zoom;
	int				shift_x;
	int				shift_y;
	float			rotate_x;
	float			rotate_y;
	float			rotate_z;
	float			z_mod;
	char			projection;
	int				color;
	int				**color_matrix;
	t_color_scheme	color_scheme;

	mlx_t			*mlx_ptr;
	mlx_image_t		*img_ptr;
	mlx_image_t		*img_menu;

}	t_fdf;

/* ------------------------FDF------------------------------ */
/* ------------------------init.c------------------------------ */
void			init_fdf(t_fdf *data, char *str);
void			reset_window(t_fdf *data);
void			clean_img(t_fdf *data);
void			clear_rot(t_fdf *data);
void			data_limits(t_fdf *data);

/* ------------------------read_file.c------------------------------ */
void			read_file(char *file_name, t_fdf *data);

/* ------------------------read_utils.c------------------------------ */
int				map_height(char *file_name);
int				map_width(char *file_name);
void			fill_matrix(int *z_matrix_line,
					int *color_mat_line, char *line);

/* ------------------------draw.c------------------------------ */
void			draw(t_fdf *data);
void			bresenham(t_3d_vector vec, t_3d_vector vec1, t_fdf *data);

/* ------------------------projections.c------------------------------ */
t_3d_vector		iso_proj(t_3d_vector p, t_fdf *data);
t_3d_vector		para_proj(t_3d_vector p, t_fdf *data);
t_3d_vector		front_proj(t_3d_vector p, t_fdf *data);
t_3d_vector		right_proj(t_3d_vector p, t_fdf *data);
t_3d_vector		top_proj(t_3d_vector p, t_fdf *data);

/* ------------------------rotate.c------------------------------ */
t_3d_vector		rotate_all(t_3d_vector p, t_fdf *data);
t_3d_vector		rotate_z(t_3d_vector p, t_fdf *data);
t_3d_vector		rotate_y(t_3d_vector p, t_fdf *data);
t_3d_vector		rotate_x(t_3d_vector p, t_fdf *data);

/* ------------------------color.c------------------------------ */
void			color_schemes(t_fdf *data);
uint32_t		get_color(t_3d_vector vec, t_fdf *data);
int				color_from_str(char *str);
t_color			split_color(uint32_t rgba);
int				merge_color(int r, int g, int b, int a);

/* ------------------------grad.c------------------------------ */
uint32_t		grad_pt(t_3d_vector start, t_3d_vector end, t_3d_vector curr);

/* ------------------------hooks.c------------------------------ */
void			menu_hook(t_fdf *data);
mlx_scrollfunc	zoom_scroll_hook(double xdelta, double ydelta, t_fdf *data);
mlx_keyfunc		key_hook_fdf(mlx_key_data_t keydata, t_fdf *data);

/* ------------------------hooks2.c------------------------------ */
void			key_colors(mlx_key_data_t keydata, t_fdf *data);
void			call_keys(mlx_key_data_t keydata, t_fdf *data);
void			key_proj(mlx_key_data_t keydata, t_fdf *data);
void			key_shift(mlx_key_data_t keydata, t_fdf *data);

/* ------------------------error.c------------------------------ */
int				filename_error(char *fd);
void			ft_error(void);

/* ------------------------trig.c------------------------------ */
float			rad(float deg);
float			deg(float rad);

/* ------------------------NO LONGER USED------------------------------ */
/* t_3d_vector		angular_proj(t_3d_vector vec, t_fdf *data);
t_3d_vector	multiply_vector_x_matrix(t_3d_vector v, t_3d_matrix m);
t_3d_vector		multiply_vector_x_constant(t_3d_vector v, int n);
t_3d_matrix		rotation_matrix(float deg, char axis);
t_3d_vector	spherical_proj(t_3d_vector vec);

	// 3x4 Matrix
	// i- {x, y, z, color;
	// j-  x, y, z, color;
	// k-  x, y, z, color};
typedef struct s_3d_matrix
{
	t_3d_vector	i;
	t_3d_vector	j;
	t_3d_vector	k;
}	t_3d_matrix; */

#endif
