/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytakii </var/mail/ytakii>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 17:22:07 by ytakii            #+#    #+#             */
/*   Updated: 2022/07/12 10:59:48 by ytakii           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_d(va_list ap)
{
	int		list_d;
	ssize_t		len;
	char	*change_char;

	len = 0;
	list_d = (int)va_arg(ap, int);
	change_char = ft_itoa(list_d);
	if (change_char == NULL)
		return (-1);
	len = print_int_d(change_char);
	free(change_char);
	return (len);
}

int	print_int_d(char *n)
{
	int	len;

	ft_putstr_fd(n, 1);
	len = ft_strlen(n);
	return (len);
}
