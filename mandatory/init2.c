/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greita <greita@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 09:38:13 by greita            #+#    #+#             */
/*   Updated: 2022/02/27 18:27:51 by greita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_trimcmd(char *argv_cmd)
{
	int	len;

	len = ft_strlen(argv_cmd) - ft_strlen(ft_strrchr(argv_cmd, '/') - 1);
	argv_cmd = ft_memmove(argv_cmd, ft_strrchr(argv_cmd, '/') + 1, len + 1);
	return (argv_cmd);
}

void	ft_check_pathcmds(t_vars *vars)
{
	vars->islong_pathcmd1 = 0;
	vars->islong_pathcmd2 = 0;
	if (vars->argv_cmd1[0][0] == '.' || vars->argv_cmd1[0][0] == '/')
		vars->islong_pathcmd1 = 1;
	if (vars->argv_cmd2[0][0] == '.' || vars->argv_cmd2[0][0] == '/')
		vars->islong_pathcmd2 = 1;
}

void	ft_choice_pathcmd(t_vars *vars)
{
	vars->is_wrongcmd1 = 0;
	if (vars->islong_pathcmd1)
	{
		vars->path_cmd1 = ft_getcmd_longpath(vars, vars->argv_cmd1[0]);
		vars->argv_cmd1[0] = ft_trimcmd(vars->argv_cmd1[0]);
	}
	else
		vars->path_cmd1 = ft_getcmd_path(vars, vars->envp_paths,
				vars->argv_cmd1[0]);
	if (vars->islong_pathcmd2)
	{
		vars->path_cmd2 = ft_getcmd_longpath(vars, vars->argv_cmd2[0]);
		vars->argv_cmd2[0] = ft_trimcmd(vars->argv_cmd2[0]);
	}
	else
		vars->path_cmd2 = ft_getcmd_path(vars, vars->envp_paths,
				vars->argv_cmd2[0]);
}

void	ft_initvars(t_vars *vars, int argc, char **argv, char **envp)
{
	vars->argc = argc;
	vars->argv = argv;
	vars->envp = envp;
	ft_check_emptycmds(vars);
	vars->argv_cmd1 = ft_split(vars->argv[2], ' ');
	vars->argv_cmd2 = ft_split(vars->argv[3], ' ');
	if (!vars->argv_cmd1 || !vars->argv_cmd2)
		ft_error("Error: wrong split argv_cmd");
	ft_check_pathcmds(vars);
	ft_getenvp_paths(vars);
	ft_choice_pathcmd(vars);
}
