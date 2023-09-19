int ft_atoi(char *str)
{
  int num;
  int neg;

  num = 0;
  neg = 1;
  while (*str = ' ' || *str >= 9 && *str <= 13)
    str++;
  if (*str == '-' || *str == '+')
  {
    neg *= -1;
    str++;
  }  
  
}