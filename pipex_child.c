/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_child.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 22:11:32 by abelqasm          #+#    #+#             */
/*   Updated: 2022/03/11 22:49:43 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_get_cmd(char **cmd_path)
{
	
}

void	ft_infile_child(t_pipex *pipex, char **argv, char **env)
{
	dup2(pipex->pipe[1], 1);
	close(pipex->pipe[0]);
	
}

void	ft_outfile_child(t_pipex *pipex, char **argv, char **env)
{
	dup2(pipex->pipe[0], 0);
	close(pipex->pipe[1]);
}