# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lhaydar <lhaydar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/12 15:21:12 by lhaydar           #+#    #+#              #
#    Updated: 2026/01/14 12:43:02 by lhaydar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =  push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

SRC = ft_stack_utils_a.c ft_stack_utils_b.c ft_stack_main.c ft_push_swap_operations_a.c

OBJ = $(SRC:.c=.o)

all: build-ftprintf build-libft $(NAME) 

$(NAME): $(OBJ) ft_printf/libftprintf.a Libft/libft.a build-ftprintf build-libft
	$(CC) $(CFLAGS) $(OBJ) ft_printf/libftprintf.a Libft/libft.a -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

build-ftprintf:
	$(MAKE) -C ft_printf

build-libft:
	$(MAKE) -C Libft
	
clean:
	$(RM) $(OBJ)
	$(MAKE) -C ft_printf clean
	$(MAKE) -C Libft clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C ft_printf fclean
	$(MAKE) -C Libft fclean

re: fclean all

.PHONY: all clean fclean re