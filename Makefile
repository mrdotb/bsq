# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bchaleil <bchaleil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/17 12:49:42 by bchaleil          #+#    #+#              #
#    Updated: 2016/01/04 16:32:51 by bchaleil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq
SRC = main.c	ft_putchar.c	ft_putstr.c		ft_putstr_err.c		\
	  print_bsq.c		ft_strlen.c		ft_atoi.c	matrix_sqrt.c	\
	  ft_concat.c		ft_map.c		resolve.c	free_sqrt.c

OBJ = $(SRC:.c=.o)
CC = gcc
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
		@$(CC) -c $(CFLAGS) $(SRC)
		@$(CC) -o $(NAME) $(OBJ)

clean:
		@rm -rf $(OBJ)

fclean: clean
		@rm -rf $(NAME)
		@rm -rf $(OBJ)

re: fclean $(NAME)

tests: fclean $(NAME)
		@cp bsq tests/bsq
		@cd tests && zsh test.sh

 .PHONY: clean fclean
