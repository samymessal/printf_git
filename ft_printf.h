/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 12:01:51 by smessal           #+#    #+#             */
/*   Updated: 2022/05/24 19:10:09 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"
# include <limits.h>

int	ft_printf(const char *str, ...);
int	ft_lenp(unsigned long long int);
int	ft_lennbr(int n);
int	ft_lenuns(unsigned int n);
int	ft_lenhexa(unsigned long long int n);


typedef struct s_var
{
	char					a;
	int						d;
	char					*s;
	unsigned int			u;
	unsigned long long int	l;
}			t_var;

#endif
