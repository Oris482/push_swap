# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaesjeon <jaesjeon@student.42seoul.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/10 14:25:06 by jaesjeon          #+#    #+#              #
#    Updated: 2022/03/10 14:39:57 by jaesjeon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

NAME = push_swap
LIBFT = libft.a
LIBFT_DIR = ./libft

SRCS = 
SRCS_DIR = ./srcs
HEADER_DIR = ./srcs

LIBFT_HEADER = $(LIBFT_DIR)/libft.h
PS_HEADER = $(HEAER_DIR)/push_swap.h

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIBFT_HEAER) $(PS_HEADER)
	make -C $(LIBFTDIR)
	cp $(LIBFTDIR)/$(LIBFT) .
	$(CC) $(SRCS) -o $@ -I$(HEADER_DIR) -L.-lft

clean:
	make clean -C $(LIBFT_DIR)

fclean:
	make fclean -C $(LIBFT_DIR)
	$(RM) $(LIBFT)
	$(RM) $(NAME)

re: fclean all
