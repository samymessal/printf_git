/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 19:57:41 by smessal           #+#    #+#             */
/*   Updated: 2022/05/22 19:16:54 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_duplicates(char *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i;
		while (++j < size)
		{
			if (tab[j] == tab[i])
			{
				return (0);
			}
		}
		i++;
	}
	return (1);
}

static int	ft_check_conditions(char *base)
{
	int	len_base;

	len_base = 0;
	while (base[len_base])
	{
		if (base[len_base] == '+' || base[len_base] == '-')
			return (0);
		len_base++;
	}
	if (len_base <= 1 || !ft_check_duplicates(base, len_base))
		return (0);
	else
		return (1);
}

int	ft_putnbr_base(long long int nbr, char *base)
{
	long long int	len_base;
	unsigned char	val;
	long long int	nbr_long;
	long long int	len;

	len_base = 0;
	len = 0;
	nbr_long = nbr;
	if (!ft_check_conditions(base))
		return (0);
	while (base[len_base])
		len_base++;
	if (nbr_long < 0)
	{
		write(1, "-", 1);
		nbr_long *= -1;
		len++;
	}
	if (nbr_long >= len_base)
	{
		ft_putnbr_base(nbr_long / len_base, base);
		ft_putnbr_base(nbr_long % len_base, base);
	}
	else
	{
		val = base[nbr_long];
		len++;
		write(1, &val, 1);
	}
	return (len);
}

int	main()
{
	ft_putnbr_base(55555566885555555, "0123456789abcdef");
}
