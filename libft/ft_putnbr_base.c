/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 19:57:41 by smessal           #+#    #+#             */
/*   Updated: 2022/05/24 20:19:52 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft.h"

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

void	ft_putnbr_base(unsigned int nbr, char *base)
{
	unsigned int	len_base;
	unsigned char			val;

	len_base = 0;
	if (!ft_check_conditions(base))
		return ;
	while (base[len_base])
		len_base++;
	if (nbr >= len_base)
	{
		ft_putnbr_base(nbr / len_base, base);
		ft_putnbr_base(nbr % len_base, base);
	}
	else
	{
		val = base[nbr];
		write(1, &val, 1);
	}
	return ;
}
