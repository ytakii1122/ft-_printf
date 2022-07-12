/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytakii </var/mail/ytakii>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 12:31:11 by ytakii            #+#    #+#             */
/*   Updated: 2022/07/12 15:29:37 by ytakii           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

char	*ft_itoa_u(unsigned int n)
{
	char			*str;
	int				num_count;

	num_count = ft_num_count_u(n);
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
	while (0 < n)
	{
		num_count--;
		str[num_count] = n % 10 + '0';
		n = n / 10;
	}
	return (str);
}
