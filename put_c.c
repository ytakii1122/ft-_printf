/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytakii </var/mail/ytakii>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 22:15:52 by ytakii            #+#    #+#             */
/*   Updated: 2022/07/05 22:22:38 by ytakii           ###   ########.fr       */
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
