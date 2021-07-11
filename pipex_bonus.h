#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

// A typedef's name must start by:	 t_
// A structure's name must start by:	 s_
// A enum's name must start by:		 e_
// A union's name must start by:	 u_
// A global's name must start by:	 g_

# include "libft/libft.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h> 

typedef struct s_cmd
{
	char			**path;	
	char			*command;
	char			**args;
	struct s_cmd	*next;
	struct s_cmd	*previous;
}					t_cmd;

typedef struct s_cmd_line
{
	char		*file_input;
	char		*file_output;
	int			nbr_of_cmds;
	t_cmd		*s_cmd;
}				t_cmd_line;

int		get_next_line(int fd, char **line);
void	copy_and_past(char **p, char *s);
int		ft_new_line(int red, char **p, char **line);
int		free_ptr(char **p);

t_cmd	*lst_new_cmd(char *argv, char **path);
void	lst_add_back_cmds(t_cmd_line *s_cmd_line, int indice, t_cmd *s_cmd);
void	lst_add_front_cmd(t_cmd_line *s_cmd_line, t_cmd *s_first_cmd);
t_cmd	*lst_last_cmd(t_cmd_line *s_cmd_line);
void	lst_clear_cmds(t_cmd_line *s_cmd_line);

void	simple_redirection(int argc, char **argv, char **envp);
void	double_redirection(int argc, char **argv, char **envp);
char	**get_env_var_path(char **envp);
char	*check_for_the_right_path(char **env_path, char *cmd);
void	free_double_table(char **str);

void	fill_linked_list_of_cmds(t_cmd_line *s_cmd_line,
			char **argv, char **envp);
int		get_fd_input(int redirection, char *file_input);
void	read_from_terminal(int fd_input, char *limiter);
int		get_fd_output(int redirection, char *file_output);
void	error_file(int fd, char *file);
void	error_pipe(int pipe_fd);
void	error_fork(int pid);

void	execution_part(int redirection, t_cmd_line *s_cmd_line);
int		launching_child_processes(int type_redirection, t_cmd_line *s_cmd_line);
void	waiting_for_processes(int nbr_of_cmds, int pid_last_cmd);
int		first_cmd(int redirection, char *file_input, t_cmd *s_cmd);
int		second_cmd(int fd_input, t_cmd *s_cmd);
int		last_cmd(int redirection, int fd_input,
			t_cmd *s_cmd, char *file_output);

#endif
