/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoward <ahoward@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 17:02:13 by ahoward           #+#    #+#             */
/*   Updated: 2025/07/29 18:47:39 by ahoward          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*a;

	a = (char *)b;
	while (len > 0)
	{
		*a = c;
		a++;
		len--;
	}
	return (b);
}

// int main(void)
// {
// 	char str[20] = "hello";
// 	char s[20] = "hello";

// 	printf("%s\n", memset(str, 'y', 1));
// 	printf ("%s\n", str);
// 	printf("%s\n", ft_memset(s, 'y', 1));
// }
