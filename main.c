/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarron <sdarron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 20:21:38 by sdarron           #+#    #+#             */
/*   Updated: 2020/01/21 20:42:47 by sdarron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

int			ft_fillitname(void)
{
	ft_putstr("usage: ./fillit file_name\n");
	return (0);
}

void		ft_freeline(char *line)
{
	free(line);
	line = NULL;
}

void		ft_endprog(t_list *list)
{
	t_map	*m;

	m = solver(list);
	if (m->size != 1)
		ft_disply(m);
	ft_freemap(m);
	ft_freelist(list);
}

void		ft_make_zero(char arr[200][6])
{
	int		i;

	i = 0;
	while (i < 200)
	{
		ft_bzero(arr[i], 6);
		i++;
	}
}

int			main(int argc, char **argv)
{
	char	*line;
	char	alltetr[200][6];
	int		i;
	int		len;
	int		fd;

	i = 0;
	len = 0;
	ft_make_zero(alltetr);
	if (argc != 2)
		return (ft_fillitname());
	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		ft_strcpy(alltetr[i], line);
		len = ft_strlen(alltetr[i]);
		alltetr[i++][len] = '\n';
		ft_freeline(line);
	}
	close(fd);
	if (!(ft_square(i, alltetr) && ft_hash(i, alltetr) && ft_chash(i, alltetr)))
		return (0);
	ft_endprog(ft_read_input(open(argv[1], O_RDONLY)));
	return (0);
}
