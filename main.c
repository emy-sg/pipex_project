/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isghioua <isghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 19:36:57 by isghioua          #+#    #+#             */
/*   Updated: 2021/07/10 19:36:58 by isghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	if (argc == 5)
		simple_redirection(argc, argv, envp);
	else
	{
		printf("ERROR, number of arguments.\n");
		exit(1);
	}
	return (0);
}
