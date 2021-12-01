#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include "../libft/libft.h"
#include <stdarg.h>
#include <limits.h>

int     ft_is_type(char c);
int     ft_putunsint(unsigned int nbr);
int     ft_putpointer(unsigned long long ptr);
int ft_putx(unsigned int n, int fun);
int     ft_arg(char c, va_list ap);
int     ft_printf(const char *str, ...);




#endif
