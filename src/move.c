/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: massrayb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:41:43 by massrayb          #+#    #+#             */
/*   Updated: 2025/01/21 16:41:43 by massrayb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

#include "stdio.h"

static void	check_for_coin(t_game_manager *gm, int x, int y)
{
	printf("%p, %d, %d\n", gm, x, y);
	if (gm->map[y][x] == 'c')
	{
		gm->collected_coins++;
		gm->map[y][x] = 's';
	}
}

void	move_validate(t_game_manager *gm)
{
	int	y;
	int	x;

	y =  gm->plr_y / 32;
	x =  gm->plr_x / 32;
	if (gm->move_dir == 1 && gm->map[y - 1][x] != '1')
		(gm->plr_y -= 32, gm->plr = gm->plr_u, check_for_coin(gm, y - 1, x));
	else if (gm->move_dir == 3 && gm->map[y + 1][x] != '1')
		(gm->plr_y += 32, gm->plr = gm->plr_d, check_for_coin(gm, y + 1, x));
	else if (gm->move_dir == 2 && gm->map[y][x + 1] != '1')
		(gm->plr_x += 32, gm->plr = gm->plr_r, check_for_coin(gm, y, x + 1));
	else if (gm->move_dir == 4 && gm->map[y][x - 1] != '1')
		(gm->plr_x -= 32, gm->plr = gm->plr_l, check_for_coin(gm, y, x - 1));
}

void	move_player(t_game_manager *gm)
{
	if (gm->move_dir != 0)
		move_validate(gm);
	gm->move_dir = 0;
}