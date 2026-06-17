/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoward <ahoward@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 14:17:16 by ahoward           #+#    #+#             */
/*   Updated: 2025/07/30 15:49:11 by ahoward          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*str1;
	char	*str2;
	size_t	i;

	i = 0;
	str1 = (char *)dst;
	str2 = (char *)src;
	if (!dst && !src)
		return (NULL);
	if (src < dst && src + len >= dst)
	{
		while (i++ < len)
		{
			str1[len - i] = str2[len - i];
		}
	}
	while (i++ < len)
	{
		*str1 = *str2;
		str1++;
		str2++;
	}
	return (dst);
}
// int main(void)
// {
// 	char str1[20] = "hello";
// 	char str2[20];

// 	char str3[20] = "lslal";
// 	char str4[20];

// 	memmove(str2, str1, 5);
// 	printf("%s\n""%s\n", str1, str2);

// 	ft_memmove(str4, str3, 5);
// 	printf("%s\n""%s\n", str3, str4);
// }
