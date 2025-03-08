#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>

void sighandler(int signum)
{
        printf("Received a signal %d\n", signum);}

int main(int argc, char **argv)
{

        signal(SIGINT, sighandler);
        if (argc!=2)
        {
                printf("Did you forget to specify number of seconds sleep?\n");
                exit(1);
        }
        printf("I am process %d\n", getpid());

        // remaining type on our sleep (before we were interrupted
        int remaining;

        // atoi is to convert string to int - e.g. remember to call ./sleepy 5
        remaining = sleep(atoi(argv[1]));

        printf("remaining time %d\n", remaining);

        exit(0);
}
