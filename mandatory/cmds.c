/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greita <greita@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 21:36:57 by greita            #+#    #+#             */
/*   Updated: 2022/02/27 18:21:45 by greita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_open_files(t_vars *vars)
{
	vars->fd_infile = open(vars->argv[1], O_RDONLY);
	if (vars->fd_infile == -1)
	{
		perror("Error (wrong input file)");
		exit(EXIT_FAILURE);
	}
	vars->fd_outfile = open(vars->argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (vars->fd_outfile == -1)
	{
		perror("Error (wrong output file)");
		exit(EXIT_FAILURE);
	}
}

void	ft_create_pipes(t_vars *vars)
{
	if (pipe(vars->pipe_end) == -1)
	{
		perror("Error (wrong pipe)");
		exit(EXIT_FAILURE);
	}
}

void	ft_create_child(pid_t *child_pid)
{
	*child_pid = fork();
	if (*child_pid == -1)
	{
		perror("Error (wrong child pid)");
		exit(EXIT_FAILURE);
	}
}

void	ft_exec_cmdfirst(t_vars *vars)
{
	if (dup2(vars->fd_infile, STDIN_FILENO) == -1)
	{
		perror("Error (wrong dup to fd_infile)");
		exit(EXIT_FAILURE);
	}
	if (dup2(vars->pipe_end[1], STDOUT_FILENO) == -1)
	{
		perror("Error (wrong dup to pipe_end[1])");
		exit(EXIT_FAILURE);
	}
	if (close(vars->pipe_end[0]) == -1)
	{
		perror("Error (wrong close pipe_end[0])");
		exit(EXIT_FAILURE);
	}
	if (execve(vars->path_cmd1, vars->argv_cmd1, NULL) == -1)
	{
		perror("Error (wrong exec cmdfirst)");
		exit(EXIT_FAILURE);
	}
}

void	ft_exec_cmdlast(t_vars *vars)
{
	if (dup2(vars->pipe_end[0], STDIN_FILENO) == -1)
	{
		perror("Error (wrong dup to pipe_end[0])");
		exit(EXIT_FAILURE);
	}
	if (dup2(vars->fd_outfile, STDOUT_FILENO) == -1)
	{
		perror("Error (wrong dup to fd_outfile)");
		exit(EXIT_FAILURE);
	}
	if (close(vars->pipe_end[1]) == -1)
	{
		perror("Error (wrong close pipe_end[1])");
		exit(EXIT_FAILURE);
	}
	if (execve(vars->path_cmd2, vars->argv_cmd2, NULL) == -1)
	{
		perror("Error (wrong exec cmdlast)");
		exit(EXIT_FAILURE);
	}
}
