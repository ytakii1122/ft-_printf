/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytakii </var/mail/ytakii>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:11:07 by ytakii            #+#    #+#             */
/*   Updated: 2022/07/05 23:03:46 by ytakii           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	sign_behavior(char	input, va_list	ap)
{
	size_t	len;

	len = 0;
	if (input == 'c')
		len = put_c(ap);
	else if (input == 's')
		len = put_s(ap);
	else if (input == 'p')
		len = put_p(ap);
	else if (input == 'd' || input == 'i')
		len = put_d(ap);
	else if (input == 'u')
		len = put_u(ap);
	else if (input == 'x' || input == 'X')
		len = put_x(input, ap);
	else if (input == '%')
	{
		ft_putchar_fd('%', 1);
		len++;
	}
	return (len);
}

int	ft_printf(const char	*fmt, ...)
{
	va_list	ap;
	size_t	i;
	size_t	return_len;

	i = 0;
	return_len = 0;
	if (fmt == NULL)
		return (-1);
	va_start(ap, fmt);
	while (fmt[i] != '\0')
	{
		if (fmt[i] == '%')
		{
			i++;
			return_len += sign_behavior(fmt[i], ap);
		}
		else
		{
			ft_putchar_fd(fmt[i], 1);
			return_len++;
		}
		i++;
	}
	va_end(ap);
	return (return_len);
}
