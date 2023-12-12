

#include <stdlib.h>



char	*ft_itoa(int num)
{
	char	*str;
	int		len = 0;
	int		t_num = num;
	int		i = 0;

	if (num == -2147483648) // could also declare t_num as long and do math to it?
	{
		str = malloc(12);
		str = "-2147483648";
		return (str);
	}
	if (t_num <= 0) // add space for '-' if needed
	{
		len++;
		t_num = -t_num;
	}
	while (t_num != 0) // count digits
	{
		len++;
		t_num /= 10;
	}
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (num < 0)
	{
		str[0] = '-';
		num = -num;
	}
	else if (num == 0)
		str[0] = '0';
	len--;
	while (num > 0)
	{
		str[len] = num % 10 + '0';
		num /= 10;
		len--;
	}
	return (str);
}

#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av)
{
	if (ac == 2)
	{	
		printf("%s\n", ft_itoa(atoi(av[1])));
	}
}