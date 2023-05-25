#include "minitalk.h"

int validate(int ac, char *av)
{
    int pid;

    if (ac != 3)
    {
        printf("Illegal Argument!\n");
        return (-1);
    }
    pid = ft_atoi(av);
    if (pid <= 100 || pid >= 99999)
    {
        printf("PID Error\n");
        return -1;
    }
    return pid;
}
