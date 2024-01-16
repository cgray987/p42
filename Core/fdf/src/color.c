/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:46:38 by cgray             #+#    #+#             */
/*   Updated: 2024/01/16 16:12:48 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* given individual rgba values, return int color */
int	merge_color(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

/* splits int color into t_color struct */
t_color	split_color(uint32_t rgba)
{
	t_color	color;

	color = (t_color){0, 0, 0, 0};
	if (rgba > 0xFFFFFF)
		color.a = 8;
	color.r = (rgba >> (16 + color.a)) & 0xFF;
	color.g = (rgba >> (8 + color.a)) & 0xFF;
	color.b = (rgba >> (color.a)) & 0xFF;
	if (color.a)
		color.a = rgba & 0xFF;
	return (color);
}

/* returns int color from given string
checks that string has '0x'
checks if color has alpha value
returns white if color not found in str */
int	color_from_str(char *str)
{
	t_color	color;

	if (str && str + 2)
	{
		color = split_color(ft_atoi_base(str + 2, 16));
		if (ft_strlen(str + 2) > 0 && ft_strlen(str + 2) < 7)
			color.a = 0xFF;
		return (merge_color(color.r, color.g, color.b, color.a));
	}
	return (merge_color(0xFF, 0xFF, 0xFF, 0xFF));
}
