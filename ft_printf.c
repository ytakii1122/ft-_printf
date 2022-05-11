/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytakii </var/mail/ytakii>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:11:07 by ytakii            #+#    #+#             */
/*   Updated: 2022/05/11 16:46:24 by ytakii           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include  <stdarg.h> 
/*
	//flags_check
	//width_check
	//precision_check
	//modifier_check
	//type_check
	//
	//
	//
	//char int -> ''> "" need to change
*/

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	//char	c;
	//size_t	i;
	int	return_size;

	//i = 0;
	va_start(ap, fmt);
	//while (fmt[i])
	//{
		//ft_putstr_fd((char*) fmt, 1);
		//c = (char)va_arg(ap, int);
		return_size = (int)va_arg(ap, int);
		//printf("%c",i);

		ft_putchar_fd(return_size, 1);
	//}
	va_end(ap);
	return (return_size);//word count include '\n'
}

int main (void)
{
	ft_printf("%hoge", '1');
	return (0);
}

int output_char(char *input , va_list arg)
{
	size_t	i;
	size_t	count

	i = 0;
	while (input[i] != '\0')
	{
	 	if (input[i] == '%')
			check(input, arg);//flag etc... check

		else
			ft_putchar_fd(input[i]);
		i++;
		count++;
	}
	return (count);// word count
}
