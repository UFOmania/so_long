/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: massrayb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 13:16:54 by massrayb          #+#    #+#             */
/*   Updated: 2025/02/03 15:21:56 by massrayb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/sprite.h"

#include <stdio.h>

static void	sprites_load_player_r_l(t_game_manager *gm)
{
	int		i;
	char	*name;
	char	*num;

	i = -1;
	while (++i < SPRITE_COUNT)
	{
		num = ft_itoa(i);
		name = ft_strjoin("player_l_", num);
		free(num);
		gm->plr_l[i] = load_img(gm, name);
		free(name);
	}
	i = -1;
	while (++i < SPRITE_COUNT)
	{
		num = ft_itoa(i);
		name = ft_strjoin("player_r_", num);
		free(num);
		gm->plr_r[i] = load_img(gm, name);
		free(name);
	}
}

static void	sprites_load_player_u_d(t_game_manager *gm)
{
	int		i;
	char	*name;
	char	*num;

	i = -1;
	while (++i < SPRITE_COUNT)
	{
		num = ft_itoa(i);
		name = ft_strjoin("player_d_", num);
		free(num);
		gm->plr_d[i] = load_img(gm, name);
		free(name);
	}
	i = -1;
	while (++i < SPRITE_COUNT)
	{
		num = ft_itoa(i);
		name = ft_strjoin("player_u_", num);
		free(num);
		gm->plr_u[i] = load_img(gm, name);
		free(name);
	}
}

static void	sprite_load_enemy(t_game_manager *gm)
{
	int		i;
	char	*name;
	char	*num;

	i = -1;
	while (++i < SPRITE_COUNT)
	{
		num = ft_itoa(i);
		name = ft_strjoin("enemy_", num);
		free(num);
		gm->enemy[i] = load_img(gm, name);
		free(name);
	}
}

static void	sprites_load(t_game_manager *gm)
{
	int	tmp;

	gm->wall = mlx_xpm_file_to_image(gm->mlx, "bonus/sprites/wall.xpm", \
	&tmp, &tmp);
	gm->coin = mlx_xpm_file_to_image(gm->mlx, "bonus/sprites/coin.xpm", \
	&tmp, &tmp);
	sprites_load_player_r_l(gm);
	sprites_load_player_u_d(gm);
	sprite_load_enemy(gm);
	gm->space = mlx_xpm_file_to_image(gm->mlx, "bonus/sprites/space.xpm", \
	&tmp, &tmp);
	gm->door = mlx_xpm_file_to_image(gm->mlx, "bonus/sprites/door.xpm", \
	&tmp, &tmp);
}

void	init_sprites(t_game_manager *gm)
{
	sprites_load(gm);
	sprites_validate(gm);
	gm->plr = gm->plr_r[0];
}
