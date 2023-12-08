

#include <unistd.h>

int skip_spaces(char *s, int i)
{
  while (s[i] && (s[i] == ' ' || s[i] == '\t'))
      ++i;
  return (i);
}

int word_len(char *s)
{
  int i = 0;

  while (s[i] && s[i] != ' ' && s[i] != '\t')
    ++i;
  return (i);
}

int main(int ac, char **av)
{
  char  *str;
  int   i = 0;
  int   first_word = 1;
  int   wordlen = 0;

  if (ac == 2)
  {
    str = av[1];
    while (str[i])
    {
      i = skip_spaces(str, i);
      if (first_word == 0)
        write(1, "   ", 3);
      wordlen = word_len(str + i);
      write(1, str + i, wordlen);
      i = i + wordlen;
      first_word = 0;
      i = skip_spaces(str, i);
    }
  }
  write(1, "\n", 1);
}