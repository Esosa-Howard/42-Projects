/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoward <ahoward@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 13:38:22 by ahoward           #+#    #+#             */
/*   Updated: 2025/12/02 23:04:38 by ahoward          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include "../libft/libft.h"
# include "ft_printf.h"
# include <stdio.h>

void	run_processes(int infile, int outfile, char **argv, char **env);
void	call_error(int err_type);
char	*find_path(char **cmd, char **envp);

#endif