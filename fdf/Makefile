# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaeychoi <jaeychoi@student.42seoul.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/31 19:50:00 by jaeychoi          #+#    #+#              #
#    Updated: 2023/04/13 15:58:51 by jaeychoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

RM = rm
RMFLAGS = -f

CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIBFT_P = libft/
LIBFT = $(LIBFT_P)libft.a

GNL_P = gnl/
GNL = $(GNL_P)gnl.a

MLX_P = minilibx/
MLX = $(MLX_P)libmlx.a
MLX_C = -L$(MLX_P) -lmlx -framework OpenGL -framework Appkit

SRCS = main.c \
	   validate.c\
	   map_reader.c \
	   map_reader2.c \
	   mlx.c

OBJS = $(SRCS:.c=.o)

all : $(MLX) $(NAME)

$(NAME) : $(GNL) $(LIBFT) $(OBJS)
	$(CC) -g $(CFLAGS) -o $@ $(MLX_C) $^
	   install_name_tool -change libmlx.dylib minilibx/libmlx.dylib $@	

$(GNL) :
	@make -C $(GNL_P)

$(LIBFT) :
	@make -C $(LIBFT_P)

$(MLX) :
	@make -C $(MLX_P)

%.o : %.c
	$(CC) -c $(CFLAGS) $< -I $(LIBFT_P) -I $(GNL_P) -I $(MLX_P)

clean :
	@make -C $(GNL_P) clean
	@make -C $(LIBFT_P) clean
	@make -C $(MLX_P) clean
	$(RM) $(RMFLAGS) $(OBJS)

fclean : clean
	@make -C $(GNL_P) fclean
	@make -C $(LIBFT_P) fclean
	$(RM) $(RMFLAGS) $(NAME)

re : fclean all

.PHONY : all clean fclean re
