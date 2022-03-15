/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa_low.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 15:27:06 by abelqasm          #+#    #+#             */
/*   Updated: 2022/01/04 21:59:07 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	calculate_the_range(int nb)
{
	int				i;
	unsigned int	num;

	num = nb;
	i = 0;
	if (nb == 0)
		return (1);
	while (num > 0 && ++i)
		num = num / 16;
	return (i);
}

static int	ft_print_hexa_low_print(int nb)
{
	unsigned int	num;
	int				len;

	num = nb;
	len = calculate_the_range(nb);
	if (num >= 16)
		ft_print_hexa_low_print(num / 16);
	ft_putchar("0123456789abcdef"[num % 16]);
	return (len);
}

int	ft_print_hexa_low(va_list arg)
{
	return (ft_print_hexa_low_print(va_arg(arg, int)));
}
