/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: massrayb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 13:16:54 by massrayb          #+#    #+#             */
/*   Updated: 2025/01/22 09:54:10 by massrayb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	sprites_load(t_game_manager *gm)
{
	int	tmp;

	gm->wall = mlx_xpm_file_to_image(gm->mlx, "sprites/wall.xpm", &tmp, &tmp);
	gm->coin = mlx_xpm_file_to_image(gm->mlx, "sprites/coin.xpm", &tmp, &tmp);
	gm->plr_l = mlx_xpm_file_to_image(gm->mlx, "sprites/player_l.xpm", \
	&tmp, &tmp);
	gm->plr_r = mlx_xpm_file_to_image(gm->mlx, "sprites/player_r.xpm", \
	&tmp, &tmp);
	gm->plr_u = mlx_xpm_file_to_image(gm->mlx, "sprites/player_u.xpm", \
	&tmp, &tmp);
	gm->plr_d = mlx_xpm_file_to_image(gm->mlx, "sprites/player_d.xpm", \
	&tmp, &tmp);
	gm->space = mlx_xpm_file_to_image(gm->mlx, "sprites/space.xpm", &tmp, &tmp);
	gm->door = mlx_xpm_file_to_image(gm->mlx, "sprites/door.xpm", &tmp, &tmp);
}

static void	sprites_validate(t_game_manager *gm)
{
	if (gm->wall == NULL)
		clear_game(gm, "Error: coudn't load wall sprite\n", -1);
	if (gm->coin == NULL)
		clear_game(gm, "Error: coudn't load coin sprite\n", -1);
	if (gm->plr_l == NULL)
		clear_game(gm, "Error: coudn't load player_l sprite\n", -1);
	if (gm->plr_r == NULL)
		clear_game(gm, "Error: coudn't load player_r sprite\n", -1);
	if (gm->plr_d == NULL)
		clear_game(gm, "Error: coudn't load player_d sprite\n", -1);
	if (gm->plr_u == NULL)
		clear_game(gm, "Error: coudn't load player_u sprite\n", -1);
	if (gm->space == NULL)
		clear_game(gm, "Error: coudn't load space sprite\n", -1);
	if (gm->space == NULL)
		clear_game(gm, "Error: coudn't load door sprite\n", -1);
}

void	init_sprites(t_game_manager *gm)
{
	sprites_load(gm);
	sprites_validate(gm);
	gm->plr = gm->plr_r;
}
