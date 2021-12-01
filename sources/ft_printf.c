#include "../includes/ft_printf.h"

int	ft_is_type(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
		|| c == 'u' || c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	else
		return (0);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int len;

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
	char str[10];
	int i;
	int j;

	i = 0;
	if (nbr == 0)
	{
		ft_putnbr_fd(0, 1);
		return (1);
	}
	while (nbr > 0)
	{
		str[i++] = nbr%10 + '0';
		nbr = nbr/10;
	}
	j = i;
	while (--i >= 0)
		ft_putchar(str[i]);
	return (j);
}

//str[10], pq max unsigned int = 18,446,744,073,709,551,615
int	ft_putpointer(unsigned long long ptr)
{
	char str[20];
	int i;
	char *hex;
	int j;

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
		ptr = ptr/16;
	}
	j += i;
	while (--i >= 0)
		ft_putchar(str[i]);
	free(hex);
	return (j);
}

//max unsigned int 4,294,967,295
int ft_putx(unsigned int n, int fun)
{
	char str[10];
	int i;
	char *hex;
	int j;

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
		n = n/16;
	}
	j = i;
	while (--i >= 0)
		ft_putchar(str[i]);
	free(hex);
	return (j);
}

int num_size(int n)
{

	if (n == -2147483648)
		return (11);
	else if (n < 0)
		return(1 + num_size(n * -1));
	else if (n >= 10)
		return (1 + num_size(n / 10));
	else
		return (1);
}



int	ft_arg(char c, va_list ap)
{
	int d;
	if (c == 'c')
		return (ft_putchar(va_arg(ap, int)));
	else if (c == 'd' || c == 'i')
	{
		d = va_arg(ap, int);
		ft_putnbr_fd(d, 1);
		return (num_size(d));
	}
	else if (c == 's')
		return (ft_putstr(va_arg(ap, char *))); //tenho de por o putstr a imprimir null
	else if (c == 'p')
		return (ft_putpointer(va_arg(ap, unsigned long long))); //quando e null nao imprimo nada e o verdadeiro imprime null
	else if (c == 'u')
		return (ft_putunsint(va_arg(ap, unsigned int)));
	else if (c == 'x')
		return (ft_putx((unsigned long long)va_arg(ap, int), 0));
	else if (c == 'X')
		return (ft_putx((unsigned long long)va_arg(ap, int), 1));
	else if (c == '%')
		return (ft_putchar('%'));
	else
		return (0);
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int letters;

	letters = 0;
	i = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			if (ft_is_type(str[i + 1]))
			{
				letters += ft_arg(str[i + 1], ap);
				i++;
			}
		}
		else if (str[i] != '%')
		{
			ft_putchar(str[i]);
			letters++;
		}
		i++;
	}	
	va_end(ap);
	return (letters);
}
/*
int	main(void)
{
	char str[50] = "jksfkdshfjhsdk";
	unsigned int d = 28365843;
	void	*ptr;
   	char	*nb;
	int long max = 4294967295 + 1;

	ptr = str;

	printf("\n%d\n", ft_printf("%x", 0));
	printf("\n%d\n", printf("%x", 0));
	printf("\n");

	return(0);
}
*/






