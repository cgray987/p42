int ft_strlen(char *str)
{
  int i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}

int main(void)
{
  char s[] = "hello";
  printf("string %s has %d characters\n", &s, ft_strlen(s));
}