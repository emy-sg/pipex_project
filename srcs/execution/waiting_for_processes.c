/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waiting_for_processes.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isghioua <isghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 19:35:13 by isghioua          #+#    #+#             */
/*   Updated: 2021/07/10 19:35:14 by isghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

void	waiting_for_processes(int nbr_of_cmds, int pid_last_cmd)
{
	int	i;
	int	status_code;
	int	wstatus;

	i = 1;
	while (i <= nbr_of_cmds)
	{
		if (wait(&wstatus) == pid_last_cmd)
		{
			if (WIFEXITED(wstatus) > 0)
			{
				status_code = WEXITSTATUS(wstatus);
				if (status_code != 0)
					exit(status_code);
			}
			else
				exit(1);
		}
		i++;
	}
}
