#ifndef MINITALK_H
# define MINITALK_H
# include <signal.h>
# include <unistd.h>
# include "libft/libft.h"
# include <stdio.h>
typedef struct t_message
{
    int     bit;
    char    ch;
}   t_message;
int validate(int ac, char *av);
#endif
