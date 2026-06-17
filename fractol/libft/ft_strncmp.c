/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoward <ahoward@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 18:36:49 by ahoward           #+#    #+#             */
/*   Updated: 2025/12/14 10:08:15 by ahoward          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		i++;
	}
	return (0);
}
// int main(void)
// {
// 	char str1[] = "the moon hunts you";
// 	char str2[] = "the moon hunts you";

// 	// printf("%s\n", str1);
// 	// printf("%s\n", str2);
// 	// printf("%d\n", ft_strncmp(str1, str2, 19));
// 	if (!ft_strncmp(str1, str2, 19))
// 		printf("yes indeed\n");
// }
