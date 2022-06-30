/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytakii </var/mail/ytakii>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:06:07 by ytakii            #+#    #+#             */
/*   Updated: 2022/06/30 21:57:30 by ytakii           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
//#include <assert.h>
# include "libft.h"


int	ft_printf(const char *fmt, ...);
char	*ft_itoa_u(unsigned int n);
int	put_unsigned(char input, va_list ap);
int ft_decimal_change(unsigned long long num, const char input);
int ft_len(unsigned long long num);

#endif
