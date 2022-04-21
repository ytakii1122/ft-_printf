# include "ft_printf.h"
# include <stdio.h>
# include "libft.h"


int	ft_printf(const char *fmt, ...);
int main(void)
{
	//char a[] = "12345";
	//char	a = 'a';
	

	//ft_putstr_fd(a, 2);
	
	char c;
	c = ft_printf("hoge","hogehoge2");
	//printf("%c\n", c);
	return(0);
}


