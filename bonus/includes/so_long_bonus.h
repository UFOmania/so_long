/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: massrayb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:23:08 by massrayb          #+#    #+#             */
/*   Updated: 2025/01/24 15:05:21 by massrayb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../../_libft/libft.h"
# include "../../_gnl/get_next_line.h"
# include <mlx.h>
# include <errno.h>
# include <string.h>
# include <fcntl.h>

#include <stdio.h>

#define UP 1
#define DOWN 3
#define RIGHT 2
#define LEFT 4

typedef struct	s_vec2
{
	int	x;
	int	y;
}				t_vec2;


typedef struct	s_enemy
{
	t_vec2	pos;
	int		dir;
	int		delay;
}				t_enemy;

# define sprite_count 9

typedef struct	s_game_manager
{
	char	**map;
	t_enemy	*enemies;
	int		m_height;
	int		m_width;
	int		move_dir;
	void	*mlx;
	void	*win;
	int		coins_count;
	int		collected_coins;
	int		door_open;
	void	*plr;
	void	*plr_l[sprite_count];
	void	*plr_r[sprite_count];
	void	*plr_u[sprite_count];
	void	*plr_d[sprite_count];
	void	*enemy[sprite_count];
	int		anim_dir;
	int		player_frame;
	int		enemy_frame;
	void	*space;
	void	*door;
	void	*wall;
	void	*coin;
	t_vec2	p_pos;
	int		moves_counter;
	int		fps;
}				t_game_manager;

void	clear_game(t_game_manager *gm, char *msg, int code);
int		close_game_event(t_game_manager *gm);
void	init_map(t_game_manager *gm, char *name);
void	init_sprites(t_game_manager *gm);
int		update(t_game_manager *gm);
void	move_player(t_game_manager *gm);
void	move_enemy(t_game_manager *gm);

#endif