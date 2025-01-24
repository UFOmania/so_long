/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: massrayb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 09:50:49 by massrayb          #+#    #+#             */
/*   Updated: 2025/01/22 19:56:00 by massrayb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static	void	clear_images(t_game_manager *gm)
{
	if (gm->coin)
		mlx_destroy_image(gm->mlx, gm->coin);
	if (gm->door)
		mlx_destroy_image(gm->mlx, gm->door);
	if (gm->plr_d)
		mlx_destroy_image(gm->mlx, gm->plr_d);
	if (gm->plr_u)
		mlx_destroy_image(gm->mlx, gm->plr_u);
	if (gm->plr_l)
		mlx_destroy_image(gm->mlx, gm->plr_l);
	if (gm->plr_r)
		mlx_destroy_image(gm->mlx, gm->plr_r);
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
