# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaeychoi <jaeychoi@student.42seoul.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/14 15:02:33 by jaeychoi          #+#    #+#              #
#    Updated: 2023/03/31 19:38:03 by jaeychoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

RM = rm -f

AR = ar

ARFLAGS = rc

NAME = libft.a

SRCS = ft_isalpha.c \
	   ft_memchr.c \
	   ft_memset.c \
	   ft_strlen.c \
	   ft_tolower.c \
	   ft_atoi.c \
	   ft_isascii.c \
	   ft_memcmp.c \
	   ft_strchr.c \
	   ft_strncmp.c \
	   ft_toupper.c \
	   ft_bzero.c \
	   ft_isdigit.c \
	   ft_memcpy.c \
	   ft_strlcat.c \
	   ft_strnstr.c \
	   ft_isalnum.c \
	   ft_isprint.c \
	   ft_memmove.c \
	   ft_strlcpy.c \
	   ft_strrchr.c \
	   ft_calloc.c \
	   ft_strdup.c \
	   ft_itoa.c \
	   ft_putchar_fd.c \
	   ft_putendl_fd.c \
	   ft_putnbr_fd.c \
	   ft_putstr_fd.c \
	   ft_split.c \
	   ft_striteri.c \
	   ft_strjoin.c \
	   ft_strmapi.c \
	   ft_strtrim.c \
   	   ft_substr.c

BSRCS = ft_lstnew.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstadd_front.c \
		ft_lstclear.c \
		ft_lstdelone.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_lstsize.c

OBJS = $(SRCS:.c=.o)

OBJSB = $(BSRCS:.c=.o)

CFLAGS = -c -Wall -Wextra -Werror
all : $(NAME)

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

%.o : %.c
	$(CC) $(CFLAGS) $<

clean :
	$(RM) $(OBJS)
	$(RM) $(OBJSB)

fclean : clean
	$(RM) $(NAME)

re : fclean all

bonus :
	@make 'OBJS=$(OBJSB)'


.PHONY : re clean fclean bonus all
