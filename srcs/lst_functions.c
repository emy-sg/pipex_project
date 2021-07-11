/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isghioua <isghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 19:36:31 by isghioua          #+#    #+#             */
/*   Updated: 2021/07/10 19:36:33 by isghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

/**
	typedef struct			s_cmd
	{
		char			**path;	
		char			*command;
		char			**args;
		struct s_pipe_cmd	*next;
		struct s_pipe_cmd	*previous;
	}				t_cmd;
**/

t_cmd	*lst_new_cmd(char *argv, char **path)
{
	char	**args;
	t_cmd	*s_cmd;

	s_cmd = malloc(sizeof(t_cmd));
	if (argv[0] != '\0')
	{	
		args = ft_split(argv, ' ');
		if (args[0] == '\0')
			s_cmd->command = ft_strdup("");
		else
			s_cmd->command = ft_strdup(args[0]);
		s_cmd->args = args;
	}
	else
	{
		s_cmd->command = ft_strdup("");
		s_cmd->args = malloc(2 * sizeof(char *));
		s_cmd->args[0] = ft_strdup("");
		s_cmd->args[1] = NULL;
	}	
	s_cmd->path = path;
	s_cmd->next = NULL;
	s_cmd->previous = NULL;
	return (s_cmd);
}

void	lst_add_back_cmds(t_cmd_line *s_cmd_line, int indice, t_cmd *s_cmd)
{
	t_cmd	*s_tmp;

	if (indice == 0)
		return (lst_add_front_cmd(s_cmd_line, s_cmd));
	s_tmp = lst_last_cmd(s_cmd_line);
	s_tmp->next = s_cmd;
	s_cmd->previous = s_tmp;
}

void	lst_add_front_cmd(t_cmd_line *s_cmd_line, t_cmd *s_first_cmd)
{
	s_cmd_line->s_cmd = s_first_cmd;
}

t_cmd	*lst_last_cmd(t_cmd_line *s_cmd_line)
{
	t_cmd	*s_next_cmd;

	s_next_cmd = s_cmd_line->s_cmd;
	if (!s_next_cmd)
		return (0);
	while (s_next_cmd->next)
		s_next_cmd = s_next_cmd->next;
	return (s_next_cmd);
}

void	lst_clear_cmds(t_cmd_line *s_cmd_line)
{
	t_cmd	*s_tmp_cmd;

	s_tmp_cmd = s_cmd_line->s_cmd;
	while (s_tmp_cmd)
	{
		s_cmd_line->s_cmd = s_tmp_cmd->next;
		free(s_tmp_cmd->command);
		free_double_table(s_tmp_cmd->args);
		free_double_table(s_tmp_cmd->path);
		free(s_tmp_cmd);
		s_tmp_cmd = s_cmd_line->s_cmd;
	}	
}
