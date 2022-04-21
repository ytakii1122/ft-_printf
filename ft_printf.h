/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytakii </var/mail/ytakii>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:06:07 by ytakii            #+#    #+#             */
/*   Updated: 2022/04/21 22:44:44 by ytakii           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef FT_PRINTF
#define FT_PRINTF
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
//#include <assert.h>
#include "libft.h"


int	ft_printf(const char *fmt, ...);

#endif
