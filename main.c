/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlangloi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 16:20:40 by mlangloi          #+#    #+#             */
/*   Updated: 2023/05/23 13:48:52 by mlangloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	main2(t_complete *game, char **av)
{
	ft_map(game, av);
	check_error(game);
	ft_find_player(game);
	check_path(game);
	ft_find_collect(game);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, (game->width * 32),
			((game->height + 1) * 32), "so_long");
	ft_register_map(game);
	ft_place_map(game);
	mlx_key_hook(game->win, ft_controls, game);
	mlx_hook(game->win, 17, 0, (void *)mon_exit, game);
	mlx_loop(game->mlx);
}

int	main(int ac, char **av)
{
	t_complete	game;
	char		*err;
	int			err2;

	if (ac != 2)
	{
		ft_printf("Error\nMauvais arguments !\n");
		return (0);
	}
	ft_bzero(&game, (sizeof (t_complete)));
	err = ft_strstr(av[1], ".ber");
	err2 = ft_strlenint(av[1]);
	if (err == NULL || err[4] || err2 <= 4)
	{
		ft_printf("Error\nLa map doit etre en '.ber'\n");
		return (0);
	}
	main2(&game, av);
	return (0);
}
