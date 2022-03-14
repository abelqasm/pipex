/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:27:56 by abelqasm          #+#    #+#             */
/*   Updated: 2022/03/14 01:17:27 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../pipex_bonus.h"

char	*get_next_line(int fd);
int		ft_strlen(const char *str);
char	*ft_strjoin_line(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
int		ft_srch_n(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	len_sub(char const *s, unsigned int start, size_t lenght);

#endif