/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: massrayb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 09:30:39 by massrayb          #+#    #+#             */
/*   Updated: 2025/02/08 21:11:57 by massrayb         ###   ########.fr       */
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

void	map_validate_dimensions(t_game_manager *gm)
{
	if (gm->m_height < 3)
		clear_game(gm, "Error: map is too short\n", -1);
	if (gm->m_height > MAX_HEIGHT)
		clear_game(gm, "Error: map is too long\n", -1);
	if (gm->m_width > MAX_WIDTH)
		clear_game(gm, "Error: map is too wide\n", -1);
}
