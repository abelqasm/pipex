/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 15:27:31 by abelqasm          #+#    #+#             */
/*   Updated: 2022/01/04 22:41:38 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	calc_range(int nb)
{
	int				i;
	unsigned int	num;

	num = nb;
	i = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		i = 1;
		num = nb * -1;
	}
	while (num > 0 && ++i)
		num = num / 10;
	return (i);
}

static int	ft_putnbr_print(int nb)
{
	long long		nbr;
	int				len;

	len = calc_range(nb);
	nbr = nb;
	if (nb < 0)
	{
		ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr >= 0 && nbr <= 9)
		ft_putchar(nbr + '0');
	if (nbr > 9)
	{
		ft_putnbr_print(nbr / 10);
		ft_putnbr_print(nbr % 10);
	}
	return (len);
}

int	ft_putnbr(va_list arg)
{
	return (ft_putnbr_print(va_arg(arg, int)));
}
