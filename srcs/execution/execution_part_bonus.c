/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_part_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isghioua <isghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 19:32:43 by isghioua          #+#    #+#             */
/*   Updated: 2021/07/10 19:32:46 by isghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex_bonus.h"

/**
 *
 *	Why parent process has to close fd of a pipe before calling wait()?
 *
 *	https://stackoverflow.com/questions/31107139/why-parent-process-has-to
 				-close-all-file-descriptors-of-a-pipe-before-calling-wa
 *
 **/

void	execution_part(int redirection, t_cmd_line *s_cmd_line)
{
	int	pid_of_last_cmd;
	int	nbr_of_cmds;

	pid_of_last_cmd = launching_child_processes(redirection, s_cmd_line);
	nbr_of_cmds = s_cmd_line->nbr_of_cmds;
	waiting_for_processes(nbr_of_cmds, pid_of_last_cmd);
}
