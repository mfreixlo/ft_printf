#include "../includes/ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	len;

	len = 0;
	if (s == NULL)
		return (ft_putstr("(null)"));
	while (s[len])
	{
		ft_putchar(s[len]);
		len++;
	}
	return (len);
}

//str[10], pq max unsigned int = 4294967295
int	ft_putunsint(unsigned int nbr)
{
	char	str[10];
	int		i;
	int		j;

	i = 0;
	if (nbr == 0)
	{
		ft_putnbr_fd(0, 1);
		return (1);
	}
	while (nbr > 0)
	{
		str[i++] = nbr % 10 + '0';
		nbr = nbr / 10;
	}
	j = i;
	while (--i >= 0)
		ft_putchar(str[i]);
	return (j);
}

//str[10], pq max unsigned int = 18,446,744,073,709,551,615
int	ft_putpointer(unsigned long long ptr)
{
	char	str[20];
	int		i;
	char	*hex;
	int		j;

	i = 0;
	if (ptr > 0)
		j = ft_putstr("0x");
	else
		return (ft_putstr("(nil)"));
	hex = malloc(sizeof(char) * 18);
	ft_strlcpy(hex, "0123456789abcdef", 17);
	while (ptr > 0)
	{
		str[i++] = hex[ptr % 16];
		ptr = ptr / 16;
	}
	j += i;
	while (--i >= 0)
		ft_putchar(str[i]);
	free(hex);
	return (j);
}

//max unsigned int 4,294,967,295
int	ft_putx(unsigned int n, int fun)
{
	char	str[10];
	int		i;
	char	*hex;
	int		j;

	if (n == 0)
		return (ft_putchar('0'));
	hex = malloc(sizeof(char) * 18);
	if (fun == 0)
		ft_strlcpy(hex, "0123456789abcdef", 17);
	else if (fun == 1)
		ft_strlcpy(hex, "0123456789ABCDEF", 17);
	i = 0;
	while (n > 0)
	{
		str[i++] = hex[n % 16];
		n = n / 16;
	}
	j = i;
	while (--i >= 0)
		ft_putchar(str[i]);
	free(hex);
	return (j);
}
