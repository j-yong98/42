# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaeychoi <jaeychoi@student.42seoul.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/21 11:26:40 by jaeychoi          #+#    #+#              #
#    Updated: 2023/03/23 10:48:55 by jaeychoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = libftprintf.a

CC = gcc
CFLAGS = -c -Wall -Wextra -Werror

RM = rm -f

AR = ar cr

SRCS = ft_printf.c \
	   ft_conversion.c \
	   ft_print_hex.c \
	   ft_print_ptr.c \
	   ft_print_decimal.c \
	   ft_print_unsigned.c \
	   ft_put.c

OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
	$(AR) $@ $^

%.o : %.c
	$(CC) $(CFLAGS) $^

all : $(NAME)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all 

.PHONY : clean fclean re
