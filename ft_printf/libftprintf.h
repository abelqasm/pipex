/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 15:27:53 by abelqasm          #+#    #+#             */
/*   Updated: 2022/01/04 23:14:03 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define    LIBFTPRINTF_H
# include  <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int	ft_putchar(char c);
int	ft_putstr_print(char *str);
int	ft_putchar_print(va_list arg);
int	ft_putnbr(va_list arg);
int	ft_putstr(va_list arg);
int	ft_printf(const char *str, ...);
int	ft_print_hexa_low(va_list arg);
int	ft_print_hexa_up(va_list arg);
int	ft_putnbr_uns(va_list arg);
int	ft_print_adress(va_list arg);
int	check_print(char print);
typedef int	(*t_printing_functions)(va_list arg);

#endif