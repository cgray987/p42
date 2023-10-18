void ft_putnum(int nb)
{
  int digits;
  int i;

  digits = nb;
  i = 0;

  while (digits >= 0)
  {
    digits /= 10;
    i++;
  }
  write (1, nb, i);
}
