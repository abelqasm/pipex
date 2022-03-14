/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 22:01:06 by abelqasm          #+#    #+#             */
/*   Updated: 2022/03/14 15:35:07 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "unistd.h"
# include "stdlib.h"
# include "stdio.h"
# include <string.h>
# include <errno.h>
# include <fcntl.h>

typedef struct s_pipex
{
	pid_t	child1;
	pid_t	child2;
	int		file1;
	int		file2;
	int		pipe[2];
	char	**paths;
	char	**cmd;
}	t_pipex;

int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char *s1, char *s2);
void	ft_error(void);
void	ft_argmt_error(void);
void	ft_infile_child(t_pipex *pipex, char **argv, char **env);
void	ft_outfile_child(t_pipex *pipex, char **argv, char **env);

#endif