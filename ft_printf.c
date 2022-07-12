/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytakii </var/mail/ytakii>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:11:07 by ytakii            #+#    #+#             */
/*   Updated: 2022/07/12 15:26:06 by ytakii           ###   ########.fr       */
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
	int		return_len;
	int		ret;

	i = 0;
	return_len = 0;
	ret = 0;
	va_start(ap, fmt);
	while (fmt[i] != '\0')
	{
		if (fmt[i] == '%')
		{
			i++;
			ret = sign_behavior(fmt[i], ap);
			if (ret < 0 || return_len >= INT_MAX - ret)
				return (-1);
			return_len += ret;
		}
		else
			return_len += write(1, &fmt[i], 1);
		i++;
	}
	va_end(ap);
	return (return_len);
}
