#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/16 02:56:18 by marvin            #+#    #+#              #
#    Updated: 2026/04/12 00:12:41 by marvin           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME	= push_swap

CC		= cc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

SRC		= source/main.c \
		  source/operation/ft_push.c \
		  source/operation/ft_reverse_rotate.c \
		  source/operation/ft_rotate.c \
		  source/operation/ft_swap.c \
		  source/stack/ft_stack_utils_a.c \
		  source/stack/ft_stack_utils_b.c \
		  source/parsing/ft_parsing.c \
		  source/parsing/ft_parsing_utils.c \
		  source/parsing/ft_parsing_flags.c \
		  source/parsing/ft_populate_stack.c \
		  source/ft_compute_disorder.c \
		  source/sorting/ft_radix_sort.c \
		  source/sorting/ft_selection_sort.c \
		  source/sorting/ft_chunk_sort.c \
		  source/sorting/ft_chunk_sort_helper.c \

OBJ		= $(SRC:.c=.o)

HEADER	= -I header/ -I Libft/ -I ft_printf/

all: build-libft build-ftprintf $(NAME)

$(NAME): $(OBJ) Libft/libft.a ft_printf/libftprintf.a
	$(CC) $(CFLAGS) $(OBJ) Libft/libft.a ft_printf/libftprintf.a -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

build-libft:
	$(MAKE) -C Libft

build-ftprintf:
	$(MAKE) -C ft_printf

clean:
	$(RM) $(OBJ)
	$(MAKE) -C Libft clean
	$(MAKE) -C ft_printf clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C Libft fclean
	$(MAKE) -C ft_printf fclean

re: fclean all

.PHONY: all clean fclean re build-libft build-ftprintf