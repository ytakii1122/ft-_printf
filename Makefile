# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ytakii </var/mail/ytakii>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/01 19:29:18 by ytakii            #+#    #+#              #
#    Updated: 2022/04/21 22:17:59 by ytakii           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = libftprintf.a

CC  = gcc

CFLAGS  = -Wall -Wextra -Werror

SRCS    = ft_printf.c ft_putnbr_fd.c ft_putstr_fd.c ft_putchar_fd.c 

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

test: re all
	    $(CC) $(CFLAGS) $(NAME)
		    ./a.out

.PHONY: all, clean, fclean, re, test
