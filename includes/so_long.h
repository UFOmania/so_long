/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: massrayb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 13:26:15 by massrayb          #+#    #+#             */
/*   Updated: 2025/01/21 16:33:44 by massrayb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include <mlx.h>
#include "../_libft/libft.h"
#include "../_gnl/get_next_line.h"
#include <fcntl.h>
#include <errno.h>
#include <string.h>


typedef struct s_game_manager
{
	char	**map;
	int		m_height;
	int		m_width;
	int		plr_x;
	int		plr_y;
	int		coins_count;
	int		found_exit;
	int		found_coins;
	void	*mlx;
	void	*win;
	void	*wall;
	void	*coin;
	int		move_dir;
	void	*plr;
	void	*plr_l;
	void	*plr_r;
	void	*plr_u;
	void	*plr_d;
	void	*space;
	void	*door;
	int		exit_game;
	int		collected_coins;
	
	
}			t_game_manager;

void	init_map(t_game_manager *gm, char *name);
void	init_game(t_game_manager *gm);
void	init_sprites(t_game_manager *gm);
int		update(t_game_manager *gm);
void	move_player(t_game_manager *gm);

#endif