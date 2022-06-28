/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytakii </var/mail/ytakii>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:11:07 by ytakii            #+#    #+#             */
/*   Updated: 2022/06/28 12:50:04 by ytakii           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include  <stdarg.h> 

int sign_behavior(char input, va_list ap)
{
	size_t	len;//ssize_t??
	char	c;
	//c = '\0';
	char	*s;
	//s = NULL;
	int	d;

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
		ft_putstr_fd(s , 1);
		len = ft_strlen(s);
	}
	//else if (input == 'p')
	
	if (input == 'd' || input == 'i')
	{
		//int	d;
		d = (int)va_arg(ap, int);
		ft_putnbr_fd(d , 1);
		len++;
	}
	/*
	else if (input == 'u')
		//(int)va_arg(ap, unsigned int); 
	else if (input == 'x')
		//(int)va_arg(ap, int);
	else if (input == 'X')
		//(int)va_arg(ap, int);
	*/
	else if (input == '%')
	{
		ft_putchar_fd('%', 1);
		len++;
	}
	return(len);
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
	//type_ciheck
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
			return_len ++;
			return_len = sign_behavior(fmt[i], ap);//flag etc... check
			//return_len++;
			//printf("%d\n", return_len);
		}
		else
		{
			//ft_putchar_fd(fmt[i], '1');
			//return_len += 
			write (1, &fmt[i], 1);
			return_len++;
		}
		i++;
		//return_len++;
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
/*	int	a;
	a = ft_printf("hoge\n",1);
	printf("%d", a);
*/
	int	b;
	b = ft_printf("%c\n",'a');
	printf("%d\n", b);

	int	c;
	c  = printf("%c\n",'a');
	printf("%d\n", c);

	int	d;
	d  = printf("%s\n","abcdefg");
	printf("%d\n", d);
	
	int	e;
	e  = ft_printf("%s\n","abcdefg");
	printf("%d\n", e);

	int	f;
	f  = printf("%d\n", 1);
	printf("%d\n", f);

	int	g;
	g  = ft_printf("%d\n", 1);
	printf("%d\n", g);

	int k;
	k = printf("%%\n");
	printf("%d\n",k);

	int l;
	l = ft_printf("%%\n");
	printf("%d\n",l);

	return (0);

}

