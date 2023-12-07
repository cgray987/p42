#include <unistd.h>

int main(int ac, char **av)
{
  char *s1;
  char *s2;
  int i;
  int j;
  int repeat[256] = {0};


  if (ac == 3)
  {
    s1 = av[1];
    s2 = av[2];
    while (s1[i])
    {
      j = 0;
      while (s2[j])
      {
        if (s1[i] == s2[j])
        {
          if (repeat[(int)s1[i]] == 0)
          {
            repeat[(int)s1[i]] = 1;
            write(1, &s2[j], 1);
          }
        }
        j++;
      }
      i++;
    }
  }
  write(1, "\n", 1);
  return (0);
}