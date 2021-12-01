#include "../includes/ft_printf.h"

int	ft_is_type(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
		|| c == 'u' || c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	else
		return (0);
}

int	num_size(int n)
{
	if (n == -2147483648)
		return (11);
	else if (n < 0)
		return (1 + num_size(n * -1));
	else if (n >= 10)
		return (1 + num_size(n / 10));
	else
		return (1);
}

int	ft_arg(char c, va_list ap)
{
	int	d;

	if (c == 'c')
		return (ft_putchar(va_arg(ap, int)));
	else if (c == 'd' || c == 'i')
	{
		d = va_arg(ap, int);
		ft_putnbr_fd(d, 1);
		return (num_size(d));
	}
	else if (c == 's')
		return (ft_putstr(va_arg(ap, char *)));
	else if (c == 'p')
		return (ft_putpointer(va_arg(ap, unsigned long long)));
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
	int		letters;

	letters = 0;
	i = -1;
	va_start(ap, str);
	while (str[++i])
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
	}	
	va_end(ap);
	return (letters);
}
