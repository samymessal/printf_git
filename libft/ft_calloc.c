/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:34:16 by smessal           #+#    #+#             */
/*   Updated: 2022/05/18 11:05:05 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	x;

	x = nmemb * size;
	if (nmemb && ((x / nmemb) != size))
		return (NULL);
	ptr = malloc(x);
	if (!ptr)
		return (NULL);
	ft_bzero((char *)ptr, x);
	return ((char *)ptr);
}
