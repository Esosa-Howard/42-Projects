/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoward <ahoward@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 11:08:08 by ahoward           #+#    #+#             */
/*   Updated: 2025/07/20 05:22:42 by ahoward          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*prt;

	i = 0;
	prt = (unsigned char *)s;
	while (n > i)
	{
		if (prt[i] == (unsigned char)c)
			return ((void *) &prt[i]);
		i++;
	}
	return (NULL);
}

// int main(void)
// {
// 	char huh[] = {"greetings"};
// 	char *s;

// 	s = ft_memchr(huh, 'o', 10);
// 	printf("%s\n", huh);
// 	printf("%s\n", s);
// }
