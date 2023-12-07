
#include <unistd.h>
#include <stdio.h>
#include <string.h>

size_t  ft_strcspn(const char *s1, const char *charset)
{
  size_t i;
  size_t  j;

  i = 0;
  while (s1[i])
  {
    j = 0;
    while (charset[j])
    {
      if (charset[j] == s1[i])
        return (i);
      j++;
    }
    i++;
  }
  return (i);
}
int	main(void)
{
	printf("%lu\n", ft_strcspn("test", "es"));
	printf("%lu\n", strcspn("test", "es"));
printf("%lu\n", ft_strcspn("test", "f"));
	printf("%lu\n", strcspn("test", "f"));
}