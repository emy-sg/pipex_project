/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_linked_list_of_cmds_bonus.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isghioua <isghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 19:35:33 by isghioua          #+#    #+#             */
/*   Updated: 2021/07/10 19:35:34 by isghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex_bonus.h"

void	fill_linked_list_of_cmds(t_cmd_line *s_cmd_line,
		char **argv, char **envp)
{
	t_cmd	*s_new_cmd;
	char	**path;
	int		i;

	i = 0;
	while (i < s_cmd_line->nbr_of_cmds)
	{
		path = get_env_var_path(envp);
		s_new_cmd = lst_new_cmd(argv[i], path);
		lst_add_back_cmds(s_cmd_line, i, s_new_cmd);
		i++;
	}
}
