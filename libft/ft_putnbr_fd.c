/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:05:45 by smessal           #+#    #+#             */
/*   Updated: 2022/05/24 17:44:10 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int x;

	x = n;
	if (x == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (x < 0)
	{
		x *= -1;
		write(fd, "-", 1);
	}
	if (x > 9)
	{
		ft_putnbr_fd(x / 10, fd);
		ft_putnbr_fd(x % 10, fd);
	}
	else
	{
		ft_putchar_fd(x + 48, fd);
	}
	return ;
}
