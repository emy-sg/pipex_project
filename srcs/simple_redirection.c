/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_redirection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isghioua <isghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 19:36:41 by isghioua          #+#    #+#             */
/*   Updated: 2021/07/10 19:36:42 by isghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	simple_redirection(int argc, char **argv, char **envp)
{
	t_cmd_line	s_cmd_line;
	int			nbr_of_args;

	nbr_of_args = argc - 1;
	if (nbr_of_args >= 4)
	{
		s_cmd_line.file_input = argv[1];
		s_cmd_line.file_output = argv[nbr_of_args];
		s_cmd_line.nbr_of_cmds = nbr_of_args - 2;
		fill_linked_list_of_cmds(&s_cmd_line, argv + 2, envp);
		execution_part(1, &s_cmd_line);
		lst_clear_cmds(&s_cmd_line);
	}
	else
	{
		write(1, "The number of args must be five arguments\n", 42);
		exit(1);
	}		
}
