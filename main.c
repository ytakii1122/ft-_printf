
#include <stdio.h>
/*
int main(void)
{
	int a;
	a = 0;
	a = printf("abc\0defg\n");
	printf("%d", a);
	return (0);
}*/


int	ft_printf(const char *fmt, ...);
int main (void)
{
	int	a;
	a = ft_printf("hoge\n");
	printf("%d\n", a);

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

/*	int	f;
	f  = printf("%d\n", 1);
	printf("%d", f);

	int	g;
	g  = ft_printf("%d\n", 1);
	printf("%d", g);

*/
	return (0);

}

