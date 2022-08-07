#include<signal.h>
#include<stdio.h>
#include<unistd.h>

char s[7];

void fill_in_bit(char c)
{
  size_t i;

  i = 0;
  while(i < 7)
  {
    if(s[i] == '\0')
    {
      s[i] = c;
      break;
    }
    i++;
  }
}

void f1()
{
  fill_in_bit('1');
}

void f2()
{
  fill_in_bit('0');
}

int main()
{
  printf("%d\n",getpid());
  while(1)
  {
    signal(SIGUSR1, f1);
    signal(SIGUSR2,f2);
    if(s[6] != '\0')
    {
      int res;
      res = 0;
      size_t  i;
      i = 0;
      while(i < 7)
      {
        res += (s[i] - '0') << i;
        i++;
      }
      write(1,&res,1);
      i = 0;
      while(i < 7) {
        s[i] = '\0';
        i++;
      }
    }
  }
  return 0;
}
