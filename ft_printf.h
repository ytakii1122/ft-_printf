/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytakii </var/mail/ytakii>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:06:07 by ytakii            #+#    #+#             */
/*   Updated: 2022/07/02 23:37:01 by ytakii           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include "libft.h"

int		ft_printf(const char *fmt, ...);
char	*ft_itoa_u(unsigned int n);
int		put_unsigned_x(char input, va_list ap);
int		put_unsigned_p(char input, va_list ap);
int		ft_decimal_change_x(unsigned int num, const char input);
int		ft_decimal_change_p(unsigned long long num, const char input);
int		ft_len(unsigned long long num);
char	*ft_itoa_u(unsigned int n);
int		put_int(const char	input, va_list ap);

#endif
