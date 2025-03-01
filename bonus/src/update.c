/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: massrayb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 20:49:21 by massrayb          #+#    #+#             */
/*   Updated: 2025/02/08 17:14:22 by massrayb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	put_img(t_game_manager *gm, void *img, int x, int y)
{
	mlx_put_image_to_window(gm->mlx, gm->win, img, x, y);
}

static void	draw_static_img(t_game_manager *gm, char sprite, int x, int y)
{
	if (sprite == '1')
		put_img(gm, gm->wall, x * 32, y * 32);
	else
		put_img(gm, gm->space, x * 32, y * 32);
	if (sprite == 'c')
		put_img(gm, gm->coin, x * 32, y * 32);
	else if (sprite == 'e')
	{
		if (gm->door_open == 1)
			put_img(gm, gm->door[1], x * 32, y * 32);
		else
			put_img(gm, gm->door[0], x * 32, y * 32);
	}
}

static void	draw_palyer_img(t_game_manager *gm)
{
	if (gm->player_frame == SPRITE_COUNT)
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
	int	i;

	if (gm->enemy_frame == SPRITE_COUNT)
		gm->enemy_frame = 0;
	i = -1;
	while (gm->enemies[++i].pos.x != 0)
	{
		put_img(gm, gm->enemy[gm->enemy_frame], gm->enemies[i].pos.x * 32, \
		gm->enemies[i].pos.y * 32);
	}
	if (gm->fps % 5 == 0)
		gm->enemy_frame++;
}

int	update(t_game_manager *gm)
{
	int		y;
	int		x;
	char	*moves_counter;

	gm->fps++;
	move_player(gm);
	if (gm->fps % 20 == 0)
		move_enemy(gm);
	y = -1;
	while (++y < gm->m_height)
	{
		x = -1;
		while (++x < gm->m_width)
			draw_static_img(gm, gm->map[y][x], x, y);
	}
	draw_palyer_img(gm);
	draw_enemy_img(gm);
	if (!gm->door_open && gm->collected_coins == gm->coins_count)
		gm->door_open = 1;
	moves_counter = ft_itoa(gm->moves_counter);
	if (moves_counter)
		mlx_string_put(gm->mlx, gm->win, 2, 2, 3800852, moves_counter);
	free(moves_counter);
	return (0);
}
