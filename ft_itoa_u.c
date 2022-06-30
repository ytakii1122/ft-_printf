/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytakii </var/mail/ytakii>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 12:31:11 by ytakii            #+#    #+#             */
/*   Updated: 2022/06/30 20:23:43 by ytakii           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"


int	ft_num_count_u(unsigned int c)
{
	int	count;

	count = 0;
	if (c == 0)
		return (1);
	while (c > 0)
	{
		c = c / 10;
		count++;
	}
	return (count);
}

int	ft_nega_u(unsigned int	n)
{
	if (n < 0)
		return (-1 * n);
	else
		return (n);
}

char	*ft_itoa_u(unsigned int n)
{
	char			*str;
	unsigned int	num;
	int				num_count;

	num = ft_nega_u(n);
	num_count = ft_num_count_u(num);
	if (n < 0)
		num_count++;
	str = (char *)malloc(sizeof(char) * (num_count + 1));
	if (str == NULL)
		return (NULL);
	if (n < 0)
		str[0] = '-';
	if (n == 0)
		str[0] = '0';
	str[num_count] = '\0';
	while (0 < num)
	{
		num_count--;
		str[num_count] = num % 10 + '0';
		num = num / 10;
	}
	return (str);
}
/*
int main(void)
{
	int a = -11111;

	printf("%s\n", ft_itoa(a));
	return (0);
}*/