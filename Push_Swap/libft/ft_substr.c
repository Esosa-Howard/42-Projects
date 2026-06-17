/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoward <ahoward@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 06:07:25 by ahoward           #+#    #+#             */
/*   Updated: 2025/07/29 22:59:06 by ahoward          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*prt;

	i = 0;
	if (s == 0)
		return (NULL);
	if (start > (unsigned int)ft_strlen(s))
		return (ft_strdup(""));
	if (len > (size_t)ft_strlen(s + start))
		len = ft_strlen(s + start);
	prt = ft_calloc(len + 1, sizeof(char));
	if (prt == 0)
		return (NULL);
	while (i < len)
	{
		prt[i] = s[start + i];
		i++;
	}
	return (prt);
}
// int main(void)
// {
// 	char str[] = "greetings";
// 	char *str1;

// 	str1 = ft_substr(str, 2, 10);
// 	printf("%s\n", str);
// 	printf("%s\n", str1);
// }
