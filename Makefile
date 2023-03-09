# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sabdelra <sabdelra@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/26 23:48:37 by sabdelra          #+#    #+#              #
#    Updated: 2023/03/07 04:24:38 by sabdelra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### COLORS
COLOR_GREEN=\033[0;32m
COLOR_RED=\033[0;31m
COLOR_BLUE=\033[0;34m
COLOR_END=\033[0m
###

SRC:= actions.c error.c push_swap.c utils.c sort.c ft_split.c

OBJ:= actions.o error.o push_swap.o utils.o sort.o ft_split.o

CCFLAGS:= -Wall -Werror -Wextra -std=c99 -g

NAME:= push_swap

all: $(NAME)

$(NAME): $(SRC)
	@$(CC) $(CCFLAGS) $^ -o $@
	@echo "$(COLOR_GREEN)>>push_swap ready"

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
