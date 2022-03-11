/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 22:00:56 by abelqasm          #+#    #+#             */
/*   Updated: 2022/03/11 22:37:26 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_path(char	**env)
{
	while (ft_strncmp("PATH", *env, 4))
		env++;
	return (*env + 5);
}

int	main(int argc, char **argv, char **env)
{
	t_pipex	pipex;

	pipex.file1 = open(argv[1], O_RDONLY);
	pipex.file2 = open(argv[argc - 1], O_RDWR | O_CREAT);
	if (pipex.file1 == -1 || pipex.file2 == -1)
		ft_error();
	if (pipe(pipex.pipe) == -1)
		ft_error();
	pipex.path = ft_path(env);
	pipex.child1 = fork();
	if (pipex.child1 == 0)
		ft_infile_child(&pipex, argv, env);
	pipex.child2 = fork();
	if (pipex.child2 == 0)
		ft_outfile_child(&pipex, argv, env);
	return (0);
}
