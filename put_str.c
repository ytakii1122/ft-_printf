/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytakii </var/mail/ytakii>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 23:47:15 by ytakii            #+#    #+#             */
/*   Updated: 2022/07/03 22:55:37 by ytakii           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_c(va_list	ap)
{
	size_t	len;
	char	list;

	len = 0;
	list = (char)va_arg(ap, int);
	ft_putchar_fd(list, 1);
	len++;
	return (len);
}

int	put_s(va_list	ap)
{
	size_t	len;
	char	*str;

	len = 0;
	str = (char *)va_arg(ap, char *);
	if (str == NULL)
	{
		write(1, "(null)", 6);
		len = 6;
	}
	else
	{
		ft_putstr_fd(str, 1);
		len = ft_strlen(str);
	}		
	return (len);
}
