/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 12:01:51 by smessal           #+#    #+#             */
/*   Updated: 2022/05/23 17:27:34 by smessal          ###   ########.fr       */
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

typedef struct s_var
{
	char			a;
	int				d;
	char			*s;
	unsigned int	u;
	long long int	l;
}			t_var;

#endif
