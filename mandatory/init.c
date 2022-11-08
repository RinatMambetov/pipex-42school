/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greita <greita@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 21:37:24 by greita            #+#    #+#             */
/*   Updated: 2022/02/27 18:26:35 by greita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_getcmd_longpath(t_vars *vars, char *cmd)
{
	if (!access(cmd, F_OK | R_OK | X_OK))
		return (ft_strdup(cmd));
	else
	{
		perror("Error (wrong access to long path cmd)");
		vars->is_wrongcmd1 = 1;
		return (ft_strdup(""));
	}
}

char	*ft_getcmd_path(t_vars *vars, char **envp_paths, char *cmd)
{
	int		i;
	char	*cmd_path;

	i = 0;
	while (envp_paths[i])
	{
		cmd_path = ft_strjoin(envp_paths[i], cmd);
		if (!cmd_path)
			ft_error("Error: wrong join cmd_path");
		if (!access(cmd_path, F_OK | R_OK | X_OK))
			break ;
		free(cmd_path);
		i++;
	}
	if (!envp_paths[i])
	{
		perror("Error (wrong access to cmd)");
		vars->is_wrongcmd1 = 1;
		return (ft_strdup(""));
	}
	return (cmd_path);
}

void	ft_split_envppath(t_vars *vars)
{
	int	i;

	i = 0;
	while (vars->envp[i])
	{
		if (!ft_strncmp(vars->envp[i], "PATH", 4))
			break ;
		i++;
	}
	vars->envp_paths = ft_split(vars->envp[i], ':');
	if (!vars->envp_paths)
		ft_error("Error: wrong split envp_paths");
}

void	ft_getenvp_paths(t_vars *vars)
{
	int		i;
	char	*temp;

	i = 0;
	ft_split_envppath(vars);
	while (vars->envp_paths[i])
	{
		temp = vars->envp_paths[i];
		vars->envp_paths[i] = ft_strjoin(temp, "/");
		if (!vars->envp_paths[i])
			ft_error("Error: wrong join envp_path");
		free(temp);
		i++;
	}
	vars->envp_paths[0] = ft_memmove(vars->envp_paths[0],
			vars->envp_paths[0] + 5, ft_strlen(vars->envp_paths[0]) - 4);
}

void	ft_check_emptycmds(t_vars *vars)
{
	int	i;
	int	j;
	int	len;

	i = 2;
	while (i < vars->argc - 1)
	{
		j = 0;
		len = ft_strlen(vars->argv[i]);
		while (j < len)
		{
			if (vars->argv[i][j] == ' ')
				j++;
			else
				len--;
		}
		if (!vars->argv[i][j])
			ft_error("Error: there is empty cmd");
		i++;
	}
}
