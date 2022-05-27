/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjociles <sjociles@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 15:18:05 by sjociles          #+#    #+#             */
/*   Updated: 2022/05/27 16:58:26 by sjociles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/libftprintf.h"
#include <stdio.h>


static int	ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

static void	ft_putstr(char *str)
{
	while (*str++ != '\0')
		write(1, &*str, 1);
}

static int	ft_printstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		ft_putstr("(NULL)"); // funcion recursiva?
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

static int	ft_printnbr(int n)
{
	char	*num;
	
	num = ft_itoa(n);
	//free num?
	return (ft_printstr(num));
}

static int	ft_printptrlen(unsigned long long n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		len++;
		n = n / 16;
	}
	return (len);
}

static void	ft_ptrhex(unsigned long long n)
{		
	if (n >= 16)
	{
		ft_ptrhex(n / 16);
		ft_ptrhex(n % 16);
	}
	else
	{
		if (n <= 9)
			ft_putchar_fd((n + '0'), 1);
		else
			ft_putchar_fd((n - 10 + 'a'), 1);
	}
}

static int	ft_printptr(unsigned long long ptr)
{
	int	len;

	len = 0;
	len += write(1, "0x", 2);
	if (ptr == 0)
		len += write(1, "0", 1);
	else
	{
		ft_ptrhex(ptr);
		len += ft_printptrlen(ptr);
	}
	return (len);
}

/*
static int	ft_printdecimal(unsigned int n)
{

}

static int	ft_printhex(unsigned int n, const char format)
{
	if (format == 'x')
	{
		ft_printptr(n);
	}
	else if (format == 'X')
	{
		ft_printptr(n);
		if 
	}

}
*/
static int	ft_conversion(va_list args, const char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += ft_printchar(va_arg(args, int));
	else if (format == 's')
		len += ft_printstr(va_arg(args, char *));
	else if (format == 'p')
		len += ft_printptr(va_arg(args, unsigned long long)); // por qué long long?
	else if (format == 'd' || format == 'i')
		len += ft_printnbr(va_arg(args, int));
/*	else if (format == 'x' || format == 'X')
		len += ft_printhex(va_arg(args, unsigned int), format);
	else if (format == 'u')
		len += ft_printdecimal(va_arg(args, unsigned int));
*/	else if (format == '%')
		len += ft_printchar('%');
	return (len);
}

int ft_printf(char const *format, ...)
{
	int		i;
	va_list	args;
	int		len;

	va_start(args, format);
	i = 0;
	len = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			len += ft_conversion(args, format[i + 1]); // 1 para coger el identificativo
			i++;
		}
		else
			len = ft_printchar(format[i]);
		i++;
	}
	va_end(args);
	return (len);
}

int	main ()
{
	char	c = 't';
	char	str[] = "caca es mi amiga";
	char	*ptr = "hola";
	int		num = -2147483648;

	ft_printf("%c\n", c);
	ft_printf("%s\n", str);
	ft_printf("%p\n", *ptr);
	ft_printf("%%\n");
	printf("%X\n", 62);
	ft_printf("%i\n", num);
	return (0);
}
