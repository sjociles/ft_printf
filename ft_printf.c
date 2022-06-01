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
#include <stdio.h>
#include <stddef.h>

static int	ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

static void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

static int	ft_printstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		ft_putstr("(null)");
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
	int		len;
	char	*num;
	
	if (n == 0)
		return (ft_printstr("0"));
	len = 0;
	num = ft_itoa(n);
	free(num);
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

static int	ft_numlen(unsigned int n)
{
	unsigned int	len;
	unsigned int	num;

	len = 0;
	num = n;
	while (num != 0)
	{
		len++;
		num = num / 10;
	}
	return (len);
}

char	*ft_uitoa(unsigned int n)
{
	char	*num;
	int		len;
	
	len = ft_numlen(n);
	num = (char *)malloc(sizeof(char) * (len + 1));
	if (!num)
		return (0);
	num[len] = '\0';
	while (n != 0)
	{
		num[len - 1] = n % 10 + 48;
		n = n / 10;
		len--;
	}
	return (num);
}


static int	ft_printu(unsigned int n)
{
	int		len;
	char	*num;

	len = 0;
	if (n == 0)
		len += write(1, "0", 1);
	else
	{
		num = ft_uitoa(n);
		len += ft_printstr(num);
		free(num);
	}
	return (len);		
}

static int	ft_hexlen(unsigned int n)
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

static int	ft_printhex(unsigned int n, const char format)
{
	if (n == 0)
	{
		write (1, "0", 1);
		return (1);
	}
	else
		if (n >= 16)
		{
 			ft_printhex((n / 16), format);
			ft_printhex((n % 16), format);
		}
		else
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
	return (ft_hexlen(n));
}

int	ft_conversion(va_list args, const char format)
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
	else if (format == 'x' || format == 'X')
		len += ft_printhex(va_arg(args, unsigned int), format);
	else if (format == 'u')
		len += ft_printu(va_arg(args, unsigned int));
	else if (format == '%')
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
			len += ft_printchar(format[i]);
		i++;
	}
	va_end(args);
	return (len);
}

int	main ()
{
//	char	c = 't';
//	char	str[] = "";
//	char	*ptr = "hola";
//	int		num = -2147483648;

//	ft_printf("%c\n", c);
//	ft_printf("%d\n", -10);
//	printf("%d\n", -10);
	ft_printf("X%s/3G,%sE73>%i\ra%dcybgx!", "I7^44p,#\\+zvD\tk\n", "S\r8<N}4PV9!\rqNnWe*mDIFl)YY,{ #qdl,\r\\1L $\\\n\n", -1616717919, -1634989699);
	printf("X%s/3G,%sE73>%i\ra%dcybgx!", "I7^44p,#\\+zvD\tk\n", "S\r8<N}4PV9!\rqNnWe*mDIFl)YY,{ #qdl,\r\\1L $\\\n", -1616717919, -1634989699);
//	ft_printf("%X\n", 62);
//	ft_printf("%x\n", 0);
//	ft_printf("%i\n", num);
	return (0);
}
