/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 22:48:12 by abelqasm          #+#    #+#             */
/*   Updated: 2022/03/15 23:14:22 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex.h"

void	ft_error(void)
{
	perror("Error");
	exit(1);
}

void	ft_argmt_error(void)
{
	write(1, "Wrong number of arguments\n", 26);
	exit(0);
}
