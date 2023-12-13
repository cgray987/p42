
#include <unistd.h>

int old_num(char *str, int max_pos, char c)
{
  int i = 0;

  while (i < max_pos)
  {
    if (str[i] == c)
      return (0);
    i++;
  }
  return (1);
}

void  ft_union(char *s1, char *s2)
{
int i = 0;
int j = 0;

  while (s1[i])
  {
    if (old_num(s1, i, s1[i])) //hasn't been repeated so far in s1
    {
      write(1, &s1[i], 1);
    }
    i++;    
  }

  while (s2[j])
  {
    if (old_num(s1, i, s2[j]) && old_num(s2, j, s2[j]))
    //s2 doesn't appear in s1 && hasn't been repeated in s2
    {
      write(1, &s2[j], 1);
    }
    j++;    
  }

}

int main(int ac, char **av)
{
  if (ac == 3)
  {
    ft_union(av[1], av[2]);
  }
  write(1, "\n", 1);
}