/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 17:21:24 by abelqasm          #+#    #+#             */
/*   Updated: 2022/03/15 23:10:36 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "unistd.h"
# include "stdlib.h"
# include "stdio.h"
# include <fcntl.h>
# include "../get_next_line/get_next_line.h"

typedef struct s_heredoc
{
	pid_t	child1;
	pid_t	child2;
	int		file;
	int		tmp_file;
	char	*str;
	int		pipe[2];
	char	**paths;
	char	**cmd;
}	t_heredoc;

typedef struct s_pipex
{
	pid_t	*pids;
	int		file1;
	int		file2;
	int		cmd_nbr;
	int		**pipe;
	char	**paths;
	char	**cmd;
}	t_pipex;

int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_printf(const char *str, ...);
int		ft_strcmp(char *s1, char *s2);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_find_cmd(char **paths, char *cmd);
char	*ft_path(char	**env);
void	ft_error(void);
void	ft_argmt_error(void);
void	ft_infile_child(t_pipex *pipex, char **argv, char **env);
void	ft_outfile_child(t_pipex *pipex, char **argv, char **env);
void	ft_cmds_child(t_pipex *pipex, char *argv, char **env, int i);
void	ft_close_pipes(t_pipex *pipex);
void	ft_heredoc(int argc, char **argv, char **env);

#endif