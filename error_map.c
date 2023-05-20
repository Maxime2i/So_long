/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlangloi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 18:13:15 by mlangloi          #+#    #+#             */
/*   Updated: 2023/05/20 15:31:09 by mlangloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

int	vertwall(t_complete *game)
{
	int	height;
	int	width;

	height = 0;
	width = game->width;
	while (height < game->height)
	{
		if (!(game->map[height][0] == '1'
			&& game->map[height][width - 1] == '1'))
			return (0);
		height++;
	}
	return (1);
}

int	horiwall(t_complete *game)
{
	int	height;
	int	width;

	width = 0;
	height = game->width;
	while (width < height)
	{
		if (!(game->map[0][width] == '1'
			&& game->map[game->height - 1][width] == '1'))
			return (0);
		width++;
	}
	return (1);
}

void	if_walls(t_complete *game)
{
	int	vert;
	int	hori;

	vert = vertwall(game);
	hori = horiwall(game);
	if (!vert || !hori)
	{
		ft_printf("Error\nCette map n'est pas ferme !\n");
		mon_exit_sans_image(game);
	}
}

void	count_checker(t_complete *game, int height, int width)
{
	if (game->map[height][width] != '1' &&
		game->map[height][width] != '0' &&
		game->map[height][width] != 'P' &&
		game->map[height][width] != 'E' &&
		game->map[height][width] != 'C' &&
		game->map[height][width] != '\n' &&
		game->map[height][width] != 'M')
	{
		ft_printf("Error\nMap, mauvaise lettre : %c\n", game->map[height][width]);
		mon_exit_sans_image(game);
	}
	if (game->map[height][width] == 'C')
		game->columncount++;
	if (game->map[height][width] == 'P')
		game->playercount++;
	if (game->map[height][width] == 'E')
		game->exitcount++;
}

void	character_valid(t_complete *game)
{
	int	height;
	int	width;

	height = 0;
	while (height < game->height - 1)
	{
		width = 0;
		while (width <= game->width)
		{
			count_checker(game, height, width);
			width++;
		}
		height++;
	}
	character_valid2(game);
}
