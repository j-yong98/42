# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaeychoi <jaeychoi@student.42seoul.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/10 21:07:15 by jaeychoi          #+#    #+#              #
#    Updated: 2023/04/11 18:39:21 by jaeychoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

AR = ar
ARFLAGS = rc

CC = gcc
CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRCS =	main.c \
		validate.c
OBJS = $(SRCS:.c=.o)

LIBFT_P = libft/
LIBFT = $(LIBFT_P)libft.a

FT_PRINTF_P = ft_printf/
FT_PRINTF = $(FT_PRINTF_P)libftprintf.a

all : $(NAME)

$(NAME) : $(LIBFT) $(FT_PRINTF) $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(LIBFT) :
	@make -C $(LIBFT_P)

$(FT_PRINTF) :
	@make -C $(FT_PRINTF_P)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -I$(LIBFT_P) -I$(FT_PRINTF_P)

clean :
	@make -C $(LIBFT_P) clean
	@make -C $(FT_PRINTF_P) clean
	$(RM) $(OBJS)

fclean : clean
	@make -C $(LIBFT_P) fclean
	@make -C $(FT_PRINTF_P) fclean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
