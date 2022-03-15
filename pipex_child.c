/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_child.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 22:11:32 by abelqasm          #+#    #+#             */
/*   Updated: 2022/03/15 22:28:59 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_find_cmd(char **paths, char *cmd)
{
	char	*cmd_path;

	while (paths && *paths)
	{
		cmd_path = ft_strjoin(*paths, cmd);
		if (access(cmd_path, F_OK) == 0)
			return (cmd_path);
		free(cmd_path);
		paths++;
	}
	ft_printf("command not found: %s\n", cmd);
	exit(1);
	return (NULL);
}

void	ft_infile_child(t_pipex *pipex, char **argv, char **env)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(argv[2], ' ');
	path = ft_find_cmd(pipex->paths, cmd[0]);
	dup2(pipex->pipe[1], 1);
	close(pipex->pipe[0]);
	dup2(pipex->file1, 0);
	if (!path)
		ft_error();
	execve(path, cmd, env);
	exit(1);
}

void	ft_outfile_child(t_pipex *pipex, char **argv, char **env)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(argv[3], ' ');
	path = ft_find_cmd(pipex->paths, cmd[0]);
	dup2(pipex->pipe[0], 0);
	close(pipex->pipe[1]);
	dup2(pipex->file2, 1);
	if (!path)
		ft_error();
	execve(path, cmd, env);
	exit(1);
}
