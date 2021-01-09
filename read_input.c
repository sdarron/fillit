/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdaisey <tdaisey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 19:39:57 by tdaisey           #+#    #+#             */
/*   Updated: 2020/01/15 20:47:58 by tdaisey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#	include "libft/libft.h"

void		ft_lstrev(t_list **l)
{
	t_list	*prev;
	t_list	*cur;
	t_list	*next;

	prev = NULL;
	cur = *l;
	while (cur != NULL)
	{
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	*l = prev;
}

/*
** Получение крайних значений
*/

void		ft_minmax(char *buff, t_res *min, t_res *max)
{
	int		i;

	i = 0;
	while (i < 20)
	{
		if (buff[i] == '#')
		{
			if (i / 5 < min->y)
				min->y = i / 5;
			if (i / 5 > max->y)
				max->y = i / 5;
			if (i % 5 < min->x)
				min->x = i % 5;
			if (i % 5 > max->x)
				max->x = i % 5;
		}
		i++;
	}
}

/*
** Заполнение структуры
*/

t_tetr		*ft_getinfo(char *buff, char letter)
{
	t_res	*mn;
	t_res	*mx;
	char	**fig;
	int		i;
	t_tetr	*t;

	i = 0;
	mn = res_new(3, 3);
	mx = res_new(0, 0);
	ft_minmax(buff, mn, mx);
	fig = ft_memalloc(sizeof(char*) * (mx->y - mn->y + 1));
	while (i < mx->y - mn->y + 1)
	{
		fig[i] = ft_strnew(mx->x - mn->x + 1);
		ft_strncpy(fig[i], buff + (mn->x) + (i + mn->y) * 5, mx->x - mn->x + 1);
		i++;
	}
	t = ft_newtetr(fig, mx->x - mn->x + 1, mx->y - mn->y + 1, letter);
	ft_memdel((void **)&mn);
	ft_memdel((void **)&mx);
	return (t);
}

t_list		*ft_read_input(int fd)
{
	char	*buff;
	t_list	*l;
	t_tetr	*t;
	int		counter;
	char	letter;

	letter = 'A';
	l = NULL;
	buff = ft_strnew(21);
	while ((counter = read(fd, buff, 21)) >= 20)
	{
		if (!(t = ft_getinfo(buff, letter)))
			return (ft_freelist(l));
		ft_lstadd(&l, ft_lstnew(t, sizeof(t_tetr)));
		ft_memdel((void **)&t);
		letter++;
	}
	if (counter < 20 && counter > 0)
		ft_error();
	ft_memdel((void **)&buff);
	if (counter != 0)
		return (ft_freelist(l));
	ft_lstrev(&l);
	return (l);
}
