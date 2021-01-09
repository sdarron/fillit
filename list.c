/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdaisey <tdaisey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 08:30:36 by sdarron           #+#    #+#             */
/*   Updated: 2020/01/15 19:47:24 by tdaisey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#	include "libft/libft.h"

t_tetr		*ft_newtetr(char **fig, int width, int height, char letter)
{
	t_tetr	*tetr;

	if ((tetr = ft_memalloc(sizeof(t_tetr))))
	{
		tetr->fig = fig;
		tetr->width = width;
		tetr->height = height;
		tetr->letter = letter;
	}
	return (tetr);
}

t_res		*res_new(int i, int j)
{
	t_res	*r;

	r = ft_memalloc(sizeof(t_res));
	r->x = i;
	r->y = j;
	return (r);
}

void		ft_freetetr(t_tetr *t)
{
	int		j;

	j = 0;
	while (j < t->height)
	{
		ft_memdel((void **)(&(t->fig[j])));
		j++;
	}
	ft_memdel((void **)(&(t->fig)));
	ft_memdel((void **)&t);
}

t_list		*ft_freelist(t_list *list)
{
	t_tetr	*tetr;
	t_list	*next;

	while (list)
	{
		tetr = (t_tetr*)list->content;
		next = list->next;
		ft_freetetr(tetr);
		ft_memdel((void **)&list);
		list = next;
	}
	return (NULL);
}
