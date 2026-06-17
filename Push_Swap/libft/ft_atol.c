/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoward <ahoward@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 15:07:32 by ahoward           #+#    #+#             */
/*   Updated: 2025/10/06 16:59:32 by ahoward          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	ws(const char c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\r' || c == '\v' || c == '\f')
		return (1);
	return (0);
}

long	ft_atol(const char *str)
{
	long	n;
	int		i;
	long	sign;

	i = 0;
	n = 0;
	sign = 1;
	while (ws(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + (str[i] - '0');
		i++;
	}
	return (n * sign);
}
// int main(void)
// {
// 	char str[] = "2147483647";

// 	printf("%s\n", str);
// 	printf("%ld\n", atol(str));
// 	printf("%ld\n", ft_atol(str));
// }