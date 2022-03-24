# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/10 14:25:06 by jaesjeon          #+#    #+#              #
#    Updated: 2022/03/24 18:26:32 by jaesjeon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

NAME = push_swap
CHECKER = checker
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
	   three_sort_one.c	\
	   three_sort_two.c	\
	   four_sort.c	\
	   five_sort.c	\
	   split_by_pivot.c	\
	   print_command.c	\
	   compress_command.c	\
	   debug_func.c
CH_SRCS_FILES =	checker.c	\
				ch_utils.c	\
				func_sp.c	\
				func_r.c	\
				get_next_line.c	\
				get_next_line_utils.c	\
				parser.c	\
				do_command.c

SRCS_DIR = ./srcs
HEADER_DIR = ./srcs
CH_SRCS_DIR = ./checker_srcs
CH_HEADER_DIR = ./checker_srcs

LIBFT_HEADER = $(LIBFT_DIR)/libft.h
PS_HEADER = $(HEADER_DIR)/push_swap.h
CH_HEADER = $(CH_HEADER_DIR)/checker.h
SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS_FILES))
CH_SRCS = $(addprefix $(CH_SRCS_DIR)/, $(CH_SRCS_FILES))
OBJS = $(SRCS:.c=.o)
CH_OBJS = $(CH_SRCS:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIBFT_HEADER) $(PS_HEADER) $(OBJS)
	make bonus -C $(LIBFT_DIR)
	cp $(LIBFT_DIR)/$(LIBFT) .
	$(CC) $(SRCS) -I$(HEADER_DIR) -L. -lft -o $@

$(CHECKER): $(LIBFT_HEADER) $(CH_HEADER) $(CH_OBJS)
	make bonus -C $(LIBFT_DIR)
	cp $(LIBFT_DIR)/$(LIBFT) .
	$(CC) $(CH_SRCS) -I$(CH_HEADER_DIR) -L. -lft -o $@

clean:
	make clean -C $(LIBFT_DIR)
	$(RM) $(OBJS)
	$(RM) $(CH_OBJS)

fclean:
	make fclean -C $(LIBFT_DIR)
	$(RM) $(LIBFT)
	$(RM) $(OBJS)
	$(RM) $(CH_OBJS)
	$(RM) $(NAME)
	$(RM) $(CHECKER)

re: fclean all
