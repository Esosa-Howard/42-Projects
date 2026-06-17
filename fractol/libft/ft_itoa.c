/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoward <ahoward@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 02:02:10 by ahoward           #+#    #+#             */
/*   Updated: 2025/07/29 22:02:02 by ahoward          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	int_len(long c)
{
	int	count;

	count = 0;
	if (c < 0)
		count++;
	c = -c;
	if (c == 0)
		count++;
	while (c != 0)
	{
		c /= 10;
		count++;
	}
	return (count);
}

static char	*allocate(int len)
{
	char	*temp;

	temp = malloc((len + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	temp[0] = '0';
	return (temp);
}

char	*ft_itoa(int n)
{
	int		len;
	int		i;
	char	*result;
	long	conv;

	i = 0;
	conv = n;
	len = int_len(conv);
	result = allocate(len);
	if (!result)
		return (NULL);
	if (conv < 0)
		conv = -conv;
	i = len -1;
	while (conv != 0)
	{
		result[i] = ((conv % 10) + 48);
		conv = conv / 10;
		i--;
	}
	if (n < 0)
		result[0] = '-';
	result[len] = 0;
	return (result);
}
// int	main(void)
// {
// 	int	i = -152;

// 	printf("%d\n", i);
// 	printf("%s\n", ft_itoa(i));
// }
