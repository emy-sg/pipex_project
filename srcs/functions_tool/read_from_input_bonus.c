/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_from_input_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isghioua <isghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 19:35:55 by isghioua          #+#    #+#             */
/*   Updated: 2021/07/10 19:35:56 by isghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex_bonus.h"

/**
 * int main(int ac, char **av)
{
	if (access(av[1], X_OK))
		printf("ERROR\n");
	else
		printf("OK\n");
	return(0);
}
*/

void	read_from_terminal(int fd_input, char *limiter)
{
	char	*line;

	line = NULL;
	write(1, ">", 1);
	if (get_next_line(0, &line) > 0)
	{
		write(fd_input, line, ft_strlen(line));
		free(line);
		line = NULL;
	}
	write(1, ">", 1);
	while (get_next_line(0, &line) > 0)
	{
		if (!ft_strncmp(line, limiter, ft_strlen(limiter))
			&& ft_strlen(line) == ft_strlen(limiter))
		{
			write(fd_input, "\n", 1);
			return ;
		}
		write(fd_input, "\n", 1);
		write(fd_input, line, ft_strlen(line));
		free(line);
		line = NULL;
		write(1, ">", 1);
	}
}
