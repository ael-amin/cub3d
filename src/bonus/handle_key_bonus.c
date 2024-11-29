/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 16:06:46 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/09/01 20:41:37 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	check_wall(t_mlx *mlx, t_rays rays)
{
	if (mlx->map[(int)((rays.py + rays.dy) + MARGE) / TAIL_SIZE] \
		[(int)(rays.px + rays.dx) / TAIL_SIZE] == '1')
		return (1);
	else if (mlx->map[(int)((rays.py + rays.dy) - MARGE) / TAIL_SIZE] \
		[(int)(rays.px + rays.dx) / TAIL_SIZE] == '1')
		return (1);
	else if (mlx->map[(int)((rays.py + rays.dy)) / TAIL_SIZE] \
		[(int)(rays.px + rays.dx + MARGE) / TAIL_SIZE] == '1')
		return (1);
	else if (mlx->map[(int)((rays.py + rays.dy)) / TAIL_SIZE] \
		[(int)(rays.px + rays.dx - MARGE) / TAIL_SIZE] == '1')
		return (1);
	return (0);
}

void	handle_key_d(t_mlx *mlx)
{
	double	change_y;
	t_rays	rays;

	mlx_destroy_image(mlx->mlx, mlx->img);
	mlx->img = NULL;
	rays.px = mlx->player.x;
	rays.py = mlx->player.y;
	rays.dx = cos(((3 * M_PI) / 2) - mlx->player.rotate) * MOVE_SPEAD;
	rays.dy = -sin(((3 * M_PI) / 2) - mlx->player.rotate) * MOVE_SPEAD;
	change_y = 0;
	if (check_wall(mlx, rays))
		return ;
	mlx->player.x = rays.px + rays.dx;
	mlx->player.y = rays.py + rays.dy;
}

void	handle_key_a(t_mlx *mlx)
{
	double	change_y;
	t_rays	rays;

	mlx_destroy_image(mlx->mlx, mlx->img);
	mlx->img = NULL;
	rays.px = mlx->player.x;
	rays.py = mlx->player.y;
	rays.dx = -cos(((3 * M_PI) / 2) - mlx->player.rotate) * MOVE_SPEAD;
	rays.dy = sin(((3 * M_PI) / 2) - mlx->player.rotate) * MOVE_SPEAD;
	change_y = 0;
	if (check_wall(mlx, rays))
		return ;
	mlx->player.x = rays.px + rays.dx;
	mlx->player.y = rays.py + rays.dy;
}

void	handle_esc(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->xpm[0].img);
	mlx_destroy_image(mlx->mlx, mlx->xpm[1].img);
	mlx_destroy_image(mlx->mlx, mlx->xpm[2].img);
	mlx_destroy_image(mlx->mlx, mlx->xpm[3].img);
	mlx_destroy_image(mlx->mlx, mlx->img);
	free_lst(mlx);
	mlx_destroy_window(mlx->mlx, mlx->win);
	exit(0);
}

int	ft_key_hook(int key, t_mlx *mlx)
{
	if (key == KEY_ESC)
		handle_esc(mlx);
	else if (key == KEY_D)
		handle_key_d(mlx);
	else if (key == KEY_A)
		handle_key_a(mlx);
	else if (key == KEY_W)
		handle_up_down(mlx, UP);
	else if (key == KEY_S)
		handle_up_down(mlx, DOWN);
	else if (key == LEFT_ARROW)
		rotate(mlx, -1);
	else if (key == RIGHT_ARROW)
		rotate(mlx, 1);
	else
		return (0);
	return (draw_map(mlx, 0), 0);
}
