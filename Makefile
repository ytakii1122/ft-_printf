# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ytakii </var/mail/ytakii>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/01 19:29:18 by ytakii            #+#    #+#              #
#    Updated: 2022/07/05 22:48:53 by ytakii           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = libftprintf.a

CC  = gcc

CFLAGS  = -Wall -Wextra -Werror

SRCS    = ft_printf.c ft_putstr_fd.c ft_putchar_fd.c ft_itoa.c ft_strlen.c ft_itoa_u.c\
		  put_d.c put_s.c put_x.c put_p.c put_u.c put_c.c

OBJS    = $(SRCS:.c=.o)
	AR  = ar rcs
	RM  = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	    $(AR) $(NAME) $(OBJS)

%.o: %.c
	    $(CC) $(CFLAGS) -c $< -o $@

clean:
	    $(RM) $(OBJS)

fclean: clean
	    $(RM) $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re, test
