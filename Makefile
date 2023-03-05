# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sabdelra <sabdelra@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/26 23:48:37 by sabdelra          #+#    #+#              #
#    Updated: 2023/02/28 01:27:23 by sabdelra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC:= clang

SRC:= actions.c error.c push_swap.c utils.c sort.c ft_split.c

OBJ:= actions.o error.o push_swap.o utils.o sort.o ft_split.o

CCFLAGS:= -Wall -Werror -Wextra -std=c99 -ggdb3

NAME:= push_swap

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CCFLAGS) $^ -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
