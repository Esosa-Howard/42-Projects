/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoward <ahoward@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 17:22:35 by ahoward           #+#    #+#             */
/*   Updated: 2025/07/20 05:59:09 by ahoward          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*prt;

	prt = 0;
	while (*s != '\0')
	{
		if ((unsigned char)*s == (unsigned char )c)
			prt = s;
		s++;
	}
	if (*s == (unsigned char)c)
		return ((char *)s);
	else
		return ((char *)prt);
}
// int main(void)
// {
// 	char str[] = "the string that strings stringers";
// 	char *l;

// 	l = ft_strrchr(str, 'c');
// 	printf("%s\n", str);
// 	printf("%s\n", l);
// }
