/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: massrayb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 13:26:15 by massrayb          #+#    #+#             */
/*   Updated: 2025/01/19 20:48:52 by massrayb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include "../_libft/libft.h"
#include "../_gnl/get_next_line.h"
#include <fcntl.h>
#include <errno.h>
#include <string.h>


typedef struct s_game_manager
{
	char	**map;
	int		m_height;
	int		m_width;
	int		player_x;
	int		player_y;
	int		coins_count;
	int		found_exit;
	int		found_coins;
	
}			t_game_manager;

void	init_map(t_game_manager *gm, char *name);
#endif