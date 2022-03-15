/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_adress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 15:26:55 by abelqasm          #+#    #+#             */
/*   Updated: 2022/01/04 22:41:22 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	calculate_the_range(unsigned long num)
{
	int				i;

	i = 0;
	if (num == 0)
		return (1);
	while (num > 0 && ++i)
		num = num / 16;
	return (i);
}

static int	ft_print_adress_print(unsigned long num)
{
	int				len;

	len = 0;
	len = len + calculate_the_range(num);
	if (num >= 16)
		ft_print_adress_print(num / 16);
	ft_putchar("0123456789abcdef"[num % 16]);
	return (len);
}

int	ft_print_adress(va_list arg)
{
	return (ft_putstr_print("0x")
		+ ft_print_adress_print(va_arg(arg, unsigned long)));
}
