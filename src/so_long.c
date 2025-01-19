/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: massrayb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 13:32:02 by massrayb          #+#    #+#             */
/*   Updated: 2025/01/19 21:50:25 by massrayb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../includes/map.h"

int main()
{
	t_game_manager gm = (t_game_manager){0};
	init_map(&gm, "./maps/map.ber");
	// char **map = gm.map;
	// while (*map)
	// 	(ft_putstr_fd(*map, 1), map++);
	
	// system("leaks so_long");
	return 0;
}