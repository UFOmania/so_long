/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: massrayb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 20:49:21 by massrayb          #+#    #+#             */
/*   Updated: 2025/01/23 19:02:00 by massrayb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	draw_static_img(t_game_manager *gm, char sprite, int x, int y)
{
	if (sprite == '1')
		mlx_put_image_to_window(gm->mlx, gm->win, gm->wall, x * 32, y * 32);
	else
		mlx_put_image_to_window(gm->mlx, gm->win, gm->space, x * 32, y * 32);
	if (sprite == 'c')
		mlx_put_image_to_window(gm->mlx, gm->win, gm->coin, x * 32, y * 32);
	else if (sprite == 'e')
		mlx_put_image_to_window(gm->mlx, gm->win, gm->door, x * 32, y * 32);
}

static void	put_img(t_game_manager *gm, void *img, int x, int y)
{
	mlx_put_image_to_window(gm->mlx, gm->win, img, x, y);
}

static void	draw_palyer_img(t_game_manager *gm)
{
	if (gm->player_frame == sprite_count)
		gm->player_frame = 0;
	if (gm->anim_dir == 3)
		put_img(gm, gm->plr_d[gm->player_frame], gm->p_pos.x, gm->p_pos.y);
	else if (gm->anim_dir == 1)
		put_img(gm, gm->plr_u[gm->player_frame], gm->p_pos.x, gm->p_pos.y);
	else if (gm->anim_dir == 2)
		put_img(gm, gm->plr_r[gm->player_frame], gm->p_pos.x, gm->p_pos.y);
	else if (gm->anim_dir == 4)
		put_img(gm, gm->plr_l[gm->player_frame], gm->p_pos.x, gm->p_pos.y);
	if (gm->fps % 8 == 0)
		gm->player_frame++;
}

static void	draw_enemy_img(t_game_manager *gm)
{
	int i;

	if (gm->enemy_frame == sprite_count)
		gm->enemy_frame = 0;
	i = -1;
	while (gm->enemies[++i].pos.x != 0)
	{
		put_img(gm, gm->enemy[gm->enemy_frame], gm->enemies[i].pos.x * 32, gm->enemies[i].pos.y * 32);
	}
	if (gm->fps % 5 == 0)
		gm->enemy_frame++;
}

static void	door_update(t_game_manager *gm)
{
	if (!gm->door_open && gm->collected_coins == gm->coins_count)
		gm->door_open = 1;
}



int	update(t_game_manager *gm)
{
	int	y;
	int	x;

	if (gm->fps == INT_MAX)
		gm->fps = 0;
	gm->fps++;
	move_player(gm);
	y = -1;
	while (++y < gm->m_height)
	{
		x = -1;
		while (++x < gm->m_width)
			draw_static_img(gm, gm->map[y][x], x, y);
	}
	draw_palyer_img(gm);
	draw_enemy_img(gm);
	door_update(gm);
	return (0);
}
