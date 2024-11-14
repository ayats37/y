# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: taya <taya@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/09 21:20:01 by taya              #+#    #+#              #
#    Updated: 2024/10/03 15:21:56 by taya             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_print_char.c \
       ft_print_hex.c \
       ft_print_int.c \
       ft_print_percent.c \
       ft_print_pointer.c \
       ft_print_str.c \
       ft_print_unsigned.c \
       ft_printf.c \
			 ft_print_utils.c

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) 
	ar rcs $(NAME) $(OBJS) 

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all








.PHONY: all clean fclean re
