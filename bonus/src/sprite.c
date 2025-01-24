/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: massrayb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 13:16:54 by massrayb          #+#    #+#             */
/*   Updated: 2025/01/23 18:41:43 by massrayb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

#include <stdio.h>

static void	*load_img(t_game_manager *gm, char *name)
{
	int		i;
	void	*img;
	char	*prefex = "bonus/sprites/";
	char	*path;
	char	*tmp;

	path = ft_strjoin(prefex, name);
	tmp = path;
	path = ft_strjoin(path, ".xpm");
	img = mlx_xpm_file_to_image(gm->mlx, path, &i, &i);
	if (img == NULL)
	{
		free(path);
		free(tmp);
		ft_putstr_fd("Error: couldn't load sprite ", 2);
		clear_game(gm, name, -1);
	}
	free(path);
	free(tmp);
	return (img);
}

static void sprites_load_player_r_l(t_game_manager *gm)
{
	int		i;
	char	*name;
	char	*num;

	i = -1;
	while (++i < sprite_count)
	{
		num = ft_itoa(i);
		name = ft_strjoin("player_l_", num);
		free(num);
		gm->plr_l[i] = load_img(gm, name);
		free(name);
	}
	i = -1;
	while (++i < sprite_count)
	{
		num = ft_itoa(i);
		name = ft_strjoin("player_r_", num);
		free(num);
		gm->plr_r[i] = load_img(gm, name);
		free(name);
	}
}
static void sprites_load_player_u_d(t_game_manager *gm)
{
	int		i;
	char	*name;
	char	*num;

	i = -1;
	while (++i < sprite_count)
	{
		num = ft_itoa(i);
		name = ft_strjoin("player_d_", num);
		free(num);
		gm->plr_d[i] = load_img(gm, name);
		free(name);
	}
	i = -1;
	while (++i < sprite_count)
	{
		num = ft_itoa(i);
		name = ft_strjoin("player_u_", num);
		free(num);
		gm->plr_u[i] = load_img(gm, name);
		free(name);
	}
}

static void sprite_load_enemy(t_game_manager *gm)
{
	int		i;
	char	*name;
	char	*num;

	i = -1;
	while (++i < sprite_count)
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

	gm->wall = mlx_xpm_file_to_image(gm->mlx, "bonus/sprites/wall.xpm", &tmp, &tmp);
	gm->coin = mlx_xpm_file_to_image(gm->mlx, "bonus/sprites/coin.xpm", &tmp, &tmp);
	sprites_load_player_r_l(gm);
	sprites_load_player_u_d(gm);
	sprite_load_enemy(gm);
	gm->space = mlx_xpm_file_to_image(gm->mlx, "bonus/sprites/space.xpm", &tmp, &tmp);
	gm->door = mlx_xpm_file_to_image(gm->mlx, "bonus/sprites/door.xpm", &tmp, &tmp);
}

static void	sprites_validate(t_game_manager *gm)
{
	if (gm->wall == NULL)
		clear_game(gm, "Error: coudn't load wall sprite\n", -1);
	if (gm->coin == NULL)
		clear_game(gm, "Error: coudn't load coin sprite\n", -1);
	if (gm->plr_l[0] == NULL)
		clear_game(gm, "Error: coudn't load player_l sprite\n", -1);
	if (gm->plr_r[0] == NULL)
		clear_game(gm, "Error: coudn't load player_r sprite\n", -1);
	if (gm->plr_d[0] == NULL)
		clear_game(gm, "Error: coudn't load player_d sprite\n", -1);
	if (gm->plr_u[0] == NULL)
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
	gm->plr = gm->plr_r[0];
}
