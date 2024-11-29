/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 19:59:22 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/09/01 20:03:24 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	check_player_utils(t_mlx *mlx, char c)
{
	if (c == 'W')
	{
		if (mlx->player.player)
			return (0);
		mlx->player.player = 1;
		mlx->player.rotate = M_PI;
	}
	else if (c == 'E')
	{
		if (mlx->player.player)
			return (0);
		mlx->player.player = 1;
		mlx->player.rotate = 0;
	}
	return (1);
}

int	check_player(t_mlx *mlx, char c)
{
	if (c == 'N')
	{
		if (mlx->player.player)
			return (0);
		mlx->player.player = 1;
		mlx->player.rotate = 3 * M_PI / 2;
	}
	else if (c == 'S')
	{
		if (mlx->player.player)
			return (0);
		mlx->player.player = 1;
		mlx->player.rotate = M_PI / 2;
	}
	return (check_player_utils(mlx, c));
}
