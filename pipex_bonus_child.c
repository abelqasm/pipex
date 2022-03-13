/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus_child.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 17:34:43 by abelqasm          #+#    #+#             */
/*   Updated: 2022/03/13 03:10:49 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*ft_find_cmd(char **paths, char *cmd)
{
	char	*cmd_path;

	while (*paths)
	{
		cmd_path = ft_strjoin(*paths, cmd);
		if (access(cmd_path, F_OK) == 0)
			return (cmd_path);
		free(cmd_path);
		paths++;
	}
	return (NULL);
}

void	ft_infile_child(t_pipex *pipex, char **argv, char **env)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(argv[2], ' ');
	printf("inpute\n");
	path = ft_find_cmd(pipex->paths, cmd[0]);
	dup2(pipex->pipe[0][1], 1);
	close(pipex->pipe[0][0]);
	dup2(pipex->file1, 0);
	if (!path)
		ft_error();
	ft_close_pipes(pipex);
	execve(path, cmd, env);
	exit(1);
}

void	ft_cmds_child(t_pipex *pipex, char *argv, char **env, int i)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(argv, ' ');
	printf("cmd\n");
	path = ft_find_cmd(pipex->paths, cmd[0]);
	dup2(pipex->pipe[i - 1][0], 0);
	dup2(pipex->pipe[i][1], 1);
	if (!path)
		ft_error();
	ft_close_pipes(pipex);
	execve(path, cmd, env);
	exit(1);
}

void	ft_outfile_child(t_pipex *pipex, char **argv, char **env)
{
	char	**cmd;
	char	*path;

	printf("output\n");
	cmd = ft_split(argv[pipex->cmd_nbr + 1], ' ');
	path = ft_find_cmd(pipex->paths, cmd[0]);
	dup2(pipex->pipe[pipex->cmd_nbr - 2][0], 0);
	close(pipex->pipe[pipex->cmd_nbr - 2][1]);
	dup2(pipex->file2, 1);
	if (!path)
		ft_error();
	ft_close_pipes(pipex);
	execve(path, cmd, env);
	exit(1);
}
