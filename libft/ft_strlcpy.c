/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoward <ahoward@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 15:59:22 by ahoward           #+#    #+#             */
/*   Updated: 2025/07/29 21:44:28 by ahoward          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;

	src_len = ft_strlen(src);
	if (src_len + 1 < dstsize)
	{
		ft_memcpy(dst, src, src_len + 1);
	}
	else if (dstsize != 0)
	{
		ft_memcpy(dst, src, dstsize - 1);
		dst[dstsize - 1] = 0;
	}
	return (src_len);
}
// int main(void)
// {
// 	char str1[6] = "hello";
// 	char str2[6];

// 	char str3[8] = "stretch";
// 	char str4[8];

// 	strlcpy(str2, str1, 6);
// 	printf("%s\n""%s\n", str1, str2);

// 	ft_strlcpy(str4, str3, 8);
// 	printf("%s\n""%s\n", str3, str4);
// }
