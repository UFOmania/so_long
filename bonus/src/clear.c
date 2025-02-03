/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: massrayb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 09:50:49 by massrayb          #+#    #+#             */
/*   Updated: 2025/02/03 15:05:52 by massrayb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static	void	clear_images(t_game_manager *gm)
{
	int	i;

	if (gm->coin)
		mlx_destroy_image(gm->mlx, gm->coin);
	if (gm->door)
		mlx_destroy_image(gm->mlx, gm->door);
	i = -1;
	while (++i < SPRITE_COUNT)
	{
		if (gm->plr_d[i])
			mlx_destroy_image(gm->mlx, gm->plr_d[i]);
		if (gm->plr_u[i])
			mlx_destroy_image(gm->mlx, gm->plr_u[i]);
		if (gm->plr_l[i])
			mlx_destroy_image(gm->mlx, gm->plr_l[i]);
		if (gm->plr_r[i])
			mlx_destroy_image(gm->mlx, gm->plr_r[i]);
		if (gm->enemy[i])
			mlx_destroy_image(gm->mlx, gm->enemy[i]);
	}
	if (gm->wall)
		mlx_destroy_image(gm->mlx, gm->wall);
	if (gm->space)
		mlx_destroy_image(gm->mlx, gm->space);
}

void	clear_game(t_game_manager *gm, char *msg, int code)
{
	int	y;
	int	fd;

	fd = 1;
	if (code == -1)
		fd = 2;
	ft_putendl_fd(msg, fd);
	y = -1;
	while (++y < gm->m_height)
		free(gm->map[y]);
	free(gm->map);
	free(gm->enemies);
	if (gm->win)
	{
		mlx_destroy_window(gm->mlx, gm->win);
		clear_images(gm);
	}
	exit(code);
}

int	close_game_event(t_game_manager *gm)
{
	clear_game(gm, "game closed !!!\n", 0);
	return (0);
}
