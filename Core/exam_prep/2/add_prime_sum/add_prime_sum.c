
#include <unistd.h>

void  put_nbr(int n)
{
  char c;

  if (n > 9)
    put_nbr(n / 10);
  c = n % 10 + '0';
  write(1, &c, 1);
}

int ft_atoi(char *s)
{
  int num = 0;

  while (*s >= '0' && *s <= '9')
  {
    num = num * 10 + *s - '0';
    s++;
  }
  return (num);
}

int is_prime(int num) // returns 1 if prime
{
  int i = 2;

  while (i < num)
  {
    if (num % i == 0)
      return (0);
    i++;
  }
  return (1);
}

int add_prime_sum(int num)
{
  int sum = 0;
  int i = 2;

  while (i <= num)
  {
    if (is_prime(i) == 1)
      sum += i;
    ++i;
  }
  return (sum);
}

int main(int ac, char **av)
{
  int num;

  if (ac == 2)
  {
    num = ft_atoi(av[1]);
    if (num > 0)
      put_nbr(add_prime_sum(num));
  }
  else
    put_nbr(0);
  write(1, "\n", 1);
}
