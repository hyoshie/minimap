/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_all_ray.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <hyoshie@student.42tokyo.jp>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 11:09:55 by user42            #+#    #+#             */
/*   Updated: 2022/03/14 00:44:27 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constants.h"
#include "cub3d.h"

static void	render_ray(t_minimap *mini, t_ray *ray, t_img *win_img)
{
	int		ray_x;
	int		ray_y;
	double	mini_ray_distance;
	int		i;

	i = 0;
	mini_ray_distance = ray->distance * mini->scale;
	while (i < mini_ray_distance)
	{
		ray_x = mini->player_pos.x + cos(ray->angle) * i;
		ray_y = mini->player_pos.y + sin(ray->angle) * i;
		my_mlx_pixel_put(win_img, ray_x, ray_y, YELLOW);
		i++;
	}
}

void	render_all_ray(t_minimap *mini, t_ray *ray, t_img *win_img)
{
	int		i;

	i = 0;
	while (i < NUM_RAYS)
	{
		render_ray(mini, &ray[i++], win_img);
	}
}
