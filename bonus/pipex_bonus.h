/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greita <greita@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 21:39:51 by greita            #+#    #+#             */
/*   Updated: 2022/02/27 20:18:11 by greita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <sys/wait.h>
# include <stdio.h>
# include <stdbool.h>

typedef struct s_vars
{
	pid_t	pid_inchild;
	pid_t	pid_outchild;
	int		argc;
	int		fd_infile;
	int		fd_outfile;
	int		fd_heredoc;
	int		pipe_end[2];
	int		is_heredoc;
	int		islong_pathcmd1;
	int		islong_pathcmd2;
	int		is_wrongcmd1;
	char	**argv;
	char	**envp;
	char	**argv_cmd1;
	char	**argv_cmd2;
	char	**envp_paths;
	char	*path_cmd1;
	char	*path_cmd2;
}	t_vars;

/*pipex_bonus.c*/
void	ft_create_heredoc(t_vars *vars);
/*init_bonus.c*/
void	ft_check_emptycmds(t_vars *vars);
void	ft_getenvp_paths(t_vars *vars);
char	*ft_getcmd_path(t_vars *vars, char **envp_paths, char *cmd);
char	*ft_getcmd_longpath(t_vars *vars, char *cmd);
/*init2_bonus.c*/
void	ft_initvars(t_vars *vars, int argc, char **argv, char **envp);
/*close_bonus.c*/
void	ft_error(char *error_message);
void	ft_close_fds(t_vars *vars);
void	ft_free_vars(t_vars *vars);
/*cmds_bonus.c*/
void	ft_open_files(t_vars *vars);
void	ft_create_pipes(t_vars *vars);
void	ft_create_child(pid_t *child_pid);
void	ft_exec_cmdfirst(t_vars *vars);
void	ft_exec_cmdlast(t_vars *vars);

#endif
