# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlangloi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/13 22:16:14 by mlangloi          #+#    #+#              #
#    Updated: 2023/05/20 14:17:34 by mlangloi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFTPRINTF = ./ft_printf/libftprintf.a
LIBS = -lXext -lX11 -lm -lz -o
SRCS = main.c \
	utils.c \
	utils2.c \
	utils3.c \
	get_next_line.c \
	get_next_line_utils.c \
	init_map.c \
	error_map.c \
	aff_map.c \
	dep_player.c \
	chemin_map.c \
	chemin_map_collect.c \

OBJS = $(SRCS:.c=.o)
MLX_LIB = ./minilibx-linux/libmlx_Linux.a 

all: so_long

$(LIBFTPRINTF):
	$(MAKE) -C ./ft_printf

so_long: $(OBJS) $(LIBFTPRINTF)
	cd ./minilibx-linux && ./configure && $(MAKE)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIBFTPRINTF) $(MLX_LIB) $(LIBS) so_long

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) clean -C ./ft_printf
	rm -f $(OBJS)
	cd ./minilibx-linux && $(MAKE) clean
	rm -f libftprintf.a

fclean: clean
	$(MAKE) fclean -C ./ft_printf
	rm -f so_long
	cd ./minilibx-linux && $(MAKE) clean

re: fclean all
