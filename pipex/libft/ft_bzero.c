/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoward <ahoward@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 12:49:12 by ahoward           #+#    #+#             */
/*   Updated: 2025/07/18 18:58:01 by ahoward          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*c;
	size_t	i;

	i = 0;
	c = (char *)s;
	while (i < n)
	{
		c[i] = '\0';
		i++;
	}
}
// int main(void)
// {
// 	char str[20] = "hello";

// 	printf("%s", str);
// 	ft_bzero(str, 5);
// 	printf("\n%s", str);
// }
