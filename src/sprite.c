/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: massrayb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 13:16:54 by massrayb          #+#    #+#             */
/*   Updated: 2025/01/21 15:22:34 by massrayb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	sprites_load(t_game_manager *gm)
{
	int tmp;

	gm->wall = mlx_xpm_file_to_image(gm->mlx, "sprites/wall.xpm", &tmp, &tmp);
	gm->coin = mlx_xpm_file_to_image(gm->mlx, "sprites/coin.xpm", &tmp, &tmp);
	gm->plr_l = mlx_xpm_file_to_image(gm->mlx, "sprites/player_l.xpm", &tmp, &tmp);
	gm->plr_r = mlx_xpm_file_to_image(gm->mlx, "sprites/player_r.xpm", &tmp, &tmp);
	gm->plr_u = mlx_xpm_file_to_image(gm->mlx, "sprites/player_u.xpm", &tmp, &tmp);
	gm->plr_d = mlx_xpm_file_to_image(gm->mlx, "sprites/player_d.xpm", &tmp, &tmp);
	gm->space = mlx_xpm_file_to_image(gm->mlx, "sprites/space.xpm", &tmp, &tmp);
	gm->door = mlx_xpm_file_to_image(gm->mlx, "sprites/door.xpm", &tmp, &tmp);

}

void	sprites_validate(t_game_manager *gm)
{
	if (gm->wall == NULL)
		(ft_putendl_fd("Error: coudn't load wall sprite", 2), exit(-1));
	if (gm->coin == NULL)
		(ft_putendl_fd("Error: coudn't load coin sprite", 2), exit(-1));
	if (gm->plr_l == NULL)
		(ft_putendl_fd("Error: coudn't load player_l sprite", 2), exit(-1));
	if (gm->plr_r == NULL)
		(ft_putendl_fd("Error: coudn't load player_r sprite", 2), exit(-1));
	if (gm->plr_d == NULL)
		(ft_putendl_fd("Error: coudn't load player_d sprite", 2), exit(-1));
	if (gm->plr_u == NULL)
		(ft_putendl_fd("Error: coudn't load player_u sprite", 2), exit(-1));
	if (gm->space == NULL)
		(ft_putendl_fd("Error: coudn't load space sprite", 2), exit(-1));
	if (gm->space == NULL)
		(ft_putendl_fd("Error: coudn't load door sprite", 2), exit(-1));

}

void	init_sprites(t_game_manager *gm)
{
	sprites_load(gm);
	sprites_validate(gm);
}