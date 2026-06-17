/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoward <ahoward@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 19:17:27 by ahoward           #+#    #+#             */
/*   Updated: 2025/10/17 11:05:48 by ahoward          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*reading_fd(int fd, char *str, int *bytes_read)
{
	char	*buffer;
	char	*temp;

	if (!str)
		str = ft_calloc(1, sizeof(char));
	if (!str)
		return (NULL);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	*bytes_read = 1;
	while (!ft_strchr(str, '\n') && *bytes_read != 0)
	{
		*bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (*bytes_read == -1)
			return (free(buffer), free(str), NULL);
		buffer[*bytes_read] = '\0';
		temp = str;
		str = ft_strjoin(temp, buffer);
		if (!str)
			return (free(buffer), NULL);
		free(temp);
	}
	free(buffer);
	return (str);
}

static char	*next_line(char *buffer_info)
{
	int		i;
	int		j;
	char	*new_line;

	i = 0;
	j = 0;
	while (buffer_info[i] && buffer_info[i] != '\n')
		i++;
	if (!buffer_info[i])
	{
		return (NULL);
	}
	new_line = ft_calloc(ft_strlen(buffer_info) - i + 1, sizeof(char));
	if (!new_line)
		return (NULL);
	if (buffer_info[i] == '\n')
		i++;
	while (buffer_info[i])
	{
		new_line[j++] = buffer_info[i++];
	}
	return (new_line);
}

static char	*cpy_line(char *buffer_info)
{
	int		i;
	char	*new_str;

	i = 0;
	if (!buffer_info[i])
		return (NULL);
	while (buffer_info[i] && buffer_info[i] != '\n')
		i++;
	new_str = ft_calloc(i + 2, sizeof(char));
	if (!new_str)
		return (NULL);
	i = 0;
	while (buffer_info[i] && buffer_info[i] != '\n')
	{
		new_str[i] = buffer_info[i];
		i++;
	}
	if (buffer_info[i] == '\n')
	{
		new_str[i] = buffer_info[i];
		i++;
	}
	return (new_str);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	int			bytes_read;
	char		*buffer_info;

	if (BUFFER_SIZE < 0 || fd < 0)
		return (NULL);
	buffer = reading_fd(fd, buffer, &bytes_read);
	if (!buffer)
		return (NULL);
	line = cpy_line(buffer);
	buffer_info = next_line(buffer);
	free(buffer);
	buffer = buffer_info;
	if (line == NULL && bytes_read == 0)
	{
		free(buffer_info);
		return (NULL);
	}
	return (line);
}
// int	main(void)
// {
// 	int		fd;
// 	char	*result;
// 	int		i;

// 	i = 0;
// 	fd = open("test.txt", O_RDONLY);
// 	printf("fd = %d\n", fd);
// 	if (fd < 0)
// 	{
// 		perror("open");
// 		return (1);
// 	}
// 	while ((result = get_next_line(fd)))
// 	{
// 		if (result == NULL)
// 			break;
// 		i++;
// 		printf("%d: %s",i, result);
// 		free(result);
// 	}
// 	close(fd);
// 	return (0);
// }