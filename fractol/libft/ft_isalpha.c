/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoward <ahoward@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 16:19:32 by ahoward           #+#    #+#             */
/*   Updated: 2025/07/29 17:34:20 by ahoward          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 97 && c <= 122) || (c >= 65 && c <= 90))
		return (c);
	return (0);
}
// int	main(void)
// {
// 	char c;

// 	c =')';
// 	if (ft_isalpha(c))
// 		printf("Miles\n");
// 	else
// 		printf("Peter\n");
// 	return (0);
// }
