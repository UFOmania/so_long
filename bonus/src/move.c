/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: massrayb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:41:43 by massrayb          #+#    #+#             */
/*   Updated: 2025/02/03 15:10:36 by massrayb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	check_for_collision(t_game_manager *gm, int x, int y)
{
	int	i;

	if (gm->map[y][x] == '1')
		return (0);
	else if (gm->map[y][x] == 'c')
	{
		gm->collected_coins++;
		gm->map[y][x] = 's';
		return (1);
	}
	else if (gm->map[y][x] == 'e')
	{
		if (gm->door_open == 1)
			clear_game(gm, "player won", 0);
		return (1);
	}
	i = -1;
	while (gm->enemies[++i].pos.x != 0)
	{
		if (gm->enemies[i].pos.x == x && gm->enemies[i].pos.y == y)
			clear_game(gm, "player lost", 0);
	}
	return (1);
}

static int	player_get_new_x(t_game_manager *gm)
{
	int	new_x;

	new_x = gm->p_pos.x / 32;
	if (gm->move_dir == UP)
		new_x = gm->p_pos.x / 32;
	else if (gm->move_dir == DOWN)
		new_x = gm->p_pos.x / 32;
	else if (gm->move_dir == RIGHT)
		new_x = (gm->p_pos.x / 32) + 1;
	else if (gm->move_dir == LEFT)
		new_x = (gm->p_pos.x / 32) - 1;
	return (new_x);
}

static int	player_get_new_y(t_game_manager *gm)
{
	int	new_y;

	new_y = gm->p_pos.y / 32;
	if (gm->move_dir == UP)
		new_y = (gm->p_pos.y / 32) - 1;
	else if (gm->move_dir == DOWN)
		new_y = (gm->p_pos.y / 32) + 1;
	else if (gm->move_dir == RIGHT)
		new_y = gm->p_pos.y / 32;
	else if (gm->move_dir == LEFT)
		new_y = gm->p_pos.y / 32;
	return (new_y);
}

void	move_player(t_game_manager *gm)
{
	int	new_x;
	int	new_y;

	new_x = player_get_new_x(gm);
	new_y = player_get_new_y(gm);
	if (check_for_collision(gm, new_x, new_y) == 1)
	{
		if (gm->move_dir != 0)
			gm->moves_counter++;
		gm->p_pos.x = new_x * 32;
		gm->p_pos.y = new_y * 32;
	}
	gm->move_dir = 0;
}
