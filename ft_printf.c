/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytakii </var/mail/ytakii>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:11:07 by ytakii            #+#    #+#             */
/*   Updated: 2022/04/21 22:47:53 by ytakii           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include  <stdarg.h> 
/*
	//flags_check
	//width_check
	//precision_check
	//modifier_check
	//type_check
	//
	//
	//
	//char int -> ''> "" need to change
*/

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	//char	c;
	int	i;

	va_start(ap, fmt);
	ft_putstr_fd((char*) fmt, 1);
	//c = (char)va_arg(ap, int);
	i = (int)va_arg(ap, int);
	//printf("%c",i);
	ft_putchar_fd(i, 1);
	va_end(ap);
	return (0);
}

int main (void)
{
	ft_printf("hoge", '1');
	return (0);
}

