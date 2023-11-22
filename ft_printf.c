/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroy <beroy@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 19:03:15 by beroy             #+#    #+#             */
/*   Updated: 2023/11/22 15:42:04 by beroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_checkarg(const char c, va_list arg)
{
	ssize_t	lenght;

	lenght = 0;
	if (c == 'c')
		lenght = ft_putchar((unsigned char)va_arg(arg, int));
	else if (c == 's')
		lenght = ft_putstr(va_arg(arg, char *));
	else if (c == 'p')
	{
		lenght = ft_putstr("0x");
		ft_putnbr_ul((size_t)va_arg(arg, size_t), "0123456789abcdef", &lenght);
	}
	else if (c == 'd')
		ft_putnbr_base(va_arg(arg, int), "0123456789", &lenght);
	else if (c == 'i')
		ft_putnbr_base(va_arg(arg, int), "0123456789", &lenght);
	else if (c == 'u')
		ft_putnbr_base(va_arg(arg, unsigned int), "0123456789", &lenght);
	else if (c == 'x')
		ft_putnbr_base(va_arg(arg, unsigned int), "0123456789abcdef", &lenght);
	else if (c == 'X')
		ft_putnbr_base(va_arg(arg, unsigned int), "0123456789ABCDEF", &lenght);
	else if (c == '%')
		lenght += ft_putchar('%');
	return (lenght);
}

int	ft_printf(const char *str, ...)
{
	size_t	i;
	va_list	args;
	ssize_t	lenght;

	i = 0;
	lenght = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] != '%')
			lenght += ft_putchar(str[i]);
		else if (str[i + 1] != 0)
		{
			lenght += ft_checkarg(str[i + 1], args);
			i++;
		}
		else
			lenght = -1;
		if (lenght == -1)
			break ;
		i++;
	}
	return (lenght);
}
