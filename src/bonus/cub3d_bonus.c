/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 17:47:51 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/09/01 20:41:11 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	init_mlx(t_mlx *mlx)
{
	size_t	len;
	int		i;

	len = 0;
	i = 0;
	mlx->map = get_map(mlx->lst);
	mlx->width = WIDTH;
	mlx->height = HEIGHT;
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, mlx->width, mlx->height, "CUB3D");
}

void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	while (split && split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

int	check_name(char *str)
{
	char	**split;
	int		i;

	split = ft_split(str, '.');
	i = 0;
	while (split[i])
		i++;
	if (!split[0] || !split[1] || !split[i - 1])
	{
		printf("Error\n\tThe name of map not valid\n");
		ft_free_split(split);
		return (0);
	}
	if (ft_strncmp(split[i - 1], "cub", 3) || ft_strlen(split[i - 1]) != 3)
	{
		printf("Error\n\tThe name of map not valid\n");
		ft_free_split(split);
		return (0);
	}
	ft_free_split(split);
	return (1);
}

void	free_lst(t_mlx *mlx)
{
	if (mlx->map)
		ft_free_split(mlx->map);
	if (mlx->lst)
		ft_lstclear(&mlx->lst, ft_del);
	if (mlx->xpm)
		free(mlx->xpm);
	if (mlx->color.f)
		free(mlx->color.f);
	if (mlx->color.c)
		free(mlx->color.c);
	if (mlx->texture.ea)
		free(mlx->texture.ea);
	if (mlx->texture.no)
		free(mlx->texture.no);
	if (mlx->texture.so)
		free(mlx->texture.so);
	if (mlx->texture.we)
		free(mlx->texture.we);
}

int	main(int ac, char **av)
{
	t_mlx	mlx;

	if (ac != 2)
	{
		printf("Error\n\tPlease enter the path of map\n");
		return (1);
	}
	ft_bzero(&mlx, sizeof(t_mlx));
	if (check_name(av[1]) && check_map(av[1], &mlx))
	{
		init_mlx(&mlx);
		mlx_key_hook(mlx.win, ft_key_hook, &mlx);
		mlx_hook(mlx.win, 17, 0, ft_close_hook, &mlx);
		draw_map(&mlx, 1);
		mlx_loop(mlx.mlx);
		free_lst(&mlx);
		return (0);
	}
	free_lst(&mlx);
	return (1);
}
