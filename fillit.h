/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarron <sdarron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 21:07:15 by tdaisey           #+#    #+#             */
/*   Updated: 2020/01/21 00:26:56 by sdarron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"

typedef struct			s_tetramino
{
	char				**fig;
	int					height;
	int					width;
	char				letter;
}						t_tetr;

typedef struct			s_map
{
	char				**map;
	int					size;
}						t_map;

typedef struct			s_res
{
	int					x;
	int					y;
}						t_res;

int						ft_solve_map(t_list *list, t_map *map);
int						ft_fits(t_tetr *t, t_map *m, int i, int j);
t_list					*ft_read_input(int fd);
t_tetr					*ft_newtetr (char **fig, int wth, int ht, char let);
t_map					*ft_newmap(int size);
int						ft_hash(int i, char alltetr[200][6]);
int						ft_square(int i, char alltetr[200][6]);
void					ft_freemap(t_map *map);
t_res					*res_new(int i, int j);
void					ft_minmax(char *buff, t_res *min, t_res *max);
void					ft_draw(t_tetr *t, t_map *m, t_res *res, char c);
t_map					*solver(t_list *list);
void					ft_disply(t_map *m);
void					ft_freetetr(t_tetr *t);
int						get_next_line(int fd, char **line);
int						lineoutput(char **fd_arr, char **line, int count);
t_list					*ft_freelist(t_list *list);
t_tetr					*ft_getinfo(char *buff, char letter);
int						ft_error(void);
int						ft_link(int k, char alltetr[200][6]);
int						ft_valid(int fd);
int						ft_fillitname(void);
void					ft_freeline (char *line);
void					ft_endprog (t_list *list);
int						ft_chash(int i, char alltetr[200][6]);

# define BUFF_SIZE 21
# define FD_SIZE 10240

#endif
