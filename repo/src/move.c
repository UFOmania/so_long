/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: massrayb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:41:43 by massrayb          #+#    #+#             */
/*   Updated: 2025/02/03 15:27:41 by massrayb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_for_collision(t_game_manager *gm, int x, int y)
{
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
	return (1);
}

void	update_anim(t_game_manager *gm)
{
	if (gm->move_dir == 1)
		gm->plr = gm->plr_u;
	else if (gm->move_dir == 3)
		gm->plr = gm->plr_d;
	else if (gm->move_dir == 2)
		gm->plr = gm->plr_r;
	else if (gm->move_dir == 4)
		gm->plr = gm->plr_l;
}

static int	player_get_new_x(t_game_manager *gm)
{
	int	new_x;

	new_x = gm->plr_x / 32;
	if (gm->move_dir == 1)
		new_x = gm->plr_x / 32;
	else if (gm->move_dir == 3)
		new_x = gm->plr_x / 32;
	else if (gm->move_dir == 2)
		new_x = (gm->plr_x / 32) + 1;
	else if (gm->move_dir == 4)
		new_x = (gm->plr_x / 32) - 1;
	return (new_x);
}

static int	player_get_new_y(t_game_manager *gm)
{
	int	new_y;

	new_y = gm->plr_y / 32;
	if (gm->move_dir == 1)
		new_y = (gm->plr_y / 32) - 1;
	else if (gm->move_dir == 3)
		new_y = (gm->plr_y / 32) + 1;
	else if (gm->move_dir == 2)
		new_y = gm->plr_y / 32;
	else if (gm->move_dir == 4)
		new_y = gm->plr_y / 32;
	return (new_y);
}

void	move_player(t_game_manager *gm)
{
	int	new_x;
	int	new_y;

	new_x = player_get_new_x(gm);
	new_y = player_get_new_y(gm);
	update_anim(gm);
	if (check_for_collision(gm, new_x, new_y) == 1)
	{
		gm->plr_x = new_x * 32;
		gm->plr_y = new_y * 32;
		if (gm->move_dir != 0)
		{
			ft_putnbr_fd(++gm->moves_counter, 1);
			ft_putendl_fd("", 1);
		}
	}
	gm->move_dir = 0;
}
