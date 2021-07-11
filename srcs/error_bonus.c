/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isghioua <isghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 19:31:47 by isghioua          #+#    #+#             */
/*   Updated: 2021/07/10 19:31:51 by isghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

/**
 *	int open(char *pathname, int flags, mode_t mode);
 *
 *	- flags : O_RDONLY | O_WRONLY | O_RDWR | O_CREAT | O_TRUNC | O_APPEND
 *	- mode : 00744
 *		- S_IRWXU 00700 : User has read, write, and execute permission
 *		- S_IRGRP 00040 : Group has read permission
 *		- S_IROTH 00004 : Others have read permission
 *
 **/

int	get_fd_input(int redirection, char *file_input)
{
	int	fd_input;

	if (redirection == 1)
	{
		fd_input = open(file_input, O_RDONLY);
		error_file(fd_input, file_input);
	}
	else
	{
		fd_input = open("/tmp/here_doc_input", O_RDWR | O_CREAT
				| O_TRUNC, S_IRWXU | S_IRGRP | S_IROTH);
		error_file(fd_input, "/tmp/here_doc_input");
		read_from_terminal(fd_input, file_input);
		close(fd_input);
		fd_input = open("/tmp/here_doc_input", O_RDONLY);
	}
	return (fd_input);
}

int	get_fd_output(int redirection, char *file_output)
{
	int	fd_output;

	if (redirection == 1)
	{
		fd_output = open(file_output, O_RDWR | O_CREAT
				| O_TRUNC, S_IRWXU | S_IRGRP | S_IROTH);
		error_file(fd_output, file_output);
	}
	else
	{
		fd_output = open(file_output, O_RDWR | O_CREAT
				| O_APPEND, S_IRWXU | S_IRGRP | S_IROTH);
		error_file(fd_output, file_output);
	}
	return (fd_output);
}

void	error_file(int fd, char *file)
{
	if (fd == -1)
	{
		perror(file);
		exit(1);
	}
}

void	error_pipe(int pipe_fd)
{
	if (pipe_fd == -1)
	{
		perror("PIPE FAILURE");
		exit(1);
	}
}

void	error_fork(int pid)
{
	if (pid == -1)
	{
		perror("FORK FAILURE");
		exit(1);
	}
}
