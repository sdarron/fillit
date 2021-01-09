/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarron <sdarron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 15:32:16 by sdarron           #+#    #+#             */
/*   Updated: 2020/01/21 20:43:37 by sdarron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"

int			ft_error(void)
{
	ft_putstr("error\n");
	return (0);
}

/*
** Подсчет связей между фигурами.
*/

int			ft_link(int k, char alltetr[200][6])
{
	int		j;
	int		link;

	link = 0;
	while (alltetr[k - 4][0] != '\n' && alltetr[k - 4][0] != '\0')
	{
		j = 0;
		while (j < 6)
		{
			if (alltetr[k - 4][j] == '#')
			{
				if (alltetr[k - 4][j + 1] == '#')
					++link;
				if (alltetr[k - 4][j - 1] == '#')
					++link;
				if (alltetr[k - 4 + 1][j] == '#')
					++link;
				if (alltetr[k - 4 - 1][j] == '#')
					++link;
			}
			j++;
		}
		++k;
	}
	return (link);
}

/*
** Проверка на кол-во симв. по горизонт. на кол-во срок в поле по верт,
** на количество количество связей между хешами (геометрию фигуры).
*/

int			ft_square(int i, char alltetr[200][6])
{
	int		k;
	int		str;

	str = 0;
	k = 0;
	while (k <= i)
	{
		if (alltetr[k][0] != '\n' && alltetr[k][0] != '\0')
		{
			++str;
			if (ft_strlen(alltetr[k]) != 5)
				return (ft_error());
		}
		if (alltetr[k][0] == '\n' || alltetr[k][0] == '\0')
		{
			if (str % 4 != 0 || (k + 1) % 5 != 0 || k > 130)
				return (ft_error());
			if (ft_link(k, alltetr) != 6 && ft_link(k, alltetr) != 8)
				return (ft_error());
		}
		if (alltetr[3][4] != '\n')
			return (ft_error());
		++k;
	}
	return (2);
}

/*
** Проверка на присутствие только симв. "#" или "."
*/

int			ft_hash(int i, char alltetr[200][6])
{
	int		k;
	int		j;

	k = 0;
	while (k <= i)
	{
		j = 0;
		while (j < 6)
		{
			if (alltetr[k][j] != '#' && alltetr[k][j] != '.')
			{
				if (alltetr[k][j] != '\n' && alltetr[k][j] != '\0')
					return (ft_error());
			}
			j++;
		}
		++k;
	}
	return (2);
}

int			ft_chash(int i, char alltetr[200][6])
{
	int		k;
	int		j;
	int		hash;

	hash = 0;
	k = 0;
	j = 0;
	while (k <= i)
	{
		while (j < 6)
		{
			if (alltetr[k][j] == '#')
				hash++;
			j++;
		}
		++k;
		j = 0;
	}
	return (hash % 4 ? ft_error() : 1);
}
