/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: massrayb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 15:26:48 by massrayb          #+#    #+#             */
/*   Updated: 2025/01/11 15:59:15 by massrayb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void	load_map(Map **map_info)
{
	int fd = open("map", O_RDONLY);
	if (fd == -1)
	{
		perror("loading map error");
		exit(-1);
	}
	*map_info = malloc(sizeof(Map));
	t_list	*map;
	t_list	*node_placer;
	char	*line;
	node_placer = ft_lstnew(NULL);
	map = node_placer;
	while (line)
	{
		line  = get_next_line(fd);
		node_placer->content = line;
		node_placer->next = ft_lstnew(NULL);
		node_placer = node_placer->next;
	}
	close(fd);
	(*map_info)->map = map;
}

void	get_map_dimensions(Map **map_info)
{
	int width;
	int	height;

	height = 0;
	t_list *map;
	map = (*map_info)->map;
	width = map_row_len(map->content);
	if (width == -1)
	{
		//return a error message
	}
	while (map->content)
	{
		if(width != map_row_len(map->content))
			destroy_map(map_info, "invalid map dimensions\n", -1);
		map = map->next;
		height++;
	}
	(*map_info)->height = height;
	(*map_info)->width = width;
}

void validate_map_boarders(Map **map_info)
{
	t_list	*map;
	char	*row;
	int		i;
	int		j;

	i = 0;
	j = 0;
	map = (*map_info)->map;
	while (i < (*map_info)->height)
	{
		row = (char *)map->content;
		if (i == 0 || i == (*map_info)->height - 1)
		{
			while (row[j] == '1')
				j++;
			if(j != (*map_info)->width)
				destroy_map(map_info, "invalid map : upper or lower wall is not comlete\n", -1);
		}
		else
			if (row[0] != '1' || row[(*map_info)->width - 1] != '1')
				destroy_map(map_info, "invalid map : right or left side is not complete\n", -1);
		map = map->next;
		i++;
	}
}

int main()
{
	Map	*map_info;

	load_map(&map_info);
	get_map_dimensions(&map_info);
	validate_map_boarders(&map_info);
	// system("leaks a.out");
	return (0);
}
