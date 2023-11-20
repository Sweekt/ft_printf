/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroy <beroy@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 19:03:15 by beroy             #+#    #+#             */
/*   Updated: 2023/11/20 19:40:07 by beroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int ft_printf(const char *str, ...)
{
	size_t	i;
	va_list	arg;

	i = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] != '%')
			ft_putchar(str[i]);
		else
		{
			ft_checkarg(str[i + 1], arg);
			va_arg(arg, int);
			i++;
		}
		i++;
	}
}