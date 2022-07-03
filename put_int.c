/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytakii </var/mail/ytakii>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 21:06:50 by ytakii            #+#    #+#             */
/*   Updated: 2022/07/03 23:06:55 by ytakii           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_int(const char	input, va_list ap)
{
	int				list_d;
	unsigned int	list_u;
	int				len;
	char			*change_char;

	len = 0;
	if (input == 'd' || input == 'i')
	{
		list_d = (int)va_arg(ap, int);
		change_char = ft_itoa(list_d);
	}
	if (input == 'u')
	{
		list_u = (unsigned int)va_arg(ap, unsigned int);
		change_char = ft_itoa_u(list_u);
	}
	ft_putstr_fd(change_char, 1);
	len = ft_strlen(change_char);
	free(change_char);
	return (len);
}
