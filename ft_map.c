/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2100/01/01 00:00:00 by glodenos          #+#    #+#             */
/*   Updated: 2016/01/04 23:36:30 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

char			*g_motif;
char			**g_tab;
unsigned int	g_x;
unsigned int	g_y;

int					open_map(int fd)
{
	char			buf;
	unsigned int	i;
	char			*tmp;

	g_x = 0;
	g_y = 0;
	tmp = "\0";
	while (read(fd, &buf, 1) && buf != '\n')
		tmp = ft_concat(tmp, buf);
	if ((i = ft_strlen(tmp)) < 5)
		return (0);
	g_motif = (char *)malloc(sizeof(*g_motif) * 3);
	i--;
	g_motif[2] = tmp[--i];
	g_motif[1] = tmp[--i];
	g_motif[0] = tmp[--i];
	tmp[i] = '\0';
	g_y = ft_atoi(tmp);
	free(tmp);
	return (1);
}

static int			valid_map_ex(unsigned int i)
{
	unsigned int	j;

	while (--i)
		if (g_tab[i][g_x] != '\n')
			return (0);
	while (++i < g_y)
	{
		j = -1;
		while (++j < g_x - 1)
			if ((g_tab[i][j] != g_motif[0]) && (g_tab[i][j] != g_motif[1]))
				return (0);
	}
	return (1);
}

int					valid_map(int fd)
{
	char			buf;
	unsigned int	i;
	char			*tmp;

	tmp = "\0";
	while (read(fd, &buf, 1) && buf != '\n')
	{
		if ((buf != g_motif[0]) && (buf != g_motif[1]))
			return (0);
		tmp = ft_concat(tmp, buf);
		g_x++;
	}
	tmp = ft_concat(tmp, buf);
	if ((g_tab = (char**)matrix_sqrt(g_x + 1, g_y + 1)) == NULL)
		return (0);
	g_tab[0] = tmp;
	i = 0;
	while (read(fd, g_tab[++i], g_x + 1))
		if (i > g_y)
			return (0);
	if (i < g_y)
		return (0);
	return (valid_map_ex(i));
}
