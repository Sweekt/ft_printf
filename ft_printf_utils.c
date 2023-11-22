/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroy <beroy@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 19:18:35 by beroy             #+#    #+#             */
/*   Updated: 2023/11/22 15:23:00 by beroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(char *str)
{
	ssize_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

ssize_t	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

ssize_t	ft_putstr(char *str)
{
	ssize_t	i;

	i = 0;
	if (!str)
		return (ft_putstr("(null)"));
	while (str[i])
		i += ft_putchar(str[i]);
	return (i);
}

void	ft_putnbr_base(ssize_t nbr, char *str, ssize_t *lenght)
{
	if (nbr < 0)
	{
		*lenght += ft_putchar('-');
		ft_putnbr_base(nbr * -1, str, lenght);
	}
	else
	{
		if (nbr >= (ssize_t)ft_strlen(str))
		{
			ft_putnbr_base(nbr / ft_strlen(str), str, lenght);
			ft_putnbr_base(nbr % ft_strlen(str), str, lenght);
		}
		else
			*lenght += ft_putchar(str[nbr]);
	}
}

void	ft_putnbr_ul(size_t nbr, char *str, ssize_t *lenght)
{
	if (nbr >= ft_strlen(str))
	{
		ft_putnbr_ul(nbr / ft_strlen(str), str, lenght);
		ft_putnbr_ul(nbr % ft_strlen(str), str, lenght);
	}
	else
		*lenght += ft_putchar(str[nbr]);
}
