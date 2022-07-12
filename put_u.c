/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_u.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytakii </var/mail/ytakii>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 17:22:36 by ytakii            #+#    #+#             */
/*   Updated: 2022/07/12 15:48:52 by ytakii           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_u(va_list ap)
{
	unsigned int	list_u;
	size_t				len;
	char			*change_char;

	len = 0;
	list_u = (unsigned int)va_arg(ap, unsigned int);
	change_char = ft_itoa_u(list_u);
	if (change_char == NULL)
		return (-1);
	len = print_int_u(change_char);
	free(change_char);
	return (len);
}

int	print_int_u(char *n)
{	
	size_t	len;

	ft_putstr_fd(n, 1);
	len = ft_strlen(n);
	return (len);
}
