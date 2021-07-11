/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_the_right_path.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isghioua <isghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 19:35:28 by isghioua          #+#    #+#             */
/*   Updated: 2021/07/10 19:35:29 by isghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

char	*check_for_the_right_path(char **env_path, char *cmd)
{
	char	*path;
	char	*tmp;
	int		access_rights;
	int		i;

	i = -1;
	while (env_path[++i])
	{
		tmp = ft_strjoin(env_path[i], "/");
		path = ft_strjoin(tmp, cmd);
		free(tmp);
		access_rights = access(path, F_OK | X_OK);
		if (access_rights == 0)
			return (path);
		else
			free(path);
	}
	write(1, cmd, ft_strlen(cmd));
	write(1, ": Command not found\n", 20);
	return (NULL);
}
