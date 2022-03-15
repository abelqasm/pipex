/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 14:25:26 by abelqasm          #+#    #+#             */
/*   Updated: 2022/01/04 23:53:14 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	print_whatever(va_list arg, char print)
{
	t_printing_functions	*printing;
	int						reslt;

	reslt = 0;
	printing = malloc(sizeof(printing) * 7);
	if (print == '%')
	{
		free(printing);
		return (ft_putchar('%'));
	}
	printing[0] = ft_putchar_print;
	printing[1] = ft_putnbr;
	printing[2] = ft_putstr;
	printing[3] = ft_print_hexa_low;
	printing[4] = ft_print_hexa_up;
	printing[5] = ft_putnbr_uns;
	printing[6] = ft_print_adress;
	reslt += printing[check_print(print)](arg);
	free (printing);
	return (reslt);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		reslt;

	reslt = 0;
	va_start(arg, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			reslt += print_whatever(arg, *str);
		}
		else
			reslt += ft_putchar(*str);
		str++;
	}
	va_end(arg);
	return (reslt);
}
