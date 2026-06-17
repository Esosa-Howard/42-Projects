/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoward <ahoward@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 16:32:09 by ahoward           #+#    #+#             */
/*   Updated: 2025/12/02 19:43:26 by ahoward          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	if (*needle == '\0' )
		return ((char *)haystack);
	while (haystack[i] != '\0')
	{
		j = 0;
		while (haystack[i] == needle[j] && haystack[i] != '\0' && i < len)
		{
			i++;
			j++;
		}
		if (needle[j] == '\0')
		{
			return ((char *)&haystack[i - j]);
		}
		i = (i - j) + 1;
	}
	return (NULL);
}
// int main(void)
// {
// 	char str1[] = "controlle yourself to be patient";
// 	char str2[] = "to";
// 	char *str3;

// 	str3 = ft_strnstr(str1, str2, 33);
// 	printf("%s\n", str1);
// 	printf("%s\n", str2);
// 	printf("%s\n", str3);
// }
