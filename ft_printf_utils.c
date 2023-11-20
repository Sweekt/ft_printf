/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroy <beroy@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 19:18:35 by beroy             #+#    #+#             */
/*   Updated: 2023/11/20 19:49:12 by beroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putchar(const char c)
{
	write(1, &c, 1);
}

void	ft_checkarg(const char c, va_list arg)
{
	if (c == 'c')
		ft_putchar(arg);
	else if (c == 's')
		ft_putstr(arg);
	else if (c == 'p')
		??;
	else if (c == 'd')
		??;
	else if (c == 'i')
		ft_putnbr(arg);
	else if (c == 'u')
		??;
	else if (c == 'x')
		ft_putnbr_hex(arg, 1);
	else if (c == 'X')
		ft_putnbr_hex(arg, 2);
	else if (c == '%')
		ft_putchar('%');
}