CC = gcc
NAME = bsq
SRCS = srcs/my_string.c srcs/my_string2.c srcs/error.c srcs/map_read2.c srcs/map_read.c srcs/find_answer2.c srcs/find_answer.c srcs/solve.c srcs/main.c
OBJS = $(SRCS:.c=.o)
HEADER = includes

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ -I $(HEADER)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $< -I $(HEADER)

clean:
	rm -rf $(OBJS)
	
fclean: clean
	rm -rf $(NAME)

re : fclean all

.PHONY: clean fclean re
