/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoward <ahoward@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 12:37:38 by ahoward           #+#    #+#             */
/*   Updated: 2025/12/03 15:34:12 by ahoward          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int	file_fd[2];

	if (argc != 5)
	{
		write(1, "False Usage\n", 13);
		exit(1);
	}
	file_fd[0] = open(argv[1], O_RDONLY);
	if (file_fd[0] < 0)
		perror("File does not exist\n");
	file_fd[1] = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (file_fd[1] < 0)
		perror("File was not able to be made\n");
	run_processes(file_fd[0], file_fd[1], argv, envp);
	return (0);
}
