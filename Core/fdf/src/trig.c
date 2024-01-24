/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trig.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:51:38 by cgray             #+#    #+#             */
/*   Updated: 2024/01/24 14:51:47 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* radians to degrees */
double	rad(double deg)
{
	return (deg * PI / 180);
}

/* degrees to radians */
double	deg(double rad)
{
	return (rad * (180 / PI));
}
