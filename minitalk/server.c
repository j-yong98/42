#include "minitalk.h"

t_message   *message;

void    get_signal(int signal)
{
    if (signal == SIGUSR1)
        message->ch |= 0;
    else
        message->ch |= 1;
    if (message->bit < 7)
        message->ch <<= 1;
    message->bit++;
    if (message->bit == 8)
    {
        write(1, &message->ch, 1);
        message->bit = 0;
        message->ch = 0;
    }
}

int main(void)
{
    message = (t_message *)malloc(sizeof(t_message));
    printf("SERVER START, PID : %d\n", getpid());
    signal(SIGUSR1, get_signal);
    signal(SIGUSR2, get_signal);
    while(1)
        pause();
    free(message);
    exit(0);
}
