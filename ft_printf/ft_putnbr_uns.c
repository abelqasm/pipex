/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_uns.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 15:27:25 by abelqasm          #+#    #+#             */
/*   Updated: 2022/01/04 21:58:40 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	calc_range_uns(unsigned long num)
{
	int				i;

	i = 0;
	if (num == 0)
		return (1);
	while (num > 0 && ++i)
		num = num / 10;
	return (i);
}

static int	ft_putnbr_uns_print(unsigned int nbr)
{
	int				len;

	len = calc_range_uns(nbr);
	if (nbr >= 0 && nbr <= 9)
		ft_putchar(nbr + '0');
	if (nbr > 9)
	{
		ft_putnbr_uns_print(nbr / 10);
		ft_putnbr_uns_print(nbr % 10);
	}
	return (len);
}

int	ft_putnbr_uns(va_list arg)
{
	return (ft_putnbr_uns_print(va_arg(arg, unsigned int)));
}
