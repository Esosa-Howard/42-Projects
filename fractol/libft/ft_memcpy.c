/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoward <ahoward@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 13:42:28 by ahoward           #+#    #+#             */
/*   Updated: 2025/07/29 16:38:51 by ahoward          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *) dest;
	str2 = (unsigned char *) src;
	if (dest == 0 && src == 0)
		return (dest);
	while (0 < n)
	{
		*str1 = *str2;
		str1++;
		str2++;
		n--;
	}
	return (dest);
}

// int main(void)
// {
// 	char str1[20] = "hello";
// 	char str2[20];

// 	char str3[20] = "hello";
// 	char str4[20];

// 	printf("%s\n", str1);
// 	memcpy(str2, str1, 5);
// 	printf("%s\n""%s\n", str1, str2);

// 	ft_memcpy(str4, str3, 5);
// 	printf("%s\n""%s\n", str3, str4);
// }
