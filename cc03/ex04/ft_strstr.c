char  *ft_strstr(char *str, char *to_find)
{
  int i;
  int j;

  i = 0;
  while (str[i] != '\0')
  {
    j = 0;
    while (to_find[j] != '\0')
    {
      if (str[i] == to_find[j])
        return (to_find);
      else
        return (0);
      j++;
    }
  }
}