/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlangloi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 18:12:38 by mlangloi          #+#    #+#             */
/*   Updated: 2023/05/23 14:17:25 by mlangloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

int	add_line(t_complete *game, char *line)
{
	char	**temp;
	int		i;

	if (!line)
		return (0);
	i = 0;
	game->height++;
	temp = malloc(sizeof (char *) * (game->height + 1));
	if (!temp)
		mon_exit_sans_image(game);
	temp[game->height - 1] = NULL;
	while (i < game->height - 1)
	{
		temp[i] = game->map[i];
		i++;
	}
	temp[i] = line;
	if (game->map)
		free(game->map);
	game->map = temp;
	return (1);
}

int	taille_map(char *str)
{
	int	taille;

	taille = 0;
	while (str[taille])
		taille++;
	if (str[taille - 1] == '\n')
		taille--;
	return (taille);
}

void	ft_cr(t_complete *game, char *line)
{
	static int	tab[100];
	static int	i = 0;
	int			len;
	int			j;

	if (line == NULL)
		return ;
	len = ft_strlen2(line);
	tab[i++] = len;
	j = 1;
	while (tab[j])
	{
		if (tab[j] != tab[j - 1])
		{
			ft_printf("Error\nLa map n'est pas rectangle");
			mon_exit_sans_image(game);
		}
		j++;
	}
}

int	ft_map(t_complete *game, char **av)
{
	char	*map;

	game->fd = open(av[1], O_RDONLY);
	if (game->fd < 0)
		return (0);
	while (1)
	{
		map = get_next_line(game->fd, game);
		if (!add_line(game, map))
			break ;
		ft_cr(game, map);
	}
	close (game->fd);
	game->width = taille_map(game->map[0]);
	return (1);
}

int	mon_exit(t_complete *game)
{
	int	line;

	line = 0;
	mlx_destroy_image(game->mlx, game->floor);
	mlx_destroy_image(game->mlx, game->mur);
	mlx_destroy_image(game->mlx, game->player);
	mlx_destroy_image(game->mlx, game->exit);
	mlx_destroy_image(game->mlx, game->collec);
	mlx_destroy_image(game->mlx, game->ennemi);
	if (game->win)
	{
		mlx_clear_window(game->mlx, game->win);
		mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(game->mlx);
	}
	free(game->mlx);
	while (line < game->height)
	{
		free(game->map[line]);
		line++;
	}
	free(game->map);
	exit(0);
}
