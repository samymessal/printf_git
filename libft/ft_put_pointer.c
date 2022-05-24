/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:19:46 by smessal           #+#    #+#             */
/*   Updated: 2022/05/24 17:36:12 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_put_pointer(unsigned long long int nbr, char *base)
{
	unsigned long long int	len_base;
	unsigned char			val;

	len_base = 0;
	while (base[len_base])
		len_base++;
	if (nbr >= len_base)
	{
		ft_put_pointer(nbr / len_base, base);
		ft_put_pointer(nbr % len_base, base);
	}
	else
	{
		val = base[nbr];
		write(1, &val, 1);
	}
	return ;
}