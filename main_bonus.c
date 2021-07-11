/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isghioua <isghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 19:36:52 by isghioua          #+#    #+#             */
/*   Updated: 2021/07/10 19:36:53 by isghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int argc, char **argv, char **envp)
{
	if (argc > 1)
	{
		if (ft_strlen(argv[1]) == 8
			&& !ft_strncmp(argv[1], "here_doc", 8))
			double_redirection(argc, argv, envp);
		else
			simple_redirection(argc, argv, envp);
	}
	else
	{
		printf("ERROR, number of arguments.\n");
		exit(1);
	}
	return (0);
}
