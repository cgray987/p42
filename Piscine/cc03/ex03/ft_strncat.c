char *ft_strncat(char *dest, char *src, unsigned int nb)
{
  char dest[100];
  int i;
  int j;

  i = 0;
  j = 0;
  while (dest[i] != '\0')
    i++;
  while (src[j] != '\0' && j <= nb)
  {
    dest[i + j] = src[j];
    j++;
  }
  dest[i+j] = '\0';
  return (dest);
}

int main(void)
{
  printf("%c/n",ft_strncat("hello", "world", 3));
}