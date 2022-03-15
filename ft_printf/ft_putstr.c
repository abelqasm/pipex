/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 15:27:38 by abelqasm          #+#    #+#             */
/*   Updated: 2022/01/04 22:41:43 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putstr_print(char *str)
{
	int		i;
	int		len;

	len = 0;
	i = 0;
	if (!str)
		str = "(null)";
	while (str[i])
	{
		len = len + ft_putchar(str[i]);
		i++;
	}
	return (len);
}

int	ft_putstr(va_list arg)
{
	return (ft_putstr_print(va_arg(arg, char *)));
}
