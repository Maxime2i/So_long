/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlangloi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 14:15:43 by mlangloi          #+#    #+#             */
/*   Updated: 2023/05/23 14:19:28 by mlangloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include"./minilibx-linux/mlx.h"
# include"ft_printf/ft_printf.h"
# include<stdio.h>
# include<stdlib.h>
# include<unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct t_start
{
	int		fd;
	int		height;
	int		width;
	int		playercount;
	int		columncount;
	int		exitcount;
	int		x;
	int		y;
	int		counter;
	int		collect;
	int		xcol;
	int		ycol;
	char	**map;
	void	*floor;
	void	*mur;
	void	*player;
	void	*exit;
	void	*collec;
	void	*ennemi;
	void	*mlx;
	void	*win;
}	t_complete;

void	main2(t_complete *game, char **av);

char	*ft_strjoin(char *s1, char *s2, t_complete *game);
size_t	ft_strlen(char *s);
int		ft_clean(char *str);
char	*get_next_line(int fd, t_complete *game);

char	*ft_strjoin2(char *s1, char *s2);
int		count_nb(int n);
char	*ft_itoa(int n);

int		right_move_end(t_complete *game, int i, int j);
void	character_valid2(t_complete *game);
int		mon_exit_sans_image(t_complete *game);

void	ft_bzero(void *s, size_t n);
char	*ft_strstr(char *str, char *to_find);
int		ft_strlenint(char *str);
void	check_error(t_complete *game);
char	*ft_strdup(const char *s, t_complete *game);

int		add_line(t_complete *game, char *line);
int		taille_map(char *str);
int		ft_map(t_complete *game, char **av);
int		mon_exit(t_complete *game);
void	ft_cr(t_complete *game, char *line);

int		vertwall(t_complete *game);
int		horiwall(t_complete *game);
void	if_walls(t_complete *game);
void	count_checker(t_complete *game, int height, int width);
void	character_valid(t_complete *game);

void	ft_register_map(t_complete *game);
void	ft_place_collect(t_complete *game, int height, int width);
void	ft_place_player(t_complete *game, int height, int width);
void	ft_place_map(t_complete *game);
void	ft_place_map2(t_complete *game, int height, int width);

int		right_move(t_complete *game, int i, int j);
int		right_move(t_complete *game, int i, int j);
int		keyboard_ad(t_complete *game, int touche);
int		ft_controls(int touche, t_complete *game);

void	*ft_calloc(size_t nmemb, size_t size, t_complete *game);
char	**ft_copy_map(t_complete *game);
int		ft_find_sol(char **map, t_complete *game, int x, int y);
void	check_path(t_complete *game);
void	ft_find_player(t_complete *game);

int		ft_find_sol_collect(char **map, t_complete *game, int x, int y);
void	check_path_collect(t_complete *game);
void	ft_find_collect(t_complete *game);
int		ft_strlen2(char *str);

#endif
