/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoward <ahoward@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 22:08:06 by ahoward           #+#    #+#             */
/*   Updated: 2025/08/24 20:05:44 by ahoward          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# if defined(__linux__)
#  define NULL_STRING "(nil)"
#  define NULL_STRING_LENGTH 5
# elif defined(__APPLE__)
#  define NULL_STRING "0x0"
#  define NULL_STRING_LENGTH 3
# endif

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

int	ft_printf(const char *format, ...);
int	op_format(char specifier, va_list arg);
int	print_prt(const void *prt);
int	print_hexa(unsigned long nbr, int base);
int	print_num(long nbr, int base);
int	print_str(char *str);
int	print_char(int c);
int	print_hexa_cap(unsigned long nbr, int base);

#endif
