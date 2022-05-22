/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 12:01:51 by smessal           #+#    #+#             */
/*   Updated: 2022/05/22 18:28:23 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"
# include <limits.h>

int	ft_printf(const char *, ...);

typedef struct s_var
{
	char			a;
	int				d;
	char			*s;
	unsigned int	u;
	long long int	l;
}			t_var;

#endif
