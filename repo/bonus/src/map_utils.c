/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: massrayb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 09:30:39 by massrayb          #+#    #+#             */
/*   Updated: 2025/02/08 21:06:55 by massrayb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map.h"

void	map_calculate_height(t_game_manager *gm, char *name)
{
	int		fd;
	char	*line;

	fd = open(name, O_RDONLY);
	if (fd == -1)
		(ft_putendl_fd("Error: couldn't open the map\n", 2), exit(-1));
	line = get_next_line(fd);
	while (line)
	{
		gm->m_height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

static void	enemy_create(t_game_manager *gm, int x, int y, int size)
{
	int	i;

	if (gm->enemies == NULL)
	{
		gm->enemies = malloc(sizeof(t_enemy) * size + 1);
		if (gm->enemies == NULL)
			clear_game(gm, "Error: coudnt allocate mem for enemies list\n", -1);
		i = -1;
		while (++i <= size)
			gm->enemies[i] = (t_enemy){0};
	}
	i = 0;
	while (gm->enemies[i].pos.x != 0)
		i++;
	gm->enemies[i].pos.x = x;
	gm->enemies[i].pos.y = y;
}

void	enemy_generate_list(t_game_manager *gm, int size)
{
	int	y;
	int	x;

	y = 0;
	while (++y < gm->m_height - 1)
	{
		x = 0;
		while (++x < gm->m_width - 1)
		{
			if (gm->map[y][x] == 't' || gm->map[y][x] == 'T')
				enemy_create(gm, x, y, size);
		}
	}
}

void	map_validate_dimensions(t_game_manager *gm)
{
	if (gm->m_height < 3)
		clear_game(gm, "Error: map is too short\n", -1);
	if (gm->m_height > MAX_HEIGHT)
		clear_game(gm, "Error: map is too long\n", -1);
	if (gm->m_width > MAX_WIDTH)
		clear_game(gm, "Error: map is too wide\n", -1);
}
