/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isghioua <isghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 19:33:07 by isghioua          #+#    #+#             */
/*   Updated: 2021/07/10 19:33:08 by isghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

/**
 * Try this:
 *
 * 	< dsdhfas ls
 * 	No such file or directory
 *
 * ==> So I should read INSIDE the CHILD PROCESS and if doesn't work,
 * 		should exit from the child  process
 *
 * 	Why close fd after dup2 ?
 * 	check for the right path of program before writing anything
 * 	Why close fd in the parent process  before waiting for the process ?
**/

int	first_cmd(int redirection, char *file_input, t_cmd *s_cmd)
{
	int		fds[2];
	int		pid;
	int		fd_input;
	char	*binary_program;

	error_pipe(pipe(fds));
	pid = fork();
	error_fork(pid);
	if (pid == 0)
	{
		fd_input = get_fd_input(redirection, file_input);
		if (dup2(fd_input, 0) == -1)
			exit(1);
		close(fd_input);
		binary_program = check_for_the_right_path(s_cmd->path, s_cmd->command);
		if (!binary_program)
			exit(127);
		close(fds[0]);
		if (dup2(fds[1], 1) == -1)
			exit(1);
		close(fds[1]);
		execve(binary_program, s_cmd->args, NULL);
	}
	close(fds[1]);
	return (fds[0]);
}
