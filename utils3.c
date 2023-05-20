/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlangloi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:15:00 by mlangloi          #+#    #+#             */
/*   Updated: 2023/05/20 15:49:27 by mlangloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

int	right_move_end(t_complete *game, int i, int j)
{
	if (game->map[j][i] == 'M')
	{
		ft_printf("LOOSE, Le petit cannard vous a tue");
		mon_exit(game);
	}
	if (game->map[j][i] == 'E')
	{
		if (game->collect != 0)
			return (0);
		ft_printf("WIN en %d pas, Bienvenue a 42 !\n", game->counter);
		mon_exit(game);
	}
	return (1);
}

void	character_valid2(t_complete *game)
{
	if (game->playercount != 1)
	{
		ft_printf("Error\nnombre de joueurs");
		mon_exit_sans_image(game);
	}
	if (game->columncount < 1)
	{
		ft_printf("Error\nnombre de collectibles");
		mon_exit_sans_image(game);
	}
	if (game->exitcount != 1)
	{
		ft_printf("Error\nnombre de sorties");
		mon_exit_sans_image(game);
	}
}

int	mon_exit_sans_image(t_complete *game)
{
	int	line;

	line = 0;
	while (line < game->height)
		free(game->map[line++]);
	free(game->map);
	exit(0);
}
