/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greita <greita@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 21:37:07 by greita            #+#    #+#             */
/*   Updated: 2022/02/27 10:05:08 by greita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_error(char *error_message)
{
	ft_putendl_fd(error_message, 2);
	exit(EXIT_FAILURE);
}

void	ft_close_pipeends(t_vars *vars)
{
	if (close(vars->pipe_end[1]) == -1)
	{
		perror("Error (wrong close pipe_end[1])");
		exit(EXIT_FAILURE);
	}
	if (close(vars->pipe_end[0]) == -1)
	{
		perror("Error (wrong close pipe_end[0])");
		exit(EXIT_FAILURE);
	}
}

void	ft_close_fds(t_vars *vars)
{
	ft_close_pipeends(vars);
	if (close(vars->fd_infile) == -1)
	{
		perror("Error (wrong close fd_infile)");
		exit(EXIT_FAILURE);
	}
	if (close(vars->fd_outfile) == -1)
	{
		perror("Error (wrong close fd_outfile");
		exit(EXIT_FAILURE);
	}
	if (vars->is_heredoc)
	{
		if (close(vars->fd_heredoc) == -1)
		{
			perror("Error (wrong close fd_heredoc");
			exit(EXIT_FAILURE);
		}
	}
}

void	ft_freearr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	ft_free_vars(t_vars *vars)
{
	ft_freearr(vars->argv_cmd1);
	ft_freearr(vars->argv_cmd2);
	ft_freearr(vars->envp_paths);
	free(vars->path_cmd1);
	free(vars->path_cmd2);
	if (vars->is_heredoc)
	{
		if (unlink("heredoc") == -1)
		{
			perror("Error (wrong unlink heredoc");
			exit(EXIT_FAILURE);
		}
	}
}
