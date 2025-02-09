/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: massrayb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 09:32:20 by massrayb          #+#    #+#             */
/*   Updated: 2025/02/09 12:31:01 by massrayb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "so_long.h"

# define MAX_WIDTH 80
# define MAX_HEIGHT 44

void	map_calculate_height(t_game_manager *gm, char *name);

#endif
