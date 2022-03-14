/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 22:00:56 by abelqasm          #+#    #+#             */
/*   Updated: 2022/03/14 16:08:46 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_path(char	**env)
{
	while (*env && ft_strncmp("PATH", *env, 4))
		env++;
	if (!*env)
		return (NULL);
	return (*env + 5);
}

void	ft_pipex(t_pipex *pipex, char **argv, char **env)
{
	pipex->child1 = fork();
	if (pipex->child1 == -1)
		ft_error();
	if (pipex->child1 == 0)
		ft_infile_child(pipex, argv, env);
	pipex->child2 = fork();
	if (pipex->child2 == -1)
		ft_error();
	if (pipex->child2 == 0)
		ft_outfile_child(pipex, argv, env);
	close(pipex->pipe[1]);
	close(pipex->pipe[0]);
	waitpid(pipex->child1, NULL, 0);
	waitpid(pipex->child2, NULL, 0);
}

int	main(int argc, char **argv, char **env)
{
	t_pipex	pipex;

	if (argc != 5)
		ft_argmt_error();
	pipex.file1 = open(argv[1], O_RDONLY);
	pipex.file2 = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (pipex.file1 == -1 || pipex.file2 == -1)
		ft_error();
	if (pipe(pipex.pipe) == -1)
		ft_error();
	if (ft_path(env) != NULL)
		pipex.paths = ft_split(ft_path(env), ':');
	ft_pipex(&pipex, argv, env);
	return (0);
}
