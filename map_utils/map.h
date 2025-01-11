/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: massrayb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 15:49:05 by massrayb          #+#    #+#             */
/*   Updated: 2025/01/11 16:01:38 by massrayb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
#define MAP_H

#include "../utils/get_next_line.h"
#include "../so_long.h"
#include "../utils/libft.h"

typedef struct {
	t_list 	*map;
	int		width;
	int		height;
} Map;

int		map_row_len(char *row);
void	destroy_map(Map **map_info, char *msg, int exit_no);

#endif