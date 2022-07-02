/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytakii </var/mail/ytakii>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:11:07 by ytakii            #+#    #+#             */
/*   Updated: 2022/07/02 23:29:08 by ytakii           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	sign_behavior(char	input, va_list	ap)
{
	size_t	len;//ssize_t??
	char	c;
	char	*s;

	len = 0;
	if (input == 'c')
	{
		//char	c;
		c = (char)va_arg(ap, int);
		ft_putchar_fd(c, 1);
		len++;
	}
	else if (input == 's')
	{
		//char	*s;
		s = (char *)va_arg(ap, char *);
		if (s == NULL)
		{
			write(1, "(null)", 6);
			len = 6;
		}
		else
		{
			ft_putstr_fd(s, 1);
			len = ft_strlen(s);
		}		
	}
	else if (input == 'p')
		len = put_unsigned_p(input, ap);
	else if (input == 'd' || input == 'i')
		len = put_int(input, ap);
	else if (input == 'u')
		len = put_int(input, ap);
	else if (input == 'x' || input == 'X')
		len = put_unsigned_x(input, ap);
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
			write (1, &fmt[i], 1);
			return_len++;
		}
		i++;
	}
	va_end(ap);
	return (return_len);//word count include '\n'
}
