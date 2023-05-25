#include "minitalk.h"

void    send(pid_t pid, char *str, size_t len)
{
    size_t  idx;
    int     bit;

    idx = 0;
    while (idx < len)
    {
        bit = 0;
        while (bit < 8)
        {
            int sig = *(str + idx) >> (7 - bit) & 1;
            if (sig == 0)
                kill(pid, SIGUSR1);
            else
                kill(pid, SIGUSR2);
            usleep(30);
            bit++;
        }
        idx++;
    }
}

void    create_signal(pid_t pid, char *str)
{
    char    *tmp;

    tmp = ft_strjoin(str, "\n");
    if (!tmp)
        exit(0);
    printf("send info : %d, %zu, %s", pid, ft_strlen(tmp), tmp);
    send(pid, tmp, ft_strlen(tmp));
    free(tmp);
}

int main(int ac, char **av)
{
    pid_t   pid;

    pid = validate(ac, av[1]);
    if (pid == -1)
        return (0);
    create_signal(pid, av[2]);
}
