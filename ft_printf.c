/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 12:07:04 by smessal           #+#    #+#             */
/*   Updated: 2022/05/24 20:58:10 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_symbol(char c, t_var x)
{
	int	len;

	len = 0;
	if (c == 'c' || c == '%')
		len += ft_putchar_fd(x.d, 1);
	else if (c == 's')
		len += ft_putstr_fd(x.s, 1);
	else if (c == 'd' || c == 'i')
	{
		ft_putnbr_fd(x.d, 1);
		len = ft_lennbr(x.d);
	}
	else if (c == 'p')
	{
		if (x.l)
		{
			write(1, "0x", 2);
			ft_put_pointer(x.l, "0123456789abcdef");
			len = ft_lenp(x.l);
		}
		else
		{
			write(1, "(nil)", 5);
			len = 5;
		}
	}
	else if (c == 'u')
	{
		ft_putunsigned_fd(x.u, 1);
		len = ft_lenuns(x.u);
	}
	else if (c == 'x')
	{
		ft_putnbr_base(x.u, "0123456789abcdef");
		len = ft_lenhexa(x.u);
	}
	else if (c == 'X')
	{
		ft_putnbr_base(x.u, "0123456789ABCDEF");
		len = ft_lenhexa(x.u);
	}
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
			if (str[i + 1] == 'c' || str[i + 1] == 'd' || str[i + 1] == 'i')
				typ.d = va_arg(args, int);
			else if (str[i + 1] == 'p')
				typ.l = va_arg(args, unsigned long long int);
			else if (str[i + 1] == 's')
				typ.s = va_arg(args, char *);
			else if (str[i + 1] == 'u')
				typ.u = va_arg(args, unsigned int);
			else if (str[i + 1] == 'x' || str[i + 1] == 'X')
				typ.u = va_arg(args, unsigned int);
			if (str[i + 1] != '%')
				len += ft_symbol(str[++i], typ);
			i++;
		}
		if (str[i])
			len += ft_putchar_fd(str[i++], 1);
	}
	va_end(args);
	return (len);
}

// int	main()
// {
// 	char	*lol = 0;
// 	int y = ft_printf("char: %c \nstring: %s \nint: %d\nunsigned:%u\nhexa:%x\nHEXA:%X\nPourcent:%%\nPoint: %p\n",'A',"lol",12345487, -4578, 58455, 58455, lol);





// 	int x = printf("\nORIGINAL\nchar: %c \nstring: %s\nint:%d\nunsigned:%u\nhexa:%x\nHEXA: %X\nPourcent:%%\nPoint: %p",'A',"lol", 12345487, -4578, 58455, 58455, lol);
// 	printf("\n%d\n%d",x , y);
// }

// int	main(void)
// {
// 	ft_printf(" %% %d ", 42);
// 	//printf(" %%%%d ", 42);
// }