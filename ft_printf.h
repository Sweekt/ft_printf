/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroy <beroy@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 19:12:47 by beroy             #+#    #+#             */
/*   Updated: 2023/11/22 15:21:16 by beroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <limits.h>

int		ft_printf(const char *str, ...);
ssize_t	ft_putchar(int c);
ssize_t	ft_putstr(char *str);
void	ft_putnbr_base(ssize_t nbr, char *str, ssize_t *length);
void	ft_putnbr_ul(size_t nbr, char *str, ssize_t *length);

#endif