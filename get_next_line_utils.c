/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlangloi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 20:52:28 by mlangloi          #+#    #+#             */
/*   Updated: 2023/05/23 14:10:18 by mlangloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strjoin(char *s1, char *s2, t_complete *game)
{
	char	*joined;
	int		i;
	int		j;

	if (s2[0] == '\0')
		return (0);
	joined = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!joined)
		mon_exit_sans_image(game);
	i = 0;
	while (s1 && s1[i])
	{
		joined[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j] && s2[j] != '\n')
		joined[i++] = s2[j++];
	if (s2[j] == '\n')
		joined[i++] = '\n';
	joined[i] = '\0';
	if (s1)
		free(s1);
	game = game;
	return (joined);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i] && s[i] != '\n')
		i++;
	if (s && s[i] == '\n')
		i++;
	return (i);
}

int	ft_clean(char *str)
{
	int	i;
	int	j;
	int	is_nl;

	i = 0;
	j = 0;
	is_nl = 0;
	while (str[i])
	{
		if (is_nl)
			str[j++] = str[i];
		if (str[i] == '\n')
			is_nl = 1;
		str[i++] = '\0';
	}
	return (is_nl);
}
