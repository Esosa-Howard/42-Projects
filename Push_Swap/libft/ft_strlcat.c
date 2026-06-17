/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoward <ahoward@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:51:35 by ahoward           #+#    #+#             */
/*   Updated: 2025/07/29 18:33:51 by ahoward          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t			i;
	unsigned int	len_d;
	unsigned int	len_s;
	unsigned int	offset;

	i = 0;
	len_d = ft_strlen(dst);
	len_s = ft_strlen(src);
	offset = len_d;
	if (dstsize == 0)
		return (len_s);
	if (dstsize < len_d)
		return (dstsize + len_s);
	while (src[i] != '\0' && len_d + i + 1 < dstsize)
	{
		dst[offset] = src[i];
		offset++;
		i++;
	}
	if (offset < dstsize)
		dst[offset] = '\0';
	return (len_d + len_s);
}
// int	main(void)
// {
// 		char	s1[] = "what exactly do\0";
// 	char	s2[] = " you want?\0";
// 	char	s3[] = "what exactly do\0";
// 	char	s4[] = " you want?\0";

// 	printf("%s\n", s1);
// 	printf("%zu\n", ft_strlcat(s1, s2, 1));
// 	printf("%lu\n", strlcat(s3, s4, 1));
// 	printf("%s", s3);
// 	return (0);
// }
