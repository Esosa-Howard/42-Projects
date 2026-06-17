/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoward <ahoward@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 01:20:56 by ahoward           #+#    #+#             */
/*   Updated: 2025/08/24 20:05:24 by ahoward          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(int c)
{
	int	count;

	count = 0;
	count += write(1, &c, 1);
	if (count == -1)
		return (-1);
	return (1);
}

int	print_str(char *str)
{
	int	count;

	count = 0;
	if (!str)
	{
		if (write(1, "(null)", 6) == -1)
			return (-1);
		return (6);
	}
	while (str[count])
	{
		if (write(1, &str[count], 1) == -1)
			return (-1);
		count++;
	}
	return (count);
}

int	op_format(char specifier, va_list arg)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += print_char(va_arg(arg, int));
	else if (specifier == 's')
		count += print_str(va_arg(arg, char *));
	else if (specifier == 'd' || specifier == 'i')
		count += print_num((long)va_arg(arg, int), 10);
	else if (specifier == 'X')
		count += print_hexa_cap((unsigned long)va_arg(arg, unsigned int), 16);
	else if (specifier == 'x')
		count += print_hexa((unsigned long)va_arg(arg, unsigned int), 16);
	else if (specifier == 'p')
		count += print_prt(va_arg(arg, const void *));
	else if (specifier == 'u')
		count += print_num(va_arg(arg, unsigned int), 10);
	else if (specifier == '%')
		count += print_char('%');
	else
		return (-1);
	if (count == -1)
		return (-1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		count;
	int		temp;

	count = 0;
	va_start(arg, format);
	while (*format)
	{
		if (*format == '%')
		{
			temp = op_format(*(++format), arg);
			if (temp == -1)
				return (-1);
		}
		else if (write(1, format, 1) == -1)
			return (-1);
		else
			temp = 1;
		count += temp;
		format++;
	}
	va_end(arg);
	return (count);
}
// int main(void)
// {
// 	int	count;
// 	int	count1;
// 	// char v;
// 	// char *prt;

// 	// v = 'a';
// 	// prt = &v;
// 	count = ft_printf("%d\n", -12212);
// 	count1 = printf("%d\n", -12212);
// 	printf("%d\n", count);
// 	printf("%d\n", count1);
// }
