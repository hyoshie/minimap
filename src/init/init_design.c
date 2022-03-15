/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_design.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 20:44:41 by user42            #+#    #+#             */
/*   Updated: 2022/03/14 22:17:51 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constants.h"
#include "cub3d.h"

static void	load_xpm_file(void *mlx_ptr,
	t_texture *direction, char *file_path, t_game *game)
{
	direction->img_ptr = mlx_xpm_file_to_image(mlx_ptr, file_path,
			&direction->width, &direction->height);
	if (!direction->img_ptr)
		free_all_exit(EM_READ_XPM, game);
	direction->addr = \
			mlx_get_data_addr(direction->img_ptr, &direction->bits_per_pixel,
			&direction->size_line, &direction->endian);
}

static void	lst_to_design_dict(t_clst *file_lst,
	int map_start_line, t_dict *design_dict, t_game *game)
{
	t_clst	*lst_ptr;
	char	**vector;
	int		i;

	i = 0;
	lst_ptr = file_lst->next;
	while (i < map_start_line)
	{
		if (lst_ptr->content[0] == '\0')
		{
			lst_ptr = lst_ptr->next;
			i++;
			continue ;
		}
		vector = ft_xsplit(lst_ptr->content, ' ');
		if (vector[2])
			free_all_exit(EM_DESIGN, game);
		dict_addback(design_dict, dict_new(ft_xstrdup(vector[0]),
				ft_xstrdup(vector[1])));
		lst_ptr = lst_ptr->next;
		free_vector(vector);
		i++;
	}
}

static void	load_wall_xpm_files(void *mlx_ptr,
	t_design *design, t_dict *design_dict, t_game *game)
{
	load_xpm_file(mlx_ptr, &design->north,
		dict_get_value("NO", design_dict), game);
	load_xpm_file(mlx_ptr, &design->south,
		dict_get_value("SO", design_dict), game);
	load_xpm_file(mlx_ptr, &design->west,
		dict_get_value("WE", design_dict), game);
	load_xpm_file(mlx_ptr, &design->east,
		dict_get_value("EA", design_dict), game);
}

static void	load_ceil_floor_color(t_design *design,
	t_dict *design_dict, t_game *game)
{
	char	**c_vector;
	char	**f_vector;
	t_color	c_color;
	t_color	f_color;

	c_vector = ft_xsplit(dict_get_value("C", design_dict), ',');
	f_vector = ft_xsplit(dict_get_value("F", design_dict), ',');
	if (c_vector[3] || f_vector[3])
		free_all_exit(EM_MANY_RGB, game);
	c_color = rgb_to_int(0, rgb_atoi(c_vector[0], game),
			rgb_atoi(c_vector[1], game), rgb_atoi(c_vector[2], game));
	f_color = rgb_to_int(0, rgb_atoi(f_vector[0], game),
			rgb_atoi(f_vector[1], game), rgb_atoi(f_vector[2], game));
	design->ceil = c_color;
	design->floor = f_color;
	free_vector(c_vector);
	free_vector(f_vector);
}

void	init_design(t_clst *file_lst,
	int map_start_line, void *mlx_ptr, t_game *game)
{
	t_dict	*design_dict;

	design_dict = dict_new(NULL, NULL);
	lst_to_design_dict(file_lst, map_start_line, design_dict, game);
	validate_design(design_dict, game);
	load_wall_xpm_files(mlx_ptr, &game->design, design_dict, game);
	load_ceil_floor_color(&game->design, design_dict, game);
	dict_clear(design_dict);
}
