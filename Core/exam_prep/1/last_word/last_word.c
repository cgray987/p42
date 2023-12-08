
#include <unistd.h>

int main(int ac, char **av)
{
  char *str;
  int i = 0;

  if (ac == 2)
  {
    str = av[1];
    while (str[i])
      i++;
    i--;
    while (i > 0 && (str[i] == ' ' || str[i] == '\t'))
        i--;
    while (i > 0 && (str[i] != ' ' && str[i] != '\t'))
        i--;
    if (str[i] == ' ' || str[i] == '\t')
      i++;
    while (str[i] != ' ' && str[i] != '\t' && str[i])
      {
        write(1, &str[i], 1);
        i++;
      }
  }
  write(1, "\n", 1);
}