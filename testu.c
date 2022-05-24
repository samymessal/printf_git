#include "ft_printf.h"

static int	ft_symbol(char c, t_var x)
{
	unsigned long long int	t;
	int	len;

	t = 0;
	len = 0;
	if (c == 'c' || c == '%')
		len += ft_putchar_fd(x.d, 1);
	else if (c == 's')
		len += ft_putstr_fd(x.s, 1);
	else if (c == 'd' || c == 'i')
		ft_putnbr_fd(x.d, 1);
	else if (c == 'p')
	{
		if (x.l)
		{
			t = (unsigned long long int)x.l;
			write(1, "0x", 2);
			ft_putnbr_base(t, "0123456789abcdef") + 2;
		}
		else
		{
			write(1, "(nil)", 5);
			len = 5;
		}
	}
	else if (c == 'u')
		ft_putnbr_fd(x.u, 1);
	else if (c == 'x')
		ft_putnbr_base(x.d, "0123456789abcdef");
	else if (c == 'X')
		ft_putnbr_base(x.d, "0123456789ABCDEF");
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		len;
	t_var	typ;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			if (str[i + 1] == 'c' || str[i + 1] == 'd' || str[i + 1] == 'i'
				|| str[i + 1] == 'x' || str[i + 1] == 'X')
				typ.d = va_arg(args, int);
			else if (str[i + 1] == 'p')
				typ.l = va_arg(args, long long int);
			else if (str[i + 1] == 's')
				typ.s = va_arg(args, char *);
			else if (str[i + 1] == 'u')
				typ.u = va_arg(args, unsigned int);
		//	else if (str[i + 1] == '%')
		//		write(1, "%", 1);
			if (str[i + 1] != '%' && str[i + 1])
				len += ft_symbol(str[++i], typ);
			i++;
		}
		if (str[i])
            len += ft_putchar_fd(str[i], 1);
		i++;
	}
	va_end(args);
	return (len);
}

int	main()
{
    int x = printf("%c\n", '0');
    printf("%d", x);

    int y = ft_printf("%c", '0');
    ft_printf("%d", y);
}
