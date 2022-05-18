/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 12:07:04 by smessal           #+#    #+#             */
/*   Updated: 2022/05/18 20:22:18 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	ft_symbol(char c, t_var x)
{
	if (c == 'c' || c == '%')
		ft_putchar_fd(x.d, 1);
	else if (c == 's')
		ft_putstr_fd(x.s, 1);
	else if (c == 'd' || c == 'i')
		ft_putstr_fd(ft_itoa(x.d), 1);
	else if (c == 'u')
		ft_putstr_fd(ft_itoa(x.u), 1);
	else if (c == 'x')
		ft_putnbr_base(x.d, "0123456789abcdef");
	else if (c == 'X')
		ft_putnbr_base(x.d, "0123456789ABCDEF");
	return ;
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	t_var	typ;

	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			if (str[i + 1] == 'c' || str[i + 1] == 'd' || str[i + 1] == 'i'
				|| str[i + 1] == 'x' || str[i + 1] == 'X')
				typ.d = va_arg(args, int);
			else if (str[i + 1] == 's')
				typ.s = va_arg(args, char *);
			else if (str[i + 1] == 'u')
				typ.u = va_arg(args, unsigned int);
			if (str[i + 1] == '%')
				write(1, "%", 1);
			else
				ft_symbol(str[++i], typ);
			i++;
		}
		ft_putchar_fd(str[i], 1);
		i++;
	}
	return (i);
}

int	main()
{
	ft_printf("char: %c \nstring: %s \nint: %d \nunsigned:%u\nhexa:%x\nHEXA:%X\nPourcent:%%\n",'A', "lol",12345487, -4578, 58455, 58455);
	printf("\nORIGINAL\nchar: %c \nstring: %s \nint:%d\nunsigned:%u\nhexa:%x\nHEXA: %X\nPourcent:%%",'A', "lol", 12345487, -4578, 58455, 58455);
}
