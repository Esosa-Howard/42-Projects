/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoward <ahoward@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 21:13:48 by ahoward           #+#    #+#             */
/*   Updated: 2025/08/24 20:06:25 by ahoward          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_num(long nbr, int base)
{
	int		count;
	char	digit;

	count = 0;
	if (nbr < 0)
	{
		count += write(1, "-", 1);
		if (count == -1)
			return (-1);
		count += print_num(-nbr, base);
	}
	else if (nbr > 9)
	{
		count += print_num(nbr / base, base);
		if (count == -1)
			return (-1);
		count += print_num(nbr % base, base);
	}
	else
	{
		digit = nbr + '0';
		count += write(1, &digit, 1);
	}
	return (count);
}

int	print_hexa(unsigned long nbr, int base)
{
	int		count;
	char	*symbols;

	count = 0;
	symbols = "0123456789abcdef";
	if (nbr < (unsigned long)base)
	{
		count += print_char(symbols[nbr]);
		if (count == -1)
			return (-1);
		return (count);
	}
	else
	{
		count += print_hexa(nbr / base, base);
		if (count == -1)
			return (-1);
		count += print_hexa(nbr % base, base);
		if (count == -1)
			return (-1);
	}
	return (count);
}

int	print_hexa_cap(unsigned long nbr, int base)
{
	int		count;
	char	*symbols;

	count = 0;
	symbols = "0123456789ABCDEF";
	if (nbr < (unsigned long)base)
	{
		count += print_char(symbols[nbr]);
		if (count == -1)
			return (-1);
		return (count);
	}
	else
	{
		count += print_hexa_cap(nbr / base, base);
		if (count == -1)
			return (-1);
		count += print_hexa_cap(nbr % base, base);
		if (count == -1)
			return (-1);
	}
	return (count);
}

int	print_prt(const void *prt)
{
	int					count;
	unsigned long long	value;

	count = 0;
	value = (unsigned long long)prt;
	if (!prt)
	{
		if (write(1, NULL_STRING, NULL_STRING_LENGTH) == -1)
			return (-1);
		return (NULL_STRING_LENGTH);
	}
	count += print_str("0x");
	if (count == -1)
		return (-1);
	count += print_hexa(value, 16);
	if (!count)
		return (-1);
	return (count);
}
