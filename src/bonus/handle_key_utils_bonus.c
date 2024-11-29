/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 14:46:25 by ael-amin          #+#    #+#             */
/*   Updated: 2023/09/01 20:42:17 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	handle_up_down(t_mlx *mlx, int key)
{
	double	change_y;
	t_rays	rays;

	mlx_destroy_image(mlx->mlx, mlx->img);
	mlx->img = NULL;
	rays.px = mlx->player.x;
	rays.py = mlx->player.y;
	rays.dx = key * cos(mlx->player.rotate) * MOVE_SPEAD;
	rays.dy = key * sin(mlx->player.rotate) * MOVE_SPEAD;
	change_y = 0;
	if (check_wall(mlx, rays))
		return ;
	mlx->player.x = rays.px + rays.dx;
	mlx->player.y = rays.py + rays.dy;
}

void	rotate(t_mlx *mlx, int dir)
{
	mlx_destroy_image(mlx->mlx, mlx->img);
	mlx->img = NULL;
	mlx->player.rotate += (double) dir * ROTATE_SPEAD;
	if (mlx->player.rotate >= 2 * M_PI)
		mlx->player.rotate -= 2 * M_PI;
	else if (mlx->player.rotate < 0.0)
		mlx->player.rotate += 2 * M_PI;
}
