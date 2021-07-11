/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_redirection_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isghioua <isghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 19:36:47 by isghioua          #+#    #+#             */
/*   Updated: 2021/07/10 19:36:48 by isghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	double_redirection(int argc, char **argv, char **envp)
{
	t_cmd_line	s_cmd_line;
	int			nbr_of_args;

	nbr_of_args = argc - 1;
	if (nbr_of_args >= 5)
	{
		s_cmd_line.file_input = argv[2];
		s_cmd_line.file_output = argv[nbr_of_args];
		s_cmd_line.nbr_of_cmds = nbr_of_args - 3;
		fill_linked_list_of_cmds(&s_cmd_line, argv + 3, envp);
		execution_part(2, &s_cmd_line);
		lst_clear_cmds(&s_cmd_line);
	}
	else
	{
		write(1, "The number of args must be five arguments\n", 42);
		exit(1);
	}		
}
