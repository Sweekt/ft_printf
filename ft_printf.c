/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroy <beroy@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 19:03:15 by beroy             #+#    #+#             */
/*   Updated: 2023/11/27 16:37:38 by beroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printmemory(size_t arg, ssize_t *lenght)
{
	if ((char *)arg == NULL)
	{
		*lenght = ft_putstr("(nil)");
		return ;
	}
	*lenght = ft_putstr("0x");
	if (*lenght == -1)
		return ;
	ft_putnbr_ul(arg, "0123456789abcdef", lenght);
}

int	ft_checkarg(const char c, va_list arg)
{
	ssize_t	lenght;

	lenght = 0;
	if (c == 'c')
		lenght = ft_putchar((unsigned char)va_arg(arg, int));
	else if (c == 's')
		lenght = ft_putstr(va_arg(arg, char *));
	else if (c == 'p')
		ft_printmemory((size_t)va_arg(arg, size_t), &lenght);
	else if (c == 'd' || c == 'i')
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
			lenght += ft_checkarg(str[i++ + 1], args);
		else
			lenght = -1;
		if (lenght == -1)
			break ;
		i++;
	}
	return (lenght);
}
