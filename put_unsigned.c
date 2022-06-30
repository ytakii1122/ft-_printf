# include "printf.h"
# include "libft.h"

/*

int	put_x()
{
		x = (int)va_arg(ap, unsigned int);
		ft_x(x, input);
		len = ft_len(x);
}	

int	put_p()
{

		write(1,"0x",2);
		len = 2;
		p = (unsigned long long)va_arg(ap, unsigned long long);
		ft_x(p, input);
		len += ft_len(p);
	
}
*/

int ft_len(unsigned long long num);
int ft_decimal_change(unsigned long long num, const char input);
int	put_unsigned(const char input, va_list ap)
{
	size_t	len;
	unsigned long long list;

	len = 0;
	if (input == 'p')
	{
		write(1,"0x",2);
		len = 2;
	}
	list = (unsigned long long)va_arg(ap, unsigned long long);
	ft_decimal_change(list, input);
	len += ft_len(list);
	return (len);
}

int ft_decimal_change(unsigned long long num, const char input)
{
	if (num >= 16)
	{
		ft_decimal_change(num / 16, input);
		ft_decimal_change(num % 16, input);
	}
	else
	{
		if(num < 10)
			ft_putchar_fd(num + '0', 1);
		else //11-15
		{
			if ( input == 'X')
				ft_putchar_fd(num -10 + 'A', 1);
			else
				ft_putchar_fd(num -10 + 'a', 1);
		}
	}
	return (0);
}

int ft_len(unsigned long long num)
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
