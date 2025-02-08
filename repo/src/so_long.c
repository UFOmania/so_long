/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: massrayb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 13:32:02 by massrayb          #+#    #+#             */
/*   Updated: 2025/02/08 21:14:31 by massrayb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	read_inputs(int key_code, t_game_manager *gm)
{
	if (key_code == 13)
		gm->move_dir = 1;
	else if (key_code == 2)
		gm->move_dir = 2;
	else if (key_code == 1)
		gm->move_dir = 3;
	else if (key_code == 0)
		gm->move_dir = 4;
	else if (key_code == 53)
		close_game_event(gm);
	return (0);
}

static void	init_game(t_game_manager *gm)
{
	gm->mlx = mlx_init();
	if (gm->mlx == NULL)
		clear_game(gm, "Error: problem with mlx_init()\n", -1);
	gm->win = mlx_new_window(gm->mlx, gm->m_width * 32, \
	gm->m_height * 32, "so_long");
	if (gm->win == NULL)
		clear_game(gm, "Error: problem with mlx_new_window()\n", -1);
}

static void	map_validate_name(char *name)
{
	char	*dot;

	dot = ft_strrchr(name, '.');
	if (!dot || ft_strnstr(dot, ".ber", 4) == NULL || dot[4] != '\0')
		(ft_putendl_fd("Error : invalid map name", 2), exit(-1));
}

int	main(int ac, char **av)
{
	t_game_manager	gm;

	if (ac != 2)
		return (ft_putendl_fd("Error: please enter map.ber path only", 2), 1);
	gm = (t_game_manager){0};
	map_validate_name(av[1]);
	init_map(&gm, av[1]);
	init_game(&gm);
	init_sprites(&gm);
	mlx_key_hook(gm.win, read_inputs, &gm);
	mlx_hook(gm.win, 17, 0, close_game_event, &gm);
	mlx_loop_hook(gm.mlx, update, &gm);
	mlx_loop(gm.mlx);
	return (0);
}
