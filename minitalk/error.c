#include "minitalk.h"

int validate(int ac, char *av)
{
    int pid;

    if (ac != 3)
    {
        ft_printf("Illegal Argument!\n");
        return (-1);
    }
    pid = ft_atoi(av);
    if (pid <= 100 || pid >= 99999)
    {
        ft_printf("PID Error\n");
        return -1;
    }
    return pid;
}
