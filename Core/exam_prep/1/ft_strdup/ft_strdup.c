
#include <unistd.h>

char  *ft_strdup(const char *s1)
{
  int i;
  char *dup;

  i = 0;
  while (s1[i])
    i++;
  dup = malloc(i + 1);
  if (!dup)
    return (NULL);
  i = 0;
  while (s1[i])
  {
    dup[i] = s1[i];
    i++;
  }
  dup[i] = '\0';
  return (dup);
}