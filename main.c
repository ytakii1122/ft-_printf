#include <stdio.h>
#include "ft_printf.h"

int	ft_printf(const char *fmt, ...);
/*
int main(void)
{
	int a;
	a = 0;
	a = printf("abc\0defg\n");
	printf("%d", a);
	return (0);
}*/
int main (void)
{
/*
	int	a;
	a = ft_printf("hoge:%d\n",1);
	printf("%d\n", a);

	int	b;
	b = printf("hoge:%d\n",1);
	printf("%d\n", b);


	int	b;
	b = ft_printf("%c\n",'a');
	printf("%d\n", b);

	int	c;
	c  = printf("%c\n",'a');
	printf("%d\n", c);
*/
	int	d;
	d = 0;
	d  = printf("%s\n", NULL);
	printf("%d\n", d);
	
	int	e;
	e = 0;
	e  = ft_printf("%s\n", NULL);
	printf("%d\n", e);
/*
	int	f;
	f  = printf("%d\n", 1);
	printf("%d\n", f);

	int	g;
	g  = ft_printf("%d\n", 1);
	printf("%d\n", g);

	int k;
	k = printf("%%\n");
	printf("%d\n",k);

	int l;
	l = ft_printf("%%\n");
	printf("%d\n",l);

	int	u;
	u = printf("%u\n", 1234);
	printf("%d\n", u);

	int	t;
	t = ft_printf("%u\n", 1234);
	printf("%d\n", t);
*/
/*
	int	x;
	x = printf("%X\n", 2744);
	printf("%d\n", x);

	int	w;
	w = ft_printf("%X\n", 2744);
	printf("%d\n", w);

	return (0);
	*/
}
