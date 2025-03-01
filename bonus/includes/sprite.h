/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: massrayb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:16:34 by massrayb          #+#    #+#             */
/*   Updated: 2025/02/15 12:15:09 by massrayb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITE_H
# define SPRITE_H

# include "so_long_bonus.h"

void	*load_img(t_game_manager *gm, char *name);
void	sprites_validate(t_game_manager *gm);

#endif