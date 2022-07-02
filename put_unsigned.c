/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_unsigned.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytakii </var/mail/ytakii>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 20:45:51 by ytakii            #+#    #+#             */
/*   Updated: 2022/07/02 23:31:27 by ytakii           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_unsigned_p(const char input, va_list ap)
{
	size_t				len;
	unsigned long long	list;

	len = 0;
	if (input == 'p')
	{
		write(1, "0x", 2);
		len = 2;
	}
	list = (unsigned long long)va_arg(ap, unsigned long long);
	ft_decimal_change_p(list, input);
	len += ft_len(list);
	return (len);
}

int	put_unsigned_x(const char input, va_list ap)
{
	size_t			len;
	unsigned int	list;

	len = 0;
	list = (unsigned int)va_arg(ap, unsigned int);
	ft_decimal_change_x(list, input);
	len += ft_len(list);
	return (len);
}

int	ft_decimal_change_x(unsigned int	num, const char	input)
{
	if (num >= 16)
	{
		ft_decimal_change_x(num / 16, input);
		ft_decimal_change_x(num % 16, input);
	}
	else
	{
		if (num < 10)
			ft_putchar_fd(num + '0', 1);
		else
		{
			if (input == 'X')
				ft_putchar_fd(num - 10 + 'A', 1);
			else
				ft_putchar_fd(num - 10 + 'a', 1);
		}
	}
	return (0);
}

int	ft_decimal_change_p(unsigned long long num, const char input)
{
	if (num >= 16)
	{
		ft_decimal_change_p(num / 16, input);
		ft_decimal_change_p(num % 16, input);
	}
	else
	{
		if (num < 10)
			ft_putchar_fd(num + '0', 1);
		else
			ft_putchar_fd(num - 10 + 'a', 1);
	}
	return (0);
}

int	ft_len(unsigned long long num)
{
	size_t	count;

	count = 0;
	if (num == 0)
		count++;
	while (num != 0)
	{
		count++;
		num = num / 16;
	}
	return (count);
}