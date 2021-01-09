# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdarron <sdarron@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/30 21:52:25 by sdarron           #+#    #+#              #
#    Updated: 2019/12/30 22:50:49 by sdarron          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

GCC = gcc

LIB = libft/libft.a

SRCS =	get_next_line.c \
		handle_map.c \
		list.c \
		main.c \
		map.c \
		read_input.c \
		valid.c \

FLAGS = -Wall -Wextra -Werror

OBJ = $(patsubst %.c, %.o, $(SRCS))

all:	$(NAME)

$(OBJ):	$(SRCS)
		@$(GCC) $(FLAGS) -c $(SRCS)

$(NAME): $(OBJ)
		make -C ./libft/
		@$(GCC) $(OBJ) $(LIB) -o $(NAME)

clean:
		@/bin/rm -f $(OBJ)
		@/bin/rm -f libft/*.o

fclean: clean
		@/bin/rm -f $(NAME)
		@/bin/rm -f libft/libft.a
		
re: fclean all

.PHONY: all clean fclean re