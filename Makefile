# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttridon <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/24 09:52:44 by ttridon           #+#    #+#              #
#    Updated: 2016/03/12 21:34:46 by ttridon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

CPPFLAGS = -I includes

SRC_NAME = 	ft_printf.c		ft_putchar.c		va_putnbr.c		va_putchar.c   \
			va_putstr.c		ft_putstr.c			va_puthexa.c	ft_puissance.c \
			va_putoctal.c	va_putpointeur.c	va_putusnbr.c	ft_toupper.c   \
			str_toupper.c	va_putmhexa.c		ft_strdup.c		ft_bzero.c	   \
			va_percent.c	ft_strlen.c			ft_strchr.c		va_putmoctal.c \
			ft_atoi.c		ft_itoa.c			ft_itoa_base.c	ft_uitoa.c	   \
			va_putmusnbr.c	va_putmnbr.c		va_putmchar.c	va_putmstr.c   \
			va_putbinaire.c	

SRC_PATH = src/

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))

OBJ_NAME = $(SRC_NAME:.c=.o)

OBJ_PATH = obj/

OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	rm -f $(SRC:.c=.o)
	rm -rf $(OBJ_PATH) 

fclean: clean
	rm -f $(NAME)

re: fclean all
