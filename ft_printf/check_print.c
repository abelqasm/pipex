/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 18:32:01 by abelqasm          #+#    #+#             */
/*   Updated: 2022/01/04 22:40:37 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	check_print(char print)
{
	if (print == 'c')
		return (0);
	if (print == 'i' || print == 'd')
		return (1);
	if (print == 's')
		return (2);
	if (print == 'x')
		return (3);
	if (print == 'X')
		return (4);
	if (print == 'u')
		return (5);
	if (print == 'p')
		return (6);
	return (0);
}
