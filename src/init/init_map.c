/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 21:25:22 by yshimazu          #+#    #+#             */
/*   Updated: 2022/03/14 11:33:47 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constants.h"
#include "cub3d.h"
/* 
//for test, check
void	print_clst(t_clst *lst)
{
	t_clst	*p;

	p = lst->next;
	while (p != lst)
	{
		printf("%s", p->content);
		printf(" : %zu\n", ft_strlen(p->content));
		p = p->next;
	}
}
 */
t_clst	*adjast_map_cols(t_clst *map_lst, size_t map_cols)
{
	t_clst	*p;
	t_clst	*adjasted_lst;
	char	*spaces;
	size_t	content_len;

	p = map_lst->next;
	adjasted_lst = clst_new(NULL);
	while (p != map_lst)
	{
		content_len = ft_strlen(p->content);
		if (content_len != map_cols)
		{
			spaces = xmalloc(sizeof(char) * (map_cols - content_len + 1));
			spaces = ft_memset(spaces, ' ', map_cols - content_len);
			spaces[map_cols - content_len] = '\0';
			clst_addback(adjasted_lst,
				clst_new(ft_xstrjoin(p->content, spaces)));
			free(spaces);
		}
		else
			clst_addback(adjasted_lst, clst_new(ft_xstrdup(p->content)));
		p = p->next;
	}
	clst_clear(map_lst);
	return (adjasted_lst);
}

void	set_map_width_height(t_clst *map_lst, t_map *map, size_t num_nodes)
{
	t_clst	*p;
	size_t	line_len;

	map->num_rows = num_nodes;
	map->height = map->num_rows * TILE_SIZE;
	p = map_lst->next;
	while (p != map_lst)
	{
		line_len = ft_strlen(p->content);
		if (line_len * TILE_SIZE > map->width)
		{
			map->num_cols = line_len;
			map->width = map->num_cols * TILE_SIZE;
		}
		p = p->next;
	}
}

t_clst	*del_design_nodes(t_clst *file_lst, int design_end_line)
{
	t_clst	*p;
	int		num_nodes;

	num_nodes = 0;
	p = file_lst->next;
	while (num_nodes < design_end_line)
	{
		clst_delone(p);
		p = file_lst->next;
		num_nodes++;
	}
	return (file_lst);
}

void	init_map(t_clst *file_lst,
	int map_start_line, int num_nodes, t_game *game)
{
	t_clst	*map_lst;

	map_lst = del_design_nodes(file_lst, map_start_line);
	set_map_width_height(map_lst, &game->map, num_nodes - map_start_line);
	map_lst = adjast_map_cols(file_lst, game->map.num_cols);
	game->map.map_ptr = clst_to_array(map_lst, game->map.height);
	validate_map(&game->map, game);
}
