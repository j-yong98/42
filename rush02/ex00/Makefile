CC = gcc
TARGET = rush-02
SRCS = srcs/error_process.c srcs/check_key.c srcs/main.c srcs/make_dict.c srcs/position.c srcs/print.c
HEADER = includes

CFLAGS = -Wall -Wextra -Werror

all : $(TARGET)

$(TARGET) : $(SRCS)
	$(CC) $(CFLAG) $^ -o $@ -I $(HEADER)

fclean : 
	rm -rf $(TARGET)

re : fclean all

.PHONY : all clean fclean re
