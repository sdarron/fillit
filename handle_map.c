/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdaisey <tdaisey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 01:29:12 by sdarron           #+#    #+#             */
/*   Updated: 2020/01/15 20:22:17 by tdaisey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#	include "libft/libft.h"

/*
** Backtracking
*/

int			ft_solve_map(t_list *l, t_map *map)
{
	int		i;
	int		j;
	t_tetr	*t;

	if (!l)
		return (1);
	j = 0;
	t = (t_tetr *)(l->content);
	while (j < map->size - t->height + 1)
	{
		i = 0;
		while (i < map->size - t->width + 1)
		{
			if (ft_fits(t, map, i, j))
			{
				if (ft_solve_map(l->next, map))
					return (1);
				else
					ft_draw(t, map, res_new(i, j), '.');
			}
			i++;
		}
		j++;
	}
	return (0);
}

t_map		*solver(t_list *list)
{
	t_map	*m;
	int		size;

	size = 1;
	if (!(m = ft_newmap(size)))
		exit(1);
	while (!ft_solve_map(list, m))
	{
		size++;
		ft_freemap(m);
		m = ft_newmap(size);
	}
	return (m);
}
