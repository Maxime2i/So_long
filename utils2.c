/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlangloi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:56:27 by mlangloi          #+#    #+#             */
/*   Updated: 2023/05/23 14:01:45 by mlangloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

char	*ft_strjoin2(char *s1, char *s2)
{
	size_t	size;
	size_t	i;
	char	*str;

	size = 0;
	i = 0;
	if (!s1 || !s2)
		return (NULL);
	size = ft_strlenint(s1) + ft_strlenint(s2);
	str = malloc (sizeof (char) * (size + 1));
	if (str == NULL)
		return (NULL);
	while (*s1)
	{
		str[i] = *s1++;
		i++;
	}
	while (*s2)
	{
		str[i] = *s2++;
		i++;
	}
	str[i] = '\0';
	size = size;
	return (str);
}

int	count_nb(int n)
{
	int	t;

	t = 0;
	if (n <= 0)
		t++;
	while (n != 0)
	{
		n /= 10;
		t++;
	}
	return (t);
}

char	*ft_itoa(int n)
{
	char	*dest;
	int		i;
	long	nb;

	i = count_nb(n) - 1;
	nb = n;
	dest = malloc(sizeof(char) * (count_nb(n) + 1));
	if (!dest)
		return (NULL);
	if (nb < 0)
	{
		dest[0] = '-';
		nb = -nb;
	}
	if (nb == 0)
		dest[0] = '0';
	while (nb != 0)
	{
		dest[i] = (nb % 10) + '0';
		i--;
		nb /= 10;
	}
	dest[count_nb(n)] = '\0';
	return (dest);
}

int	ft_strlen2(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 10)
		i++;
	return (i);
}
