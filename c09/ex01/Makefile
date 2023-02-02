CC = gcc
TARGET = libft.a
SRCSP =  srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c
HEADER = includes
OBJS = $(SRCSP:.c=.o)

CFLAGS = -c -Wall -Wextra -Werror

all : $(TARGET)

$(TARGET) : $(OBJS)
	ar rc $@ $^

%.o : %.c
	$(CC) $(CFLAGS) $< -o $@ -I $(HEADER)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -fr $(TARGET)

re : fclean all

.PHONY : all clean fclean re
