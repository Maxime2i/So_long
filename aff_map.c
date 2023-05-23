/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlangloi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 18:15:02 by mlangloi          #+#    #+#             */
/*   Updated: 2023/05/23 14:01:04 by mlangloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	ft_register_map(t_complete *game)
{
	int	i;
	int	j;

	game->floor = mlx_xpm_file_to_image(game->mlx, "sol.xpm", &i, &j);
	game->mur = mlx_xpm_file_to_image(game->mlx, "mur.xpm", &i, &j);
	game->player = mlx_xpm_file_to_image(game->mlx, "player.xpm", &i, &j);
	game->exit = mlx_xpm_file_to_image(game->mlx, "sortie.xpm", &i, &j);
	game->collec = mlx_xpm_file_to_image(game->mlx, "collectible.xpm", &i, &j);
	game->ennemi = mlx_xpm_file_to_image(game->mlx, "ennemi.xpm", &i, &j);
}

void	ft_place_collect(t_complete *game, int height, int width)
{
	mlx_put_image_to_window(game->mlx, game->win, game->collec,
		width * 32, height * 32);
	game->collect++;
}

void	ft_place_player(t_complete *game, int height, int width)
{
	mlx_put_image_to_window(game->mlx, game->win, game->player,
		width * 32, height * 32);
	game->y = height;
	game->x = width;
}

void	ft_place_map2(t_complete *game, int height, int width)
{
	if (game->map[height][width] == '1')
		mlx_put_image_to_window(game->mlx, game->win,
			game->mur, width * 32, height * 32);
	if (game->map[height][width] == 'C')
		ft_place_collect(game, height, width);
	if (game->map[height][width] == 'P')
		ft_place_player(game, height, width);
	if (game->map[height][width] == 'E')
		mlx_put_image_to_window(game->mlx, game->win,
			game->exit, width * 32, height * 32);
	if (game->map[height][width] == '0')
		mlx_put_image_to_window(game->mlx, game->win,
			game->floor, width * 32, height * 32);
	if (game->map[height][width] == 'M')
		mlx_put_image_to_window(game->mlx, game->win,
			game->ennemi, width * 32, height * 32);
}

void	ft_place_map(t_complete *game)
{
	int	height;
	int	width;

	game->collect = 0;
	height = 0;
	while (height < game->height)
	{
		width = 0;
		while (game->map[height][width])
		{
			ft_place_map2(game, height, width);
			width++;
		}
		height++;
	}
}
