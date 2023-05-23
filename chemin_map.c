/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chemin_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlangloi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 21:35:26 by mlangloi          #+#    #+#             */
/*   Updated: 2023/05/23 13:59:56 by mlangloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	*ft_calloc(size_t nmemb, size_t size, t_complete *game)
{
	char	*dest;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	dest = malloc(nmemb * size);
	if (!dest)
		mon_exit_sans_image(game);
	ft_bzero((unsigned char *)dest, nmemb * size);
	return (dest);
}

char	**ft_copy_map(t_complete *game)
{
	int		i;
	char	**grid;

	i = 0;
	grid = ft_calloc((game->height + 1), sizeof(char *), game);
	if (!grid)
		return (NULL);
	while (i < game->height)
	{
		grid[i] = ft_strdup(game->map[i], game);
		if (!grid[i])
		{
			free(grid);
			return (NULL);
		}
		i += 1;
	}
	return (grid);
}

int	ft_find_sol(char **map, t_complete *game, int x, int y)
{
	if (map[x][y] == '1' || map[x][y] == 'M')
		return (0);
	else if (map[x][y] == 'E')
		return (1);
	map[x][y] = '1';
	if (ft_find_sol(map, game, x + 1, y) == 1)
		return (1);
	if (ft_find_sol(map, game, x - 1, y) == 1)
		return (1);
	if (ft_find_sol(map, game, x, y + 1) == 1)
		return (1);
	if (ft_find_sol(map, game, x, y - 1) == 1)
		return (1);
	return (0);
}

void	check_path(t_complete *game)
{
	char	**map;
	int		i;

	i = 0;
	map = ft_copy_map(game);
	if (ft_find_sol(map, game, game->x, game->y) == 0)
	{
		ft_printf("Error\nLa sortie n'est pas atteignable");
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

void	ft_find_player(t_complete *game)
{
	int	height;
	int	width;

	height = 0;
	while (height < game->height)
	{
		width = 0;
		while (game->map[height][width])
		{
			if (game->map[height][width] == 'P')
			{
				game->x = height;
				game->y = width;
			}
			width++;
		}
		height++;
	}
}
