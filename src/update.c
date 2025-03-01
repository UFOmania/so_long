/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: massrayb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 20:49:21 by massrayb          #+#    #+#             */
/*   Updated: 2025/02/08 19:51:50 by massrayb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	put_img(t_game_manager *gm, void *img, int x, int y)
{
	mlx_put_image_to_window(gm->mlx, gm->win, img, x, y);
}

static void	draw_static_img(t_game_manager *gm, char sprite, int x, int y)
{
	if (sprite == '1')
		put_img(gm, gm->wall, x * 32, y * 32);
	else if (sprite == 'c')
	{
		put_img(gm, gm->space, x * 32, y * 32);
		put_img(gm, gm->coin, x * 32, y * 32);
	}
	else if (sprite == 's')
		put_img(gm, gm->space, x * 32, y * 32);
	else if (sprite == 'e')
	{
		put_img(gm, gm->space, x * 32, y * 32);
		if (gm->door_open)
			put_img(gm, gm->door[1], x * 32, y * 32);
		else
			put_img(gm, gm->door[0], x * 32, y * 32);
	}
}

void	draw_palyer_img(t_game_manager *gm)
{
	mlx_put_image_to_window(gm->mlx, gm->win, gm->plr, gm->plr_x, gm->plr_y);
}

void	door_update(t_game_manager *gm)
{
	if (!gm->door_open && gm->collected_coins == gm->coins_count)
		gm->door_open = 1;
}

int	update(t_game_manager *gm)
{
	int	y;
	int	x;

	move_player(gm);
	y = -1;
	while (++y < gm->m_height)
	{
		x = -1;
		while (++x < gm->m_width)
			draw_static_img(gm, gm->map[y][x], x, y);
	}
	draw_palyer_img(gm);
	door_update(gm);
	return (0);
}
