/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: massrayb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:05:35 by massrayb          #+#    #+#             */
/*   Updated: 2025/01/24 15:57:15 by massrayb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"
#include <stdio.h>

void	rand_enemy_dir(t_game_manager *gm)
{
	int	dir;
	int	i;

	i = -1;
	while(gm->enemies[++i].pos.x)
	{
		dir = (rand() % 4) + 1;
		if (dir == gm->enemies[i].dir)
			dir++;
		if (dir > 4)
			dir = 1;
		gm->enemies[i].dir = dir;
	}
}

int validate_move(t_game_manager *gm, int x, int y)
{
	int	i;
	if (gm->map[y][x] == '1')
		return (0);
	i = -1;
	while (gm->enemies[++i].pos.x != 0)
		if (gm->enemies[i].pos.x == x && gm->enemies[i].pos.y == y)
			return (0);
	return (1);
}

void	move_enemy(t_game_manager *gm)
{
	int	i;
	int new_x;
	int new_y;

	i = -1;
	while (gm->enemies[++i].pos.x != 0)
	{
		new_x = gm->enemies[i].pos.x;
		new_y = gm->enemies[i].pos.y;
		
		if (gm->p_pos.x - new_x <= 5 && gm->p_pos.y - new_y <= 5)
		{
			move_to_kill(gm);
		}
		else 
		{
			if (gm->enemies[i].delay <= 0)
			{
				rand_enemy_dir(gm);
				gm->enemies[i].delay = (rand() % 10) + 3;
			}
			else
			{
				if (gm->enemies[i].dir == UP)
					new_y -= 1;
				else if (gm->enemies[i].dir == DOWN)
					new_y += 1;
				else if (gm->enemies[i].dir == RIGHT)
					new_x += 1;
				else if (gm->enemies[i].dir == LEFT)
					new_x -= 1;
				if (validate_move(gm, new_x, new_y) == 1)
				{
					gm->enemies[i].pos.x = new_x;
					gm->enemies[i].pos.y = new_y;
				}
				else
					gm->enemies[i].delay = 0;
				gm->enemies[i].delay--;
			}
		}
	}
}
