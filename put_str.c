/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytakii </var/mail/ytakii>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 23:47:15 by ytakii            #+#    #+#             */
/*   Updated: 2022/07/03 00:01:22 by ytakii           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
	
int	put_str(const char	input, va_list ap);
{
	size_t	len;
	char	list;
	char	*str

	len = 0;
	if (input == 'c')
	{
		list = (char)va_arg(ap, int);
		ft_putchar_fd(list, 1);
		len++;
	}
	else if (input == 's')
	{
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
	}
	return (len);
}
