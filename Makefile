# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/10 14:25:06 by jaesjeon          #+#    #+#              #
#    Updated: 2022/03/22 03:35:00 by jaesjeon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address
RM = rm -f

NAME = push_swap
LIBFT = libft.a
LIBFT_DIR = ./libft

SRCS_FILES = push_swap.c	\
	   ps_utils.c	\
	   parser.c		\
	   func_sp.c	\
	   func_r.c		\
	   check_sorted.c	\
	   arg_indexing.c	\
	   manual_sort.c	\
	   two_sort.c	\
	   three_sort.c	\
	   four_sort.c	\
	   five_sort.c	\
	   split_by_pivot.c	\
	   debug_func.c
SRCS_DIR = ./srcs
HEADER_DIR = ./srcs

LIBFT_HEADER = $(LIBFT_DIR)/libft.h
PS_HEADER = $(HEADER_DIR)/push_swap.h
SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS_FILES))
OBJS = $(SRCS:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIBFT_HEAER) $(PS_HEADER) $(OBJS)
	make -C $(LIBFT_DIR)
	cp $(LIBFT_DIR)/$(LIBFT) .
	$(CC) $(SRCS) -g -I$(HEADER_DIR) -L. -lft -o $@

clean:
	make clean -C $(LIBFT_DIR)
	$(RM) $(OBJS)

fclean:
	make fclean -C $(LIBFT_DIR)
	$(RM) $(LIBFT)
	$(RM) $(OBJS)
	$(RM) $(NAME)

re: fclean all
