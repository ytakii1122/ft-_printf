# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ytakii </var/mail/ytakii>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/01 19:29:18 by ytakii            #+#    #+#              #
#    Updated: 2022/03/30 16:32:13 by ytakii           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = libftprintf.a

CC  = cc

CFLAGS  = -Wall -Wextra -Werror

SRCS    = 

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
