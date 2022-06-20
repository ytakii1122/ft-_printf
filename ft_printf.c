/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytakii </var/mail/ytakii>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:11:07 by ytakii            #+#    #+#             */
/*   Updated: 2022/06/20 14:11:44 by ytakii           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include  <stdarg.h> 


int output_char(char input , va_list arg);
int check(char input, va_list arg)
{
	printf("check");
	return(2);
}
	//flags_check - or 0
	//width_check
		//size_t lengh = 0; 
		//lengh = ft_strlen(arg)
		//if(lengh  < // width)
			//putchar_fd(fd," ", width-lengh);
		//else
		//	nothing
	//precision_:wqicheck
	//modifier_check
	//type_check
	//
	//
	//
	//char int -> ''> "" need to change

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	size_t	i;
	int	return_len;

	i = 0;
	return_len = 0;
	if (fmt == NULL)
		return(-1);
	va_start(ap, fmt);
	//output_char(fmt, ap);
	while (fmt[i] != '\0')
	{
		if(fmt[i] == '%')
		{
			i++;
			check(fmt[i], ap);//flag etc... check
			return_len++;
		}
		else
			//ft_putchar_fd(fmt[i], '1');
			write (1, &fmt[i], 1);
		i++;
		return_len++;
	}
	va_end(ap);
	return (return_len);//word count include '\n'
}
/*
int output_char(char *input , va_list arg)
{
	size_t	i;
	size_t	count;

	i = 0;
	while (input[i] != '\0')
	{
	 	if (input[i] == '%')
		{
			i++;
			check(input[i], arg);//flag etc... check
		}
		else
			ft_putchar_fd(input[i], '1');
		i++;
		count++;
	}
	return (count);// word count
}

*/
int main (void)
{
	int	a;
	a = ft_printf("hoge\n");
	printf("%d", a);
	return (0);
}

