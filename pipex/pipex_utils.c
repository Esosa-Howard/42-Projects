/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoward <ahoward@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 14:24:40 by ahoward           #+#    #+#             */
/*   Updated: 2025/12/03 15:51:57 by ahoward          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	call_error(int err_type)
{
	if (err_type == 1)
	{
		perror("Process was unable to be forked\n");
		exit(1);
	}
	else if (err_type == 2)
	{
		perror("Pipe was unable to be made\n");
		exit(1);
	}
	else
	{
		perror("Command was not able to be executed\n");
		exit(1);
	}
}

static char	*append_cmd(char **dir, char *cmd)
{
	char	*path;
	char	*tmp;
	int		i;

	i = 0;
	while (dir[i])
	{
		tmp = ft_strjoin(dir[i], "/");
		path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(path, X_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	return (NULL);
}

static char	*get_envp(char **envp)
{
	char	*path;
	int		i;

	i = -1;
	if (!envp)
		return (NULL);
	while (envp[++i])
	{
		if (ft_strnstr(envp[i], "PATH=", 5))
		{
			path = envp[i] + 5;
			return (path);
		}
	}
	return (NULL);
}

char	*find_path(char **cmd, char **envp)
{
	char	**dir;
	char	*cmd_path;

	cmd_path = NULL;
	if (!cmd || !*cmd)
		return (NULL);
	if (ft_strchr(cmd[0], '/') && (access(cmd[0], X_OK) == 0))
	{
		cmd_path = ft_strdup(cmd[0]);
		return (cmd_path);
	}
	else
		cmd_path = get_envp(envp);
	if (!cmd_path)
	{
		perror("Failed to find PATH\n");
		return (NULL);
	}
	dir = ft_split(cmd_path, ':');
	if (!dir)
		return (NULL);
	cmd_path = append_cmd(dir, cmd[0]);
	free(dir);
	return (cmd_path);
}
