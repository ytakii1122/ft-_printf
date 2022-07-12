/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytakii </var/mail/ytakii>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:06:07 by ytakii            #+#    #+#             */
/*   Updated: 2022/07/12 15:28:19 by ytakii           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include "libft.h"
# include <limits.h>

int		ft_printf(const char *fmt, ...);
char	*ft_itoa_u(unsigned int n);
int		put_d(va_list	ap);
int		put_c(va_list	ap);
int		put_u(va_list	ap);
int		put_s(va_list	ap);
int		put_x(char input, va_list	ap);
int		put_p(va_list	ap);
int		ft_decimal_change_x(unsigned int num, const char input);
int		ft_decimal_change_p(unsigned long long num);
int		ft_len(unsigned long long num);
int		print_int_u(char *n);
int		print_int_d(char *n);
#endif
