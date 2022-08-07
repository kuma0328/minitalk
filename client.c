#include<signal.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main(int ac, char **av)
{
  if(ac != 3) return 0;
  size_t  i;
  size_t  j;
  int pid = atoi(av[1]);
  i = 0;
  while(av[2][i] != '\0')
  {
    j = 0;
    while(j < 7)
    {
      if(av[2][i] >> j & 1) {
        kill(pid,SIGUSR1);
        puts("1");
      }
      else {
        kill(pid, SIGUSR2);
        puts("0");
      }
      usleep(500);
      j++;
    }
    i++;
  }
}