
int main(int ac, char **av)
{
  char *str;

  if (ac == 2)
  {
    str = av[1];
    while (*str)
      str++;
  }
}