#include <stdio.h> 
#include <stdarg.h>

int    ft_printf(const char *s, ...)
{
	va_list list;
	//char *str;
	char	*str;
	
	printf("%s\n", s);
	va_start(list, s);
	str =(char *) va_arg(list, char*);
	printf("%s\n",str);
	str = (char*)va_arg(list, char*);
	printf("%s\n",str);
	va_end(list);
	return (0);
}

int main(void)
{
	//char	*str;
	//char	*a;

	//a = "abcdefg";
	//char	a = "b"; 
	//a[1] = 'b';
	//char	b[] = "abcdefg";
	//printf("%s\n", a);
	//printf("%s\n", b);
	ft_printf("%s","abcd","%d");
	//char	str = foo(&a);
	return (0);
}
