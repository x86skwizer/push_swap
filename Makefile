# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yamrire <yamrire@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/23 05:07:27 by yamrire           #+#    #+#              #
#    Updated: 2022/08/23 05:30:39 by yamrire          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ./includes/ft_nbr_base.c ./includes/ft_printf.c ./includes/ft_putchar.c ./includes/ft_putstr.c main.c push_swap_utils.c
NAME = push_swap
CC = gcc
FLAG = -Wall -Werror -Wextra
OBJ = OBJ = $(SRC:%.c=%.o)

all : $(NAME)

%.o : %.c
	$(CC) $(FLAG) -c $(SRC)

$(NAME) : $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all