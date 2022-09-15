# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yamrire <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/23 05:07:27 by yamrire           #+#    #+#              #
#    Updated: 2022/09/15 01:43:09 by yamrire          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ./includes/ft_nbr_base.c ./includes/ft_printf.c ./includes/ft_putchar.c ./includes/ft_putstr.c ./includes/ft_atoi.c ./includes/ft_putnbr.c ./includes/ft_strchr.c ./includes/ft_strlen.c main.c push_swap_utils.c operations.c
NAME = push_swap
CC = gcc
FLAG = -Wall -Werror -Wextra
OBJ = $(SRC:%.c=%.o)

all : $(NAME)

%.o: %.c
	$(CC) $(FLAG) -c $< -o $@

$(NAME) : $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all