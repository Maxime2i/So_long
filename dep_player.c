/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dep_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlangloi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 18:15:46 by mlangloi          #+#    #+#             */
/*   Updated: 2023/05/20 14:09:48 by mlangloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

int	right_move(t_complete *game, int i, int j)
{
	if (right_move_end(game, i, j) == 0)
		return (0);
	if (game->map[j][i] == '0')
	{
		game->map[j][i] = 'P';
		game->x = i;
		game->y = j;
		game->counter++;
	}
	if (game->map[j][i] == 'C')
	{
		game->map[j][i] = 'P';
		game->x = i;
		game->y = j;
		game->collect--;
		game->counter++;
	}
	return (1);
}

void	ft_actualise_pas(t_complete *game)
{
	char	*str;
	char	*str2;

	mlx_put_image_to_window(game->mlx, game->win, game->floor,
		0, (((game->height + 1) * 32) - 32));
	mlx_put_image_to_window(game->mlx, game->win, game->floor,
		30, (((game->height + 1) * 32) - 32));
	mlx_put_image_to_window(game->mlx, game->win, game->floor,
		50, (((game->height + 1) * 32) - 32));
	str2 = ft_itoa(game->counter);
	str = ft_strjoin2("Pas : ", str2);
	mlx_string_put(game->mlx, game->win, 10, (((game->height + 1) * 32) - 12),
		0x33bbff, str);
	free(str);
	free(str2);
}

int	keyboard_ws(t_complete *game, int touche)
{
	int		i;
	int		j;

	i = game->x;
	j = game->y;
	if (touche == 119 || touche == 65362)
	{
		j--;
		if (game->map[j][i] == '1')
			return (0);
		if (right_move(game, i, j) == 0)
			return (0);
		game->map[j + 1][i] = '0';
	}
	else if (touche == 115 || touche == 65364)
	{
		j++;
		if (game->map[j][i] == '1')
			return (0);
		if (right_move(game, i, j) == 0)
			return (0);
		game->map[j - 1][i] = '0';
	}
	ft_actualise_pas(game);
	return (1);
}

int	keyboard_ad(t_complete *game, int touche)
{
	int		i;
	int		j;

	i = game->x;
	j = game->y;
	if (touche == 97 || touche == 65361)
	{
		i--;
		if (game->map[j][i] == '1')
			return (0);
		if (right_move(game, i, j) == 0)
			return (0);
		game->map[j][i + 1] = '0';
	}
	else if (touche == 100 || touche == 65363)
	{
		i++;
		if (game->map[j][i] == '1')
			return (0);
		if (right_move(game, i, j) == 0)
			return (0);
		game->map[j][i - 1] = '0';
	}
	ft_actualise_pas(game);
	return (1);
}

int	ft_controls(int touche, t_complete *game)
{
	int	works;

	if (touche == 65307)
		mon_exit(game);
	if (touche == 119 || touche == 65362)
		works = keyboard_ws(game, touche);
	if (touche == 115 || touche == 65364)
		works = keyboard_ws(game, touche);
	if (touche == 97 || touche == 65361)
		works = keyboard_ad(game, touche);
	if (touche == 100 || touche == 65363)
		works = keyboard_ad(game, touche);
	if (works)
		ft_place_map(game);
	return (1);
}
