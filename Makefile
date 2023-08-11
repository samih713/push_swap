# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sabdelra <sabdelra@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/26 23:48:37 by sabdelra          #+#    #+#              #
#    Updated: 2023/07/27 20:59:02 by sabdelra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### COLORS
COLOR_GREEN=\033[0;32m
COLOR_RED=\033[0;31m
COLOR_BLUE=\033[0;34m
COLOR_YELLOW= \033[0;33m
COLOR_END=\033[0m
###

NAME:= push_swap

SRCSDR:= src/
SRCSL:= sort.c free.c error.c _ft_atoi.c check_sort.c stack_fill.c stack_init.c stack_print.c utils.c push.c swap.c rotate.c r_rotate.c ft_strchr.c ft_memmove.c sort_small.c
SRCS:= $(addprefix $(SRCSDR), $(SRCSL))

OBJSDR:= obj/
OBJSL:= $(SRCSL:.c=.o)
OBJS:= $(addprefix $(OBJSDR), $(OBJSL))
#-Wall -Werror -Wextra -std=c99
CCFLAGS:= -ggdb3

all: $(NAME)

$(NAME): $(OBJS) main.c
	@$(CC) $(CCFLAGS) $(OBJS) main.c -o $(NAME)
	@echo "$(COLOR_GREEN)>> push_swap ready✅\n$(COLOR_END)"

$(OBJSDR)%.o: $(SRCSDR)%.c
	@if [ "$echo_printed" = "false" ]; then \
		echo "$(COLOR_YELLOW)>> Compiling object files... ✅\n$(COLOR_END)"; \
		echo_printed=true; \
	fi
	@mkdir -p $(OBJSDR)
	@$(CC) $(CCFLAGS) -I./ -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)
	@echo "$(COLOR_BLUE).. full cleaned$(COLOR_END)"


re: fclean all

.PHONY: all test fclean clean re
