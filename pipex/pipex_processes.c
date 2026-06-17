/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_processes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoward <ahoward@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 14:16:28 by ahoward           #+#    #+#             */
/*   Updated: 2025/12/03 15:31:27 by ahoward          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	first_process(int infile, char *cmd, char **envp, int *fd)
{
	char	**args;
	char	*cmd_path;

	cmd_path = NULL;
	if (dup2(infile, STDIN_FILENO) == -1)
		perror("dup2 function faild\n");
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		perror("dup2 ffunction faild\n");
	close(infile);
	close(fd[0]);
	close(fd[1]);
	args = ft_split(cmd, ' ');
	if (!args)
		exit(1);
	cmd_path = find_path(args, envp);
	if (!cmd_path)
	{
		perror("No such command found\n");
		exit(1);
	}
	if (execve(cmd_path, args, envp) == -1)
		(call_error(3));
	exit(0);
}

static void	second_process(int outfile, char *cmd, char **envp, int	*fd)
{
	char	**args;
	char	*cmd_path;

	cmd_path = NULL;
	if (dup2(fd[0], STDIN_FILENO) == -1)
		perror("dup2 ffunction faild\n");
	if (dup2(outfile, STDOUT_FILENO) == -1)
		perror("dup2 function faild\n");
	close(fd[0]);
	close(fd[1]);
	close(outfile);
	args = ft_split(cmd, ' ');
	if (!args)
		exit(1);
	cmd_path = find_path(args, envp);
	if (!cmd_path)
	{
		perror("No such command found\n");
		exit(1);
	}
	if (execve(cmd_path, args, envp) == -1)
		call_error(3);
	exit(0);
}

void	run_processes(int infile, int outfile, char **argv, char **envp)
{
	int	pid1;
	int	pid2;
	int	fd[2];

	if (pipe(fd) == -1)
		call_error(2);
	pid1 = fork();
	if (pid1 < 0)
		call_error(1);
	if (pid1 == 0)
		first_process(infile, argv[2], envp, fd);
	pid2 = fork();
	if (pid2 < 0)
		call_error(1);
	if (pid2 == 0)
		second_process(outfile, argv[3], envp, fd);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	exit(0);
}
