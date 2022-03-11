/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 22:01:06 by abelqasm          #+#    #+#             */
/*   Updated: 2022/03/11 22:37:04 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "unistd.h"
# include "stdlib.h"
# include "stdio.h"
# include <fcntl.h>

typedef struct s_pipex
{
	pid_t	child1;
	pid_t	child2;
	int		file1;
	int		file2;
	int		pipe[2];
	char	**path;
	char	**cmd;
}	t_pipex;
void	ft_error(void);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_infile_child(t_pipex *pipex, char **argv, char **env);
void	ft_outfile_child(t_pipex *pipex, char **argv, char **env);

#endif