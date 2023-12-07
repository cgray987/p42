
#include <unistd.h>

int ft_strcmp(char *s1, char *s2)
{
  while (*s1 || *s2)
  {
    if (*s1 != *s2)
      return ((unsigned char)*s1 - (unsigned char)*s2);
    s1++;
    s2++;
  }
  return (0);
}
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    if (argc == 3)
        printf("ft_strcmp(\"%s\", \"%s\") = %d\n", argv[1], argv[2], strcmp(argv[1], argv[2]));
    return(0);
}