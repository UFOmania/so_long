/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: massrayb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 18:47:12 by massrayb          #+#    #+#             */
/*   Updated: 2025/01/24 15:05:55 by massrayb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map.h"

static void	map_load(t_game_manager *gm, char *name)
{
	int		fd;
	char	*line;
	int		i;

	map_calculate_height(gm, name);
	i = 0;
	fd = open(name, O_RDONLY);
	if (fd == -1)
		(ft_putendl_fd("Error: couldn't open the map 2 timme\n", 2), exit(-1));
	gm->map = malloc(sizeof(char *) * (gm->m_height + 1));
	if (!gm->map)
		(strerror(errno), close(fd), exit(-1));
	line = get_next_line(fd);
	gm->map[i++] = ft_strtrim(line, "\n");
	free(line);
	while (line)
	{
		line = get_next_line(fd);
		gm->map[i] = ft_strtrim(line, "\n");
		free(line);
		i++;
	}
	close(fd);
}

static void	map_validate_shape(t_game_manager *gm)
{
	int	i;
	int	j;
	int	size;

	if (gm->m_height < 3)
		clear_game(gm, "Error: map is too short\n", -1);
	i = -1;
	gm->m_width = ft_strlen(gm->map[0]);
	while (++i < gm->m_height)
	{
		size = (int)ft_strlen(gm->map[i]);
		if (gm->m_width != size)
			clear_game(gm, "Error: invalid map shape\n", -1);
		if (i == 0 || i == gm->m_height - 1)
		{
			j = -1;
			while (++j < size)
				if (gm->map[i][j] != '1')
					clear_game(gm, "Error: invalid up/down shape\n", -1);
		}
		else if (gm->map[i][0] != '1' || gm->map[i][size - 1] != '1')
			clear_game(gm, "Error: invalid right/left side\n", -1);
	}
}

static void	map_elements_count(t_game_manager *gm, t_elements *elements)
{
	int	y;
	int	x;

	y = -1;
	while (++y < gm->m_height)
	{
		x = -1;
		while (++x < gm->m_width)
		{
			if (gm->map[y][x] == 'P')
			{
				(*elements).p_count++;
				gm->p_pos.x = x * 32;
				gm->p_pos.y = y * 32;
			}
			else if (gm->map[y][x] == 'E')
				(*elements).d_count++;
			else if (gm->map[y][x] == 'C')
				(*elements).c_count++;
			else if (gm->map[y][x] == 'T')
				(*elements).t_count++;
		}
	}
}

static void	map_validate_path(t_game_manager *gm,t_elements *elements, int x, int y)
{
	if (gm->map[y][x] == '1' || gm->map[y][x] == 's' || gm->map[y][x] == 'e'
		|| gm->map[y][x] == 'c' || gm->map[y][x] == 't')
		return ;
	if (gm->map[y][x] == 'P' || gm->map[y][x] == '0')
		gm->map[y][x] = 's';
	else if (gm->map[y][x] == 'E')
	{
		gm->map[y][x] = 'e';
		elements->found_exit++;
	}
	else if (gm->map[y][x] == 'C')
	{
		gm->map[y][x] = 'c';
		elements->found_coins++;
	}
	else if (gm->map[y][x] == 'T')
		gm->map[y][x] = 't';
	map_validate_path(gm, elements, x + 1, y);
	map_validate_path(gm, elements, x - 1, y);
	map_validate_path(gm, elements, x, y + 1);
	map_validate_path(gm, elements, x, y - 1);
}

void	init_map(t_game_manager *gm, char *name)
{
	t_elements elements;

	elements = (t_elements){0};
	map_load(gm, name);
	map_validate_shape(gm);
	map_elements_count(gm, &elements);
	if (elements.p_count != 1 || elements.c_count == 0 || 
	elements.d_count != 1 || elements.t_count == 0)
		clear_game(gm, "Error: invalid map, map elements are not good\n", -1);
	gm->coins_count = elements.c_count;
	map_validate_path(gm, &elements, gm->p_pos.x / 32, gm->p_pos.y / 32);
	if (elements.found_exit != 1)
		clear_game(gm, "Error: invalid map, cannot reach the exit\n", -1);
	if (gm->coins_count != elements.found_coins)
		clear_game(gm, "Error, invalid map, connot collect all coins\n", -1);
	enemy_generate_list(gm, elements.t_count);
}
