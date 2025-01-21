/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: massrayb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 13:32:02 by massrayb          #+#    #+#             */
/*   Updated: 2025/01/21 16:19:05 by massrayb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

#include <stdio.h>
int	read_inputs(int key_code, t_game_manager *gm)
{
	if (key_code == 13)
		gm->move_dir = 1;
	else if (key_code == 2)
		gm->move_dir = 2;
	else if (key_code == 1)
		gm->move_dir = 3;
	else if (key_code == 0)
		gm->move_dir = 4;
	else if (key_code == 53)
		gm->exit_game = 1;
	return (0);
}

int main()
{
	t_game_manager gm = (t_game_manager){0};
	init_map(&gm, "./maps/map.ber");
	init_game(&gm);
	init_sprites(&gm);
	gm.plr = gm.plr_r;
	mlx_key_hook(gm.win, read_inputs, &gm);
	mlx_loop_hook(gm.mlx, update, &gm);
	mlx_loop(gm.mlx);
	system("leaks so_long");
	return 0;
}