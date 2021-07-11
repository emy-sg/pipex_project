/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launching_child_processes.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isghioua <isghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 19:33:28 by isghioua          #+#    #+#             */
/*   Updated: 2021/07/10 19:33:29 by isghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

int	launching_child_processes(int type_redirection, t_cmd_line *s_cmd_line)
{
	int		nbr_of_cmds;	
	pid_t	pid_of_last_cmd;
	t_cmd	*s_cmd;
	int		next_input;
	int		i;

	nbr_of_cmds = s_cmd_line->nbr_of_cmds;
	i = 1;
	s_cmd = s_cmd_line->s_cmd;
	while (i <= s_cmd_line->nbr_of_cmds)
	{
		if (i == 1)
			next_input = first_cmd(type_redirection,
					s_cmd_line->file_input, s_cmd);
		else if (i == nbr_of_cmds)
			pid_of_last_cmd = last_cmd(type_redirection,
					next_input, s_cmd, s_cmd_line->file_output);
		else
			next_input = second_cmd(next_input, s_cmd);
		s_cmd = s_cmd->next;
		i++;
	}
	return (pid_of_last_cmd);
}
