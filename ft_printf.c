/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjociles <sjociles@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 15:18:05 by sjociles          #+#    #+#             */
/*   Updated: 2022/05/22 15:57:33 by sjociles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libftprintf.h"

int ft_printf(char const *format, ...)
{
	int		i;
	va_list	args;
	int		done;

	va_start(args, format);
	i = 0;
	while (format[i] != '\0')
	{
		done = va_args(args, char);
		i++;
	}




	va_end(args);
	return (done);
}
