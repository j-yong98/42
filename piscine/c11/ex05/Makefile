CC = gcc
NAME = do-op
SRCS = srcs/calc.c srcs/main.c srcs/util.c srcs/oper.c

CFLAGS =  -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(SRCS)
	$(CC) $(CFLAGS) $^ -o $@

clean :

fclean :
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
