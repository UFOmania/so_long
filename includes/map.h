/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: massrayb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 09:32:20 by massrayb          #+#    #+#             */
/*   Updated: 2025/03/06 22:52:06 by massrayb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "so_long.h"

# define MAX_WIDTH 81
# define MAX_HEIGHT 44

void	map_calculate_height(t_game_manager *gm, char *name);
void	map_validate_dimensions(t_game_manager *gm);

#endif
