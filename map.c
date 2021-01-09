/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdaisey <tdaisey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 17:49:43 by sdarron           #+#    #+#             */
/*   Updated: 2020/01/15 20:28:18 by tdaisey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#	include "libft/libft.h"

t_map		*ft_newmap(int size)
{
	t_map	*map;
	int		i;
	int		j;

	i = 0;
	if (!(map = (t_map*)ft_memalloc(sizeof(t_map))))
		return (NULL);
	map->size = size;
	if (!(map->map = (char **)ft_memalloc(sizeof(char *) * size)))
		ft_freemap(map);
	while (i < size && map)
	{
		if (!(map->map[i] = ft_strnew(size)))
		{
			ft_freemap(map);
			return (NULL);
		}
		j = 0;
		while (j < size)
			map->map[i][j++] = '.';
		i++;
	}
	return (map);
}

void		ft_freemap(t_map *map)
{
	int		i;

	i = 0;
	while (i < map->size)
	{
		ft_memdel((void **)&(map->map[i]));
		i++;
	}
	ft_memdel((void **)&(map->map));
	ft_memdel((void **)&map);
}

/*
** Размещает тетраминку на карте в указанную позицию с нужным символом
*/

void		ft_draw(t_tetr *t, t_map *m, t_res *res, char c)
{
	int		k;
	int		l;

	k = 0;
	l = 0;
	while (k < t->width)
	{
		while (l < t->height)
		{
			if (t->fig[l][k] == '#')
				m->map[res->y + l][res->x + k] = c;
			l++;
		}
		l = 0;
		k++;
	}
	ft_memdel((void**)&res);
}

/*
** Размещает тераминку по указанному удресу, предварительно проверяя
*/

int			ft_fits(t_tetr *t, t_map *m, int i, int j)
{
	int		k;
	int		l;

	k = 0;
	while (k < t->width)
	{
		l = 0;
		while (l < t->height)
		{
			if (m->map[l + j][k + i] != '.' && t->fig[l][k] == '#')
				return (0);
			l++;
		}
		k++;
	}
	ft_draw(t, m, res_new(i, j), t->letter);
	return (1);
}

void		ft_disply(t_map *m)
{
	int		i;

	i = 0;
	while (i < m->size)
	{
		ft_putstr(m->map[i]);
		ft_putchar('\n');
		i++;
	}
}
