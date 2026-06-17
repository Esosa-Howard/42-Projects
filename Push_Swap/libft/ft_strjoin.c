/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoward <ahoward@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 21:09:15 by ahoward           #+#    #+#             */
/*   Updated: 2025/08/20 02:14:00 by ahoward          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*s3;

	j = 0;
	i = 0;
	s3 = malloc(ft_strlen(s1) + ft_strlen(s2) + 1 * sizeof(char));
	if (s3 == 0)
		return (NULL);
	while (s1[i] != '\0')
	{
		s3[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		s3[j] = s2[i];
		i++;
		j++;
	}
	s3[j] = 0;
	return (s3);
}
// int main(void)
// {
// 	char str[] = "concen";
// 	char str1[] = "trate";
// 	char *str2;

// 	str2 = ft_strjoin(str, str1);
// 	printf("%s\n""%s\n", str, str1);
// 	printf("%s\n", str2);
// }
