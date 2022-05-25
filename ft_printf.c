/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 12:07:04 by smessal           #+#    #+#             */
/*   Updated: 2022/05/25 11:41:58 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_nonvalid(char c)
{
	char	*test;
	int		i;

	i = 0;
	test = "csdipuxX%";
	while (test[i])
	{
		if (test[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_symbol(char c, t_var x)
{
	int	len;

	len = 0;
	if (c == 'c')
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
		if (str[i] == '%' && str[i + 1] && ft_nonvalid(str[i + 1]))
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
			else if (str[i + 1] == '%')
				len += ft_putchar_fd('%', 1);
			len += ft_symbol(str[++i], typ);
		}
		else
			len += ft_putchar_fd(str[i], 1);
		i++;
	}
	va_end(args);
	return (len);
}


// int	main(void)
// {
// 	ft_printf(" %%%%%d ", 42);
// 	//printf(" %s %% %d ", "lol", 42);
// }

// int	main(void)
// {
// 	int		ptr = 42;
// 	void	*second_ptr = &ptr;
// 	int 	my_function_return = 0;
// 	int 	real_function_return = 0;
	
// 	// tests without %
// 	printf("\n----------   without %%   ----------\n\n");
	
// 	my_function_return = ft_printf("my ft_printf : Hello\n");
// 	real_function_return = printf("real printf  : Hello\n");
// 	if (real_function_return == my_function_return)
// 		printf("\033[1;32mReturn is OK : [%d,%d]\033[0m\n\n", my_function_return, real_function_return);
// 	else
// 		printf("\033[1;31mReturn is KO : [%d,%d]\033[0m\n\n", my_function_return, real_function_return);
		
// 	my_function_return = ft_printf("my ft_printf : Hello World!\n");
// 	real_function_return = printf("real printf  : Hello World!\n");
// 	if (real_function_return == my_function_return)
// 		printf("\033[1;32mReturn is OK : [%d,%d]\033[0m\n\n", my_function_return, real_function_return);
// 	else
// 		printf("\033[1;31mReturn is KO : [%d,%d]\033[0m\n\n", my_function_return, real_function_return);

// 	// tests %c
// 	printf("\n----------   %%c   ----------\n\n");

// 	my_function_return = ft_printf("my ft_printf : %c\n", 'c');
// 	real_function_return = printf("real printf  : %c\n", 'c');
// 	if (real_function_return == my_function_return)
// 		printf("\033[1;32mReturn is OK : [%d,%d]\033[0m\n\n", my_function_return, real_function_return);
// 	else
// 		printf("\033[1;31mReturn is KO : [%d,%d]\033[0m\n\n", my_function_return, real_function_return);

// 	my_function_return = ft_printf("my ft_printf : %c\n", 'A');
// 	real_function_return = printf("real printf  : %c\n", 'A');
// 	if (real_function_return == my_function_return)
// 		printf("\033[1;32mReturn is OK : [%d,%d]\033[0m\n\n", my_function_return, real_function_return);
// 	else
// 		printf("\033[1;31mReturn is KO : [%d,%d]\033[0m\n\n", my_function_return, real_function_return);

// 	my_function_return = ft_printf("my ft_printf : %c%c%c\n", 'a', 'b', 'c');
// 	real_function_return = printf("real printf  : %c%c%c\n", 'a', 'b', 'c');
// 	if (real_function_return == my_function_return)
// 		printf("\033[1;32mReturn is OK : [%d,%d]\033[0m\n\n", my_function_return, real_function_return);
// 	else
// 		printf("\033[1;31mReturn is KO : [%d,%d]\033[0m\n\n", my_function_return, real_function_return);

// 	// tests %s
// 	printf("\n----------   %%s   ----------\n\n");

// 	my_function_return = ft_printf("my ft_printf : %s\n", "Hello World!");
// 	real_function_return = printf("real printf  : %s\n", "Hello World!");
// 	if (real_function_return == my_function_return)
// 		printf("\033[1;32mReturn is OK : [%d,%d]\033[0m\n\n", my_function_return, real_function_return);
// 	else
// 		printf("\033[1;31mReturn is KO : [%d,%d]\033[0m\n\n", my_function_return, real_function_return);

// 	my_function_return = ft_printf("my ft_printf : NULL %s NULL\n", NULL);
// 	real_function_return = printf("real printf  : NULL %s NULL\n", NULL);
// 	if (real_function_return == my_function_return)
// 		printf("\033[1;32mReturn is OK : [%d,%d]\033[0m\n\n", my_function_return, real_function_return);
// 	else
// 		printf("\033[1;31mReturn is KO : [%d,%d]\033[0m\n\n", my_function_return, real_function_return);

// 	my_function_return = ft_printf("my ft_printf : %s\n", "AbCdEf");
// 	real_function_return = printf("real printf  : %s\n", "AbCdEf");
// 	if (real_function_return == my_function_return)
// 		printf("\033[1;32mReturn is OK : [%d,%d]\033[0m\n\n", my_function_return, real_function_return);
// 	else
// 		printf("\033[1;31mReturn is KO : [%d,%d]\033[0m\n\n", my_function_return, real_function_return);

// 	// tests %p
// 	printf("\n----------   %%p   ----------\n\n");

// 	my_function_return = ft_printf("my ft_printf : [%p, %p, %p]\n", &ptr, second_ptr, &second_ptr);
// 	real_function_return = printf("real printf  : [%p, %p, %p]\n", &ptr, second_ptr, &second_ptr);
// 	if (real_function_return == my_function_return)
// 		printf("\033[1;32mReturn is OK : [%d,%d]\033[0m\n\n", my_function_return, real_function_return);
// 	else
// 		printf("\033[1;31mReturn is KO : [%d,%d]\033[0m\n\n", my_function_return, real_function_return);

// 	my_function_return = ft_printf("my ft_printf : [%p / %p]\n", LONG_MIN, LONG_MAX);
// 	real_function_return = printf("real printf  : [%p / %p]\n", LONG_MIN, LONG_MAX);
// 	if (real_function_return == my_function_return)
// 		printf("\033[1;32mReturn is OK : [%d,%d]\033[0m\n\n", my_function_return, real_function_return);
// 	else
// 		printf("\033[1;31mReturn is KO : [%d,%d]\033[0m\n\n", my_function_return, real_function_return);

// 	my_function_return = ft_printf("my ft_printf : [%p / %p]\n", 0, 0);
// 	real_function_return = printf("real printf  : [%p / %p]\n", 0, 0);
// 	if (real_function_return == my_function_return)
// 		printf("\033[1;32mReturn is OK : [%d,%d]\033[0m\n\n", my_function_return, real_function_return);
// 	else
// 		printf("\033[1;31mReturn is KO : [%d,%d]\033[0m\n\n", my_function_return, real_function_return);

// 	// tests %d
// 	printf("\n----------   %%d   ----------\n\n");

// 	my_function_return = ft_printf("my ft_printf : [%d, %d, %d, %d]\n", 10 , -10, 42, 0);
// 	real_function_return = printf("real printf  : [%d, %d, %d, %d]\n", 10 , -10, 42, 0);
// 	if (real_function_return == my_function_return)
// 		printf("\033[1;32mReturn is OK : [%d,%d]\033[0m\n\n", my_function_return, real_function_return);
// 	else
// 		printf("\033[1;31mReturn is KO : [%d,%d]\033[0m\n\n", my_function_return, real_function_return);

// 	// tests %i
// 	printf("\n----------   %%i   ----------\n\n");
	
// 	my_function_return = ft_printf("my ft_printf : [%i, %i, %i]\n", (int)-2147483648, (int)2147483647, 0);
// 	real_function_return = printf("real printf  : [%i, %i, %i]\n", (int)-2147483648, (int)2147483647, 0);
// 	if (real_function_return == my_function_return)
// 		printf("\033[1;32mReturn is OK : [%d,%d]\033[0m\n\n", my_function_return, real_function_return);
// 	else
// 		printf("\033[1;31mReturn is KO : [%d,%d]\033[0m\n\n", my_function_return, real_function_return);

// 	// tests %u
// 	printf("\n----------   %%u   ----------\n\n");

// 	my_function_return = ft_printf("my ft_printf : [%u, %u]\n", (unsigned int)10, (unsigned int)0);
// 	real_function_return = printf("real printf  : [%u, %u]\n", (unsigned int)10, (unsigned int)0);
// 	if (real_function_return == my_function_return)
// 		printf("\033[1;32mReturn is OK : [%d,%d]\033[0m\n\n", my_function_return, real_function_return);
// 	else
// 		printf("\033[1;31mReturn is KO : [%d,%d]\033[0m\n\n", my_function_return, real_function_return);

// 	my_function_return = ft_printf("my ft_printf : Hello %u world %u\n", 123, 789);
// 	real_function_return = printf("real printf  : Hello %u world %u\n", 123, 789);
// 	if (real_function_return == my_function_return)
// 		printf("\033[1;32mReturn is OK : [%d,%d]\033[0m\n\n", my_function_return, real_function_return);
// 	else
// 		printf("\033[1;31mReturn is KO : [%d,%d]\033[0m\n\n", my_function_return, real_function_return);
	
// 	my_function_return = ft_printf("my ft_printf : Hello %u world %u\n", -123, 789);
// 	real_function_return = printf("real printf  : Hello %u world %u\n", -123, 789);
// 	if (real_function_return == my_function_return)
// 		printf("\033[1;32mReturn is OK : [%d,%d]\033[0m\n\n", my_function_return, real_function_return);
// 	else
// 		printf("\033[1;31mReturn is KO : [%d,%d]\033[0m\n\n", my_function_return, real_function_return);
		
// 	my_function_return = ft_printf("my ft_printf : %u \n", -10);
// 	real_function_return = printf("real printf  : %u \n", -10);
// 	if (real_function_return == my_function_return)
// 		printf("\033[1;32mReturn is OK : [%d,%d]\033[0m\n\n", my_function_return, real_function_return);
// 	else
// 		printf("\033[1;31mReturn is KO : [%d,%d]\033[0m\n\n", my_function_return, real_function_return);

// 	// tests %x
// 	printf("\n----------   %%x   ----------\n\n");

// 	my_function_return = ft_printf("my ft_printf : [%x, %x, %x, %x, %x]\n", (int)-2147483648, (int)2147483647, 0, -42, 42);
// 	real_function_return = printf("real printf  : [%x, %x, %x, %x, %x]\n", (int)-2147483648, (int)2147483647, 0, -42, 42);
// 	if (real_function_return == my_function_return)
// 		printf("\033[1;32mReturn is OK : [%d,%d]\033[0m\n\n", my_function_return, real_function_return);
// 	else
// 		printf("\033[1;31mReturn is KO : [%d,%d]\033[0m\n\n", my_function_return, real_function_return);

// 	// tests %X
// 	printf("\n----------   %%X   ----------\n\n");

// 	my_function_return = ft_printf("my ft_printf : [%X, %X, %X, %X, %X]\n", (int)-2147483648, (int)2147483647, 0, -42, 42);
// 	real_function_return = printf("real printf  : [%X, %X, %X, %X, %X]\n", (int)-2147483648, (int)2147483647, 0, -42, 42);
// 	if (real_function_return == my_function_return)
// 		printf("\033[1;32mReturn is OK : [%d,%d]\033[0m\n\n", my_function_return, real_function_return);
// 	else
// 		printf("\033[1;31mReturn is KO : [%d,%d]\033[0m\n\n", my_function_return, real_function_return);

// 	// tests %%
// 	printf("\n----------   %%%%   ----------\n\n");

// 	my_function_return = ft_printf("my ft_printf : %%\n");
// 	real_function_return = printf("real printf  : %%\n");
// 	if (real_function_return == my_function_return)
// 		printf("\033[1;32mReturn is OK : [%d,%d]\033[0m\n\n", my_function_return, real_function_return);
// 	else
// 		printf("\033[1;31mReturn is KO : [%d,%d]\033[0m\n\n", my_function_return, real_function_return);

// 	my_function_return = ft_printf("my ft_printf : Hello %%\n");
// 	real_function_return = printf("real printf  : Hello %%\n");
// 	if (real_function_return == my_function_return)
// 		printf("\033[1;32mReturn is OK : [%d,%d]\033[0m\n\n", my_function_return, real_function_return);
// 	else
// 		printf("\033[1;31mReturn is KO : [%d,%d]\033[0m\n\n", my_function_return, real_function_return);

// 	// tests % mixed
// 	printf("\n----------   %% mixed   ----------\n\n");

// 	my_function_return = ft_printf("my ft_printf : Hello %i world %d\n", -123, 789);
// 	real_function_return = printf("real printf  : Hello %i world %d\n", -123, 789);
// 	if (real_function_return == my_function_return)
// 		printf("\033[1;32mReturn is OK : [%d,%d]\033[0m\n\n", my_function_return, real_function_return);
// 	else
// 		printf("\033[1;31mReturn is KO : [%d,%d]\033[0m\n\n", my_function_return, real_function_return);

// 	my_function_return = ft_printf("my ft_printf : Hello %x world %X\n", 123456, -9807);
// 	real_function_return = printf("real printf  : Hello %x world %X\n", 123456, -9807);
// 	if (real_function_return == my_function_return)
// 		printf("\033[1;32mReturn is OK : [%d,%d]\033[0m\n\n", my_function_return, real_function_return);
// 	else
// 		printf("\033[1;31mReturn is KO : [%d,%d]\033[0m\n\n", my_function_return, real_function_return);

// 	my_function_return = ft_printf("my ft_printf : %c%%%s\n", 'c', "hello");
// 	real_function_return = printf("real printf  : %c%%%s\n", 'c', "hello");
// 	if (real_function_return == my_function_return)
// 		printf("\033[1;32mReturn is OK : [%d,%d]\033[0m\n\n", my_function_return, real_function_return);
// 	else
// 		printf("\033[1;31mReturn is KO : [%d,%d]\033[0m\n\n", my_function_return, real_function_return);

// 	my_function_return = ft_printf("my ft_printf : [%%%%%%c%%%%%%]\n");
// 	real_function_return = printf("real printf  : [%%%%%%c%%%%%%]\n");
// 	if (real_function_return == my_function_return)
// 		printf("\033[1;32mReturn is OK : [%d,%d]\033[0m\n\n", my_function_return, real_function_return);
// 	else
// 		printf("\033[1;31mReturn is KO : [%d,%d]\033[0m\n\n", my_function_return, real_function_return);

// 	// tests unvalid %
// 	printf("\n----------   unvalid %%   ----------\n\n");

// 	my_function_return = ft_printf("my ft_printf : Hello %y\n");
// 	real_function_return = printf("real printf  : Hello %y\n");
// 	if (real_function_return == my_function_return)
// 		printf("\033[1;32mReturn is OK : [%d,%d]\033[0m\n\n", my_function_return, real_function_return);
// 	else
// 		printf("\033[1;31mReturn is KO : [%d,%d]\033[0m\n\n", my_function_return, real_function_return);
// }