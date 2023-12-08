
int nbr_in_base(char c, int base)
{
  if (base <= 10)
    return (c >= '0' && c <= '9');
  else
    return ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'a' + base - 10) || (c >= 'A' && c <= 'A' + base - 10));
}

int ft_atoi_base(const char *str, int base)
{
  int i = 0;
  int num = 0;
  int neg = 1;

  if (str[i] == '-')
  {
    neg = -1;
    i++;
  }
  while (str[i] && nbr_in_base(str[i], base))
  {
    if ((str[i] >= 'A' && str[i] <= 'F'))
      num = num * base + str[i] - 'A' + 10;
    if ((str[i] >= 'a' && str[i] <= 'f'))
      num = num * base + str[i] - 'a' + 10;
    else if ((str[i] >= '0' && str[i] <= '9'))
      num = num * base + str[i] - '0';
    i++;
  }
  return (num * neg);
}

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  printf("%d\n", ft_atoi_base("011", atoi("2")));
  printf("%d\n", ft_atoi_base("16", atoi("8")));
  printf("%d\n", ft_atoi_base("123", atoi("10")));
  printf("%d\n", ft_atoi_base("FF", atoi("16")));
}