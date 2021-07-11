/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_cmd_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isghioua <isghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 19:34:58 by isghioua          #+#    #+#             */
/*   Updated: 2021/07/10 19:34:59 by isghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex_bonus.h"

int	second_cmd(int fd_input, t_cmd *s_cmd)
{
	int		fds[2];
	int		pid;
	char	*binary_program;

	error_pipe(pipe(fds));
	pid = fork();
	error_fork(pid);
	if (pid == 0)
	{
		close(fds[0]);
		if (dup2(fd_input, 0) == -1)
			exit(1);
		close(fd_input);
		binary_program = check_for_the_right_path(s_cmd->path, s_cmd->command);
		if (!binary_program)
			exit(127);
		if (dup2(fds[1], 1) == -1)
			exit(1);
		close(fds[1]);
		execve(binary_program, s_cmd->args, NULL);
	}
	close(fd_input);
	close(fds[1]);
	return (fds[0]);
}
