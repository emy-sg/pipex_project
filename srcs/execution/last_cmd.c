/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isghioua <isghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 19:33:17 by isghioua          #+#    #+#             */
/*   Updated: 2021/07/10 19:33:18 by isghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

int	last_cmd(int redirection, int fd_input, t_cmd *s_cmd, char *file_output)
{
	int		fd_output;
	int		pid;
	char	*binary_program;

	pid = fork();
	error_fork(pid);
	if (pid == 0)
	{
		if (dup2(fd_input, 0) == -1)
			exit(1);
		close(fd_input);
		fd_output = get_fd_output(redirection, file_output);
		binary_program = check_for_the_right_path(s_cmd->path, s_cmd->command);
		if (!binary_program)
			exit(127);
		if (dup2(fd_output, 1) == -1)
			exit(1);
		close(fd_output);
		execve(binary_program, s_cmd->args, NULL);
	}
	close(fd_input);
	return (pid);
}
