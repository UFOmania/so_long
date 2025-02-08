/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: massrayb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:16:03 by massrayb          #+#    #+#             */
/*   Updated: 2025/02/04 15:14:19 by massrayb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/sprite.h"

void	*load_img(t_game_manager *gm, char *name)
{
	int		i;
	void	*img;
	char	*prefex;
	char	*path;
	char	*tmp;

	prefex = "bonus/sprites/";
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

void	sprites_validate(t_game_manager *gm)
{
	int	i;

	if (gm->wall == NULL)
		clear_game(gm, "Error: coudn't load wall sprite\n", -1);
	if (gm->coin == NULL)
		clear_game(gm, "Error: coudn't load coin sprite\n", -1);
	if (gm->space == NULL)
		clear_game(gm, "Error: coudn't load space sprite\n", -1);
	if (gm->door[0] == NULL || gm->door[1] == NULL)
		clear_game(gm, "Error: coudn't load door sprite\n", -1);
	i = -1;
	while (++i < SPRITE_COUNT)
	{
		if (gm->plr_l[i] == NULL)
			clear_game(gm, "Error: coudn't load player_l sprite\n", -1);
		if (gm->plr_r[i] == NULL)
			clear_game(gm, "Error: coudn't load player_r sprite\n", -1);
		if (gm->plr_d[i] == NULL)
			clear_game(gm, "Error: coudn't load player_d sprite\n", -1);
		if (gm->plr_u[i] == NULL)
			clear_game(gm, "Error: coudn't load player_u sprite\n", -1);
	}
}
