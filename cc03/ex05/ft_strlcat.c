unsigned int  ft_strlcat(char *dest, char *src, unsigned int size)
{
  int d;
  int s;

  d = 0;
  s = 0;
  while (dest[d] != '\0')
    d++;
  while (src[s] != '\0' && s <= size)
  {
    dest[d + s] = src[s];
    s++;
  }
  dest[d + s] = '\0';
  return (d + s);
}
int main(void)
{
  char a[] = "test";
  char b[] = "12356";

  printf("size: %d\n cat a: %s\n ", ft_strlcat(a,b,3), b);
}
