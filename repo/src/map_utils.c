/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: massrayb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 09:30:39 by massrayb          #+#    #+#             */
/*   Updated: 2025/02/09 12:30:50 by massrayb         ###   ########.fr       */
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
	if (ft_strlen(line) > MAX_WIDTH)
		clear_game(gm, "Error: map is too wide", -1);
	while (line)
	{
		gm->m_height++;
		free(line);
		line = get_next_line(fd);
	}
	if (gm->m_height > MAX_HEIGHT)
		clear_game(gm, "Error: map is too long\n", -1);
	else if (gm->m_height < 3)
		clear_game(gm, "Error: map is too short\n", -1);
	close(fd);
}
