/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytakii </var/mail/ytakii>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:11:07 by ytakii            #+#    #+#             */
/*   Updated: 2022/04/21 21:33:10 by ytakii           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>
/*
	//flags_check
	//width_check
	//precision_check
	//modifier_check
	//type_check
*/

int	ft_printf(const char *fmt, ...);
int main (void)
{
	ft_printf("hoge", 'a');
	return (0);
}


int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	char	c;
	int	i;

	va_start(ap, fmt);
	printf("%s\n",fmt);
	c = (char )va_arg(ap, int);
	//i = (int)va_arg(ap, int);
	printf("%c\n", c);
	va_end(ap);
	return (0);
}
