/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greita <greita@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 21:36:50 by greita            #+#    #+#             */
/*   Updated: 2022/02/27 18:22:13 by greita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_vars	vars;

	if (argc != 5)
		ft_error("Error: wrong amount of arguments");
	ft_open_files(&vars);
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
