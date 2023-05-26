NAME = $(SERVER) $(CLIENT)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SERVER = server
S_SRC = server.c
S_OBJ = $(S_SRC:.c=.o)

CLIENT = client
C_SRC = client.c \
        error.c
C_OBJ = $(C_SRC:.c=.o)

LIBFT_P = libft/
LIBFT = $(LIBFT_P)libft.a

FT_PRINTF_P = ft_printf/
FT_PRINTF = $(FT_PRINTF_P)libftprintf.a

all : $(NAME)

$(NAME) : $(LIBFT) $(FT_PRINTF) $(S_OBJ) $(C_OBJ)
	$(CC) $(CFLAGS) -o $(SERVER) $(S_OBJ) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) -o $(CLIENT) $(C_OBJ) $(LIBFT) $(FT_PRINTF)

$(LIBFT) :
	@make -C $(LIBFT_P)

$(FT_PRINTF) :
	@make -C $(FT_PRINTF_P)

%.o : %.c
	$(CC) -c $(CFLAGS) -o $@ $<

clean :
	@make -C $(LIBFT_P) clean
	@make -C $(FT_PRINTF_P) clean
	$(RM) $(S_OBJ)
	$(RM) $(C_OBJ)

fclean : clean
	@make -C $(LIBFT_P) fclean
	@make -C $(FT_PRINTF_P) fclean
	$(RM) $(SERVER)
	$(RM) $(CLIENT)
    
re : fclean all

.PHONY : all clean fclean re
