/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: massrayb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 20:49:21 by massrayb          #+#    #+#             */
/*   Updated: 2025/01/21 16:25:32 by massrayb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	draw_static_img(t_game_manager *gm, char sprite, int x, int y)
{
	if (sprite == '1')
		mlx_put_image_to_window(gm->mlx, gm->win, gm->wall, x * 32, y * 32);
	else if (sprite == 'c')
	{
		mlx_put_image_to_window(gm->mlx, gm->win, gm->space, x * 32, y * 32);
		mlx_put_image_to_window(gm->mlx, gm->win, gm->coin, x * 32, y * 32);
	}
	else if (sprite == 's')
		mlx_put_image_to_window(gm->mlx, gm->win, gm->space, x * 32, y * 32);
	else if (sprite == 'e')
	{
		mlx_put_image_to_window(gm->mlx, gm->win, gm->space, x * 32, y * 32);
		mlx_put_image_to_window(gm->mlx, gm->win, gm->door, x * 32, y * 32);
	}
}

void	draw_palyer_img(t_game_manager *gm)
{
	// void	*s = NULL;

	// if (gm->move_dir == 1)
	// 	s = gm->plr_u;
	// else if (gm->move_dir == 2)
	// 	s = gm->plr_r;
	// else if (gm->move_dir == 3)
	// 	s = gm->plr_d;
	// else if (gm->move_dir == 4)
	// 	s = gm->plr_l;
	mlx_put_image_to_window(gm->mlx, gm->win, gm->plr, gm->plr_x, gm->plr_y);
}

int	update(t_game_manager *gm)
{
	int	y;
	int x;

	move_player(gm);
	y = -1;
	while (++y < gm->m_height)
	{
		x = -1;
		while (++x < gm->m_width)
			draw_static_img(gm , gm->map[y][x], x, y);
	}
	draw_palyer_img(gm);
	return (0);
}

void init_game(t_game_manager *gm)
{
	gm->mlx = mlx_init();
	if (gm->mlx == NULL)
		(ft_putendl_fd("Error: couldn't init mlx", 2), exit(-1));
	gm->win = mlx_new_window(gm->mlx, gm->m_width * 32, gm->m_height * 32, "so_long");
	if (gm->win == NULL)
		(ft_putendl_fd("Error: couldn't create window", 2), exit(-1));
}