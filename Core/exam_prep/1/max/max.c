
#include <unistd.h>
#include <stdio.h>

int max(int *tab, unsigned int len)
{
  int max = tab[len];

  while (len > 0)
  {
    if (max <= tab[len])
      max = tab[len];
    len--;
  }
  return (max);
}

int main(void)
{
  int tab[] = {-1234, -432, -312345, -5123454};
  int len = 4;

  printf("%d\n", max(tab, len));
}