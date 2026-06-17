/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoward <ahoward@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 20:21:26 by ahoward           #+#    #+#             */
/*   Updated: 2025/07/30 17:02:55 by ahoward          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count(char const *s, char c)
{
	int	a;
	int	count;

	a = 0;
	count = 0;
	while (*s != '\0')
	{
		if (*s != c && a == 0)
		{
			a = 1;
			count++;
		}
		else if (*s == c)
		{
			a = 0;
		}
		s++;
	}
	return (count);
}

static void	*ft_free(void **prts, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(prts[i]);
		i++;
	}
	free(prts);
	return (NULL);
}

char	*fill_word( const char *str, int start, int end)
{
	int		i;
	char	*word;

	i = 0;
	word = malloc((end - start + 1) * sizeof(char));
	if (word == NULL)
		return (NULL);
	while (start < end)
	{
		word[i] = str[start];
		i++;
		start++;
	}
	word[i] = '\0';
	return (word);
}

static void	initialize(int *s_word, size_t *i, int *j)
{
	*s_word = -1;
	*i = 0;
	*j = 0;
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	i;
	int		j;
	int		s_word;

	initialize(&s_word, &i, &j);
	str = ft_calloc((ft_count(s, c) + 1), sizeof(char *));
	if (str == NULL)
		return (NULL);
	while (i <= (size_t)ft_strlen(s))
	{
		if (s[i] != c && s_word < 0)
			s_word = i;
		else if ((s[i] == c || i == (size_t)ft_strlen(s)) && s_word >= 0)
		{
			str[j] = fill_word(s, s_word, i);
			if (str[j] == NULL)
				return (ft_free((void **)str, j));
			s_word = -1;
			j++;
		}
		i++;
	}
	str[j] = NULL;
	return (str);
}
// int	main(void)
// {
// 	char	*str = "madsshatter";
// 	char	**result;
// 	int	i;

// 	i = 0;
// 	result = ft_split(str, 's');
// 	while (result[i])
// 	{
// 		printf("%s\n", result[i]);
// 		i++;
// 	}
// 	return (0);
// }
