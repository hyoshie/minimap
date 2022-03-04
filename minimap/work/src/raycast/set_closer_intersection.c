/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_closer_intersection.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <hyoshie@student.42tokyo.jp>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 15:41:29 by user42            #+#    #+#             */
/*   Updated: 2022/03/04 14:03:54 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constants.h"
#include "minimap.h"

static double	get_distance(const t_point *p1, const t_point *p2)
{
	double	dx;
	double	dy;

	dx = p1->x - p2->x;
	dy = p1->y - p2->y;
	return (sqrt(dx * dx + dy * dy));
}

void	set_closer_intersection(t_ray *ray, const t_point *horiz_intersection,
								const t_point *vert_intersection,
								const t_point *player_pos)
{
	double	horiz_distance;
	double	vert_distance;

	horiz_distance = get_distance(horiz_intersection, player_pos);
	vert_distance = get_distance(vert_intersection, player_pos);
	if (horiz_distance < vert_distance)
	{
		ray->wall_hit = *horiz_intersection;
		ray->distance = horiz_distance;
		ray->was_hit_vertical = false;
	}
	else
	{
		ray->wall_hit = *vert_intersection;
		ray->distance = vert_distance;
		ray->was_hit_vertical = true;
	}
}
