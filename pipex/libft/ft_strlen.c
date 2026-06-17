/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoward <ahoward@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 18:36:55 by ahoward           #+#    #+#             */
/*   Updated: 2025/07/20 05:55:35 by ahoward          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen(const char *str)
{
	int	num;

	num = 0;
	while (*str != '\0')
	{
		str++;
		num++;
	}
	return (num);
}

// int	main(void)
// {
// 	char	*str;

// 	str = "muahahaha\0";
// 	ft_strlen(str);
// 	printf("%s", str);
// 	printf("\n%d", ft_strlen(str));
// 	return (0);
// }
