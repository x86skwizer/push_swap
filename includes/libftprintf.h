/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamrire <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 14:03:27 by yamrire           #+#    #+#             */
/*   Updated: 2022/09/09 03:10:30 by yamrire          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "./../push_swap.h"

int		ft_putchar(char c);
int		ft_putnbr(long n, int *len);
int		ft_putstr(char *s);
int		ft_printf(const char *str, ...);
int		ft_nbr_base(unsigned long long n, int base, int which, int *len);
int		ft_atoi(const char *str);
char	*ft_strchr(const char *str, int c);
size_t	ft_strlen(const char *str);
void	ft_exit(char *str);

#endif
