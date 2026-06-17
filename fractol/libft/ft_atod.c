/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoward <ahoward@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 16:22:07 by ahoward           #+#    #+#             */
/*   Updated: 2026/01/02 22:09:25 by ahoward          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ws(const char c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == ' ' || c == '\r')
		return (1);
	return (0);
}

static double	double_up(const char *s, int i)
{
	double	factor;
	double	nbr;

	nbr = 0;
	factor = 1.0;
	while (s[i] >= '0' && s[i] <= '9')
	{
		nbr = nbr * 10 + (s[i] - '0');
		i++;
	}
	if (s[i] == '.')
	{
		i++;
		while (s[i] >= '0' && s[i] <= '9')
		{
			factor /= 10;
			nbr += (s[i] - '0') * factor;
			i++;
		}
	}
	return (nbr);
}

double	ft_atod(const char *s)
{
	double	nbr;
	int		sign;
	int		i;

	i = 0;
	sign = 1;
	nbr = 0;
	while (ws(s[i]))
		i++;
	if (s[i] == '+' || s[i] == '-')
	{
		sign = -1;
		i++;
	}
	nbr = double_up(s, i);
	return (nbr * sign);
}

// int main()
// {
// 	char	*str;
// 	double test;

// 	str = "1.0";
// 	test = ft_atod(str);
// 	printf("%f", test);
// }