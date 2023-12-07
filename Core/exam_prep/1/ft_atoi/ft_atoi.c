

#include <unistd.h>
#include <limits.h>
#include <stdio.h>

int ft_atoi(const char *str)
{
  int num;
  int neg;

  num = 0;
  neg = 1;
  while (*str == ' ' || (*str >= 9 && *str <= 13))
    str++;
  if (*str == '-' || *str == '+')
  {
    if (*str == '-')
      neg = -1;
    str++;
  }
  while (*str >= '0' && *str <= '9')
  {
    num = num * 10 + *str - '0';
    str++;
  }
  return (num * neg);
}
int main(int ac, char **av)
{
  if (ac == 2)
  {
    printf("%d\n", ft_atoi(av[1]));
  }
  else
    write(1, "\n", 1);
  return (0);
}