/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: massrayb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 09:32:20 by massrayb          #+#    #+#             */
/*   Updated: 2025/02/08 21:13:55 by massrayb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "so_long_bonus.h"

# define MAX_WIDTH 80
# define MAX_HEIGHT 44

typedef struct s_celements
{
	int	p_count;
	int	c_count;
	int	d_count;
	int	t_count;
	int	found_exit;
	int	found_coins;
}				t_elements;

void	map_calculate_height(t_game_manager *gm, char *name);
void	enemy_generate_list(t_game_manager *gm, int size);
void	map_validate_dimensions(t_game_manager *gm);

#endif
