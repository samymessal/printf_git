/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lens.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:24:58 by smessal           #+#    #+#             */
/*   Updated: 2022/05/24 19:04:34 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_lenp(unsigned long long int nbr)
{
	int	len;

	len = 3;
	while (nbr >= 16)
	{
		nbr /= 16;
		len++;
	}
	return (len);
}

int	ft_lennbr(int n)
{
	long long int	x;
	int				len;

	x = n;
	len = 0;
	if (x < 0)
	{
		x *= -1;
		len++;
	}
	if (x == 0)
		return (1);
	while (x > 0)
	{
		x /= 10;
		len++;
	}
	return (len);
}

int	ft_lenuns(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

int	ft_lenhexa(unsigned long long int n)
{
	int	len;

	len = (n == 0);
	while (n)
	{
		n /= 16;
		len++;
	}
	return (len);
}

// int	main(void)
// {
// 	printf("%d", ft_lenhexa(-9223372036854775807));
// }