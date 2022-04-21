/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft_putnbr_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytakii </var/mail/ytakii>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 12:36:23 by ytakii            #+#    #+#             */
/*   Updated: 2022/02/22 13:15:55 by ytakii           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	num;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		num = n * -1;
	}
	else
		num = n;
	if (10 <= num)
	{
		ft_putnbr_fd(num / 10, fd);
		ft_putnbr_fd(num % 10, fd);
	}
	else
		ft_putchar_fd((num + '0'), fd);
}
/*
int	main(void)
{
int i = (-2147483647 -1);
char buff[0xF0];

ft_putnbr_fd(i, 2);
write(2, "", 1);
}
*/
