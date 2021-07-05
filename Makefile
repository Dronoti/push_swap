# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bkael <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/05 12:11:53 by bkael             #+#    #+#              #
#    Updated: 2021/07/05 19:00:30 by bkael            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = commands.c \
	commands2.c \
	lst_utils.c \
	lst_utils2.c \
	push_swap.c \
	push_swap_utils.c \
	push_swap_utils2.c \
	sorting.c

OBJ = $(SRC:%.c=%.o)

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(FLAGS) -I ./ $^ -o $(NAME)

%.o: %.c:
	gcc $(FLAGS) -I ./ -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
