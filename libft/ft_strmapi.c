/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoward <ahoward@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 03:35:33 by ahoward           #+#    #+#             */
/*   Updated: 2025/07/29 17:17:51 by ahoward          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	s_count(char const *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*new_s;
	int		len;

	i = 0;
	len = s_count(s);
	new_s = malloc((len + 1) * sizeof(char));
	if (!new_s)
		return (NULL);
	while (i < len)
	{
		new_s[i] = (*f)(i, s[i]);
		i++;
	}
	new_s[i] = 0;
	return (new_s);
}
