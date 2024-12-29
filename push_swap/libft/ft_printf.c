/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhkim <suhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:58:58 by suhkim            #+#    #+#             */
/*   Updated: 2022/11/10 19:04:23 by suhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"
#include <unistd.h>

static int	put_char(char c)
{
	return (write(1, &c, 1));
}

static int	put_string(char *str)
{
	int	cnt;

	cnt = 0;
	if (!str)
		return (write(1, "(null)", 6));
	else
		while (*(str + cnt))
			write(1, str + cnt++, 1);
	return (cnt);
}

static int	put_nbr(unsigned long num, char mode)
{
	int	b;

	b = 0;
	if (mode == 'p')
	{
		write(1, "0x", 2);
		return (2 + ft_putnbr_base(num, "0123456789abcdef", 16, &b));
	}
	else if (mode == 'd' || mode == 'i')
	{
		if ((int)num < 0)
		{
			b += write(1, "-", 1);
			num = (unsigned long)(-1 * (int)num);
		}
		return (ft_putnbr_base((unsigned int)num, "0123456789", 10, &b));
	}
	else if (mode == 'u')
		return (ft_putnbr_base((unsigned int)num, "0123456789", 10, &b));
	else if (mode == 'x')
		return (ft_putnbr_base((unsigned int)num, "0123456789abcdef", 16, &b));
	else if (mode == 'X')
		return (ft_putnbr_base((unsigned int)num, "0123456789ABCDEF", 16, &b));
	else
		return (0);
}

static int	check_param(const char **format, va_list ap)
{
	*format += 1;
	if (**format == '%')
		return (write(1, "%", 1));
	else if (**format == 'c')
		return (put_char((char)va_arg(ap, int)));
	else if (**format == 's')
		return (put_string(va_arg(ap, char *)));
	else if (**format == 'p')
		return (put_nbr(va_arg(ap, unsigned long), **format));
	else if (**format == 'd' || **format == 'i')
		return (put_nbr(va_arg(ap, int), **format));
	else if (**format == 'u')
		return (put_nbr(va_arg(ap, unsigned int), **format));
	else if (**format == 'x')
		return (put_nbr(va_arg(ap, unsigned int), **format));
	else if (**format == 'X')
		return (put_nbr(va_arg(ap, unsigned int), **format));
	else
		return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		nbyte;

	va_start(ap, format);
	nbyte = 0;
	while (*format)
	{
		if (*format == '%')
		{
			nbyte += check_param(&format, ap);
			format++;
		}
		else
		{
			nbyte += write(1, format, 1);
			format++;
		}
	}
	va_end(ap);
	return (nbyte);
}
