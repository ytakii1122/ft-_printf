/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytakii </var/mail/ytakii>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:11:07 by ytakii            #+#    #+#             */
/*   Updated: 2022/06/30 16:03:42 by ytakii           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include  <stdarg.h> 

int ft_x(unsigned int num, const char input);//have to check return value
int ft_p(unsigned long long num);
int ft_len(unsigned num);

int sign_behavior(char input, va_list ap)
{
	size_t	len;//ssize_t??
	char	c;
	//c = '\0';
	char	*s;
	//s = NULL;
	int	d;
	unsigned int	u;//unsigned long long
	char	*str;
	unsigned int	p;
	unsigned int	x;
	char	*str_d;

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
			write(1,"(null)",6);
			len = 6;
		}
		else
		{
			ft_putstr_fd(s , 1);
			len = ft_strlen(s);
		}
		
	}
	else if (input == 'p')
	{
		write(1,"0x",2);
		len = 2;
		p = (int)va_arg(ap, unsigned int);
		len += ft_p(p);
	}
	else if (input == 'd' || input == 'i')
	{
		//int	d;
		//char	*str_d;
		d = (int)va_arg(ap, int);
		str_d = ft_itoa(d);
		ft_putstr_fd(str_d, 1);
		len = ft_strlen(str_d);
		free(str_d);
		//ft_putnbr_fd(d , 1);
	}
	
	else if (input == 'u')
	{
	//	unsigned int	u;//unsigned long long
	//	char	*str;

		u =	(int)va_arg(ap, unsigned int);
		str = ft_itoa(u);
		ft_putstr_fd(str, 1);
		len = ft_strlen(str);
		free(str);
	}
	else if (input == 'x' || input == 'X')
	{
		//unsigned int	x;	
		x = (int)va_arg(ap, unsigned int);
		ft_x(x, input);
		len = ft_len(x);
	}
	else if (input == '%')
	{
		ft_putchar_fd('%', 1);
		len++;
	}
	return(len);
}


int ft_x(unsigned int num, const char input)
{
	int len;

	len = 0;
	if (num >= 16)
	{
		ft_x(num / 16, input);
		ft_x(num % 16, input);
	}
	else
	{
		if(num < 10)
		{
			ft_putchar_fd(num + '0', 1);
			len++;
			//printf("1:%d\n",len);
		}
		else //11-15
		{
			if ( input == 'X')
			{
				ft_putchar_fd(num -10 + 'A', 1);
				len++;
				//printf("2:%d\n",len);
			}
			else
			{
				ft_putchar_fd(num -10 + 'a', 1);
				len++;
				//printf("3: %d\n",len);
			}
		}
	}
	//printf("4:%d\n",len);
	return (len);
}

int ft_p(unsigned long long num)
{
	int len;

	len = 0;
	if (num >= 16)
	{
		ft_p(num / 16);
		ft_p(num % 16);
	}
	else
	{
		if(num < 10)
			ft_putchar_fd(num + '0', 1);
		else //11-15
			ft_putchar_fd(num -10 + 'a', 1);
	}
	return (len);
}

int ft_len(unsigned num)
{
	size_t count;

	count = 0;
	if(num == 0)
		count++;
	while (num != 0)
	{
		count++;
		num = num / 16;
	}
	return (count);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	size_t	i;
	size_t	return_len;

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
			//return_len ++;
			return_len += sign_behavior(fmt[i], ap);//flag etc... check
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
/*
int main (void)
{

	int	a;
	a = ft_printf("hoge\n",1);
	printf("%d", a);


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

	int	u;
	u = printf("%u\n", 1234);
	printf("%d\n", u);

	int	t;
	t = ft_printf("%u\n", 1234);
	printf("%d\n", t);


	int	x;
	x = printf("%x\n", 2744);
	printf("%d\n", x);

	int	w;
	w = ft_printf("%x\n", 2744);
	printf("%d\n", w);

	return (0);

}
*/
