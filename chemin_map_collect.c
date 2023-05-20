/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chemin_map_collect.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlangloi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 13:04:21 by mlangloi          #+#    #+#             */
/*   Updated: 2023/05/20 16:05:02 by mlangloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

int	ft_find_sol_collect(char **map, t_complete *game, int x, int y)
{
	if (map[x][y] == '1' || map[x][y] == 'M' || map[x][y] == 'E')
		return (0);
	else if (x == game->xcol && y == game->ycol)
		return (1);
	map[x][y] = '1';
	if (ft_find_sol_collect(map, game, x + 1, y) == 1)
		return (1);
	if (ft_find_sol_collect(map, game, x - 1, y) == 1)
		return (1);
	if (ft_find_sol_collect(map, game, x, y + 1) == 1)
		return (1);
	if (ft_find_sol_collect(map, game, x, y - 1) == 1)
		return (1);
	return (0);
}

void	check_path_collect(t_complete *game)
{
	char	**map;
	int		i;

	i = 0;
	map = ft_copy_map(game);
	if (ft_find_sol_collect(map, game, game->x, game->y) == 0)
	{
		ft_printf("Error\nUn collectible n'est pas atteignable");
		while (map[i])
		{
			free(map[i]);
			i++;
		}
		free(map);
		mon_exit_sans_image(game);
	}
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	ft_find_collect(t_complete *game)
{
	int			height;
	int			width;

	height = 0;
	while (height < game->height)
	{
		width = 0;
		while (game->map[height][width])
		{
			if (game->map[height][width] == 'C')
			{
				game->xcol = height;
				game->ycol = width;
				check_path_collect(game);
			}
			width++;
		}
		height++;
	}
}
