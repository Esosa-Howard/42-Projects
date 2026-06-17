/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoward <ahoward@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 15:55:22 by ahoward           #+#    #+#             */
/*   Updated: 2025/07/20 05:23:46 by ahoward          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;

	a = (unsigned char *)s1;
	b = (unsigned char *)s2;
	while (n > 0)
	{
		if (*a != *b)
		{
			return (*a - *b);
		}
		n--;
		a++;
		b++;
	}
	return (0);
}
// int main(void)
// {
// 	char s1[] = "greetings";
// 	char s2[] = "greetings";

// 	printf("%s\n", s1);
// 	printf("%s\n", s2);
// 	printf("%d\n", ft_memcmp(s1, s2, 10));
// }
