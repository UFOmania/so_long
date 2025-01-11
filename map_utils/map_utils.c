/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: massrayb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 15:48:45 by massrayb          #+#    #+#             */
/*   Updated: 2025/01/11 16:03:00 by massrayb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int	map_row_len(char *row)
{
	int len;

	len = 0;
	while(row && row[len])
	{
		
		if(row[len] == '\n')
		{
			if(row[len + 1] != '\0') // problem with gnl
				return (-1);
			break;
		}
		len++;
	}
	return (len);
}

static void del(void *obj)
{
	free(obj);
	obj = NULL;
}

void	destroy_map(Map **map_info, char *msg, int exit_no)
{
	if(msg)
		write(2, msg, ft_strlen(msg));
	exit(exit_no);
	ft_lstclear(&(*map_info)->map, del);
	free(*map_info);
}