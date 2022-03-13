/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 17:21:33 by abelqasm          #+#    #+#             */
/*   Updated: 2022/03/13 03:02:28 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*ft_path(char	**env)
{
	while (ft_strncmp("PATH", *env, 4))
		env++;
	return (*env + 5);
}

void	ft_pipex_bonus(t_pipex *pipex, char **argv, char **env)
{
	int	i;

	i = 0;
	pipex->pids = malloc(sizeof(int) * pipex->cmd_nbr);
	while (i < pipex->cmd_nbr)
	{
		pipex->pids[i] = fork();
		if (pipex->pids[i] == -1)
			ft_error();
		if (pipex->pids[i] == 0)
		{
			if (i == 0)
				ft_infile_child(pipex, argv, env);
			else if (i == pipex->cmd_nbr - 1)
				ft_outfile_child(pipex, argv, env);
			else
				ft_cmds_child(pipex, argv[i + 2], env, i);
		}
		i++;
	}
	i = -1;
	while (++i < pipex->cmd_nbr)
		waitpid(pipex->pids[i], NULL, 0);
}

int	main(int argc, char **argv, char **env)
{
	t_pipex	pipex;
	int		i;

	i = 0;
	pipex.cmd_nbr = argc - 3;
	pipex.pipe = malloc(sizeof(int *) * (pipex.cmd_nbr - 1));
	while (i < pipex.cmd_nbr - 1)
	{
		pipex.pipe[i] = malloc(sizeof(int) * 2);
		if (pipe(pipex.pipe[i]) == -1)
			ft_error();
		i++;
	}
	pipex.file1 = open(argv[1], O_RDONLY);
	pipex.file2 = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (pipex.file1 == -1 || pipex.file2 == -1)
		ft_error();
	pipex.paths = ft_split(ft_path(env), ':');
	ft_pipex_bonus(&pipex, argv, env);
	return (0);
}
