/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: massrayb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 18:47:12 by massrayb          #+#    #+#             */
/*   Updated: 2025/01/19 21:50:02 by massrayb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map.h"

static void	map_load(t_game_manager *gm,  char *name)
{
	int		fd;
	char	*line;
	int		i;
	
	(i = 0, fd = open(name, O_RDONLY));
	if (fd == -1)
		(ft_putendl_fd("Error: couldn't open the map", 2), exit(-1));
	line = get_next_line(fd);
	while (line)
		(gm->m_height++, free(line), line = get_next_line(fd));
	(close(fd), fd = open(name, O_RDONLY));
	if (fd == -1)
		(ft_putendl_fd("Error: couldn't open the map second time", 2), exit(-1));
	gm->map = malloc(sizeof(char *) * (gm->m_height + 1));
	if (!gm->map)
		(strerror(errno), close(fd), exit(-1));
	line = get_next_line(fd);
	(gm->map[i++] = ft_strtrim(line, "\n"), free(line));
	while (line)
		(line = get_next_line(fd), gm->map[i] = ft_strtrim(line, "\n"), free(line), i++);
	close(fd);
}

static void	map_validate_name(char *name)
{
	char	*dot;

	dot = ft_strrchr(name, '.');
	if (!dot || ft_strnstr(dot, ".ber", 4) == NULL || dot[4] != '\0')
		(ft_putendl_fd("Error : invalid map name", 2), exit(-1));
}

static void	map_validate_shape(t_game_manager *gm)
{
	int	i;
	int size;
	int j;

	i = -1;
	gm->m_width = ft_strlen(gm->map[0]);
	while (++i < gm->m_height)
	{	
		size = (int)ft_strlen(gm->map[i]);
		if (gm->m_width != size)
			(ft_putendl_fd("Error: invalid map shape",2), exit(-1));
		if (i == 0 || i == gm->m_height - 1)
		{
			j = -1;
			while (++j < size)
				if (gm->map[i][j] != '1')
					(ft_putendl_fd("Error: invalid up/down side", 2), exit(-1));
		}
		else if (gm->map[i][0] != '1' || gm->map[i][size - 1] != '1')
			(ft_putendl_fd("Error: invalid right/left side", 2), exit(-1));
	}
}

static void	map_elements_count(t_game_manager *gm,int *p_count,int *c_count,int *d_count)
{
	int	y;
	int	x;

	y = -1;
	while (++y < gm->m_height)
	{
		x = -1;
		while (++x < gm->m_width)
			if (gm->map[y][x] == 'P')
				((*p_count)++, gm->player_x = x, gm->player_y = y);
			else if (gm->map[y][x] == 'E')
				(*d_count)++;
			else if (gm->map[y][x] == 'C')
				(*c_count)++;
	}
}
void	map_validate_path(t_game_manager *gm, int x, int y)
{

	if (gm->map[y][x] == '1' || gm->map[y][x] == 's' || gm->map[y][x] == 'e'
		|| gm->map[y][x] == 'c')
		return ;
	if (gm->map[y][x] == 'P' || gm->map[y][x] == '0')
		gm->map[y][x] = 's';
	else if (gm->map[y][x] == 'E')
		(gm->map[y][x] = 'e', gm->found_exit++);
	else if (gm->map[y][x] == 'C')
		(gm->map[y][x] = 'c', gm->found_coins++);
	
	
	map_validate_path(gm, x + 1, y);
	map_validate_path(gm, x - 1, y);
	map_validate_path(gm, x , y + 1);
	map_validate_path(gm, x , y - 1);
}

void init_map(t_game_manager *gm,char *name)
{
	int	p_count;
	int	c_count;
	int	d_count;
	
	(p_count = 0, c_count = 0, d_count = 0);
	map_validate_name(name);
	map_load(gm, name);
	map_validate_shape(gm);
	map_elements_count(gm, &p_count, &c_count, &d_count);
	if (p_count != 1 || c_count == 0 || d_count != 1)
		(ft_putendl_fd("Error: invalid map elements count", 2), exit(-1));
	gm->coins_count  = c_count;
	map_validate_path(gm, gm->player_x, gm->player_y);
	if (gm->found_exit == 1)
		ft_putendl_fd("exit found",1);
	else
		ft_putendl_fd("exit not founf", 1);
	if (gm->coins_count == gm->found_coins)
		ft_putendl_fd("found all coins",1);
	else
		ft_putendl_fd("didnt find all coins", 1);
}
