/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greita <greita@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 21:36:50 by greita            #+#    #+#             */
/*   Updated: 2022/02/27 20:17:09 by greita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_create_heredoc(t_vars *vars)
{
	char	*line;

	vars->fd_heredoc = open("heredoc", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (vars->fd_heredoc == -1)
	{
		perror("Error (wrong create heredoc)");
		exit(EXIT_FAILURE);
	}
	while (true)
	{
		ft_putstr_fd("pipe heredoc> ", 1);
		line = ft_get_nextline(STDIN_FILENO);
		if (!line)
			ft_error("Error: wrong get next line");
		if (line[ft_strlen(vars->argv[2]) + 1] == '\0'
			&& !ft_strncmp(line, vars->argv[2], ft_strlen(vars->argv[2])))
			break ;
		if (write(vars->fd_heredoc, line, ft_strlen(line)) == -1)
		{
			perror("Error (wrong write heredoc)");
			exit(EXIT_FAILURE);
		}
		free(line);
	}
	free(line);
}

int	main(int argc, char **argv, char **envp)
{
	t_vars	vars;

	if (argc != 5 && argc != 6)
		ft_error("Error: wrong amount of arguments");
	ft_initvars(&vars, argc, argv, envp);
	ft_create_pipes(&vars);
	if (!vars.is_wrongcmd1)
	{
		ft_create_child(&vars.pid_inchild);
		if (vars.pid_inchild == 0)
			ft_exec_cmdfirst(&vars);
	}
	ft_create_child(&vars.pid_outchild);
	if (vars.pid_outchild == 0)
		ft_exec_cmdlast(&vars);
	ft_close_fds(&vars);
	ft_free_vars(&vars);
	waitpid(vars.pid_inchild, NULL, 0);
	waitpid(vars.pid_outchild, NULL, 0);
	return (0);
}
