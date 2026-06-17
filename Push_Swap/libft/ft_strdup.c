/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoward <ahoward@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 17:18:07 by ahoward           #+#    #+#             */
/*   Updated: 2025/07/20 06:05:47 by ahoward          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*s2;

	i = 0;
	s2 = (char *) malloc(ft_strlen(s1) + 1);
	if (s2 == 0)
	{
		return (NULL);
	}
	while (s1[i] != '\0')
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = 0;
	return (s2);
}
// int main(void)
// {
// 	char s1[] = "muhahahaha";
// 	char *s2;

// 	s2 = ft_strdup(s1);
// 	printf("%s\n", s1);
// 	printf("%s\n", s2);
// }
