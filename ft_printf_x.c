/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjociles <sjociles@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 15:18:05 by sjociles          #+#    #+#             */
/*   Updated: 2022/06/01 16:51:16 by sjociles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/ft_printf.h"

int	ft_hexlen(unsigned int n)
{
	unsigned int	len;

	len = 0;
	while (n != 0)
	{
		len++;
		n = n / 16;
	}
	return (len);
}

void	ft_hexing(unsigned int n, const char format)
{
	if (n <= 9)
		ft_putchar_fd((n + '0'), 1);
	else
	{
		if (format == 'x')
			ft_putchar_fd((n - 10 + 'a'), 1);
		else if (format == 'X')
			ft_putchar_fd((n - 10 + 'A'), 1);
	}
}

int	ft_printhex(unsigned int n, const char format)
{
	if (n == 0)
	{
		write (1, "0", 1);
		return (1);
	}
	else
	{
		if (n >= 16)
		{
			ft_printhex((n / 16), format);
			ft_printhex((n % 16), format);
		}
		else
			ft_hexing(n, format);
	}
	return (ft_hexlen(n));
}
