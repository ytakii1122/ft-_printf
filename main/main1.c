#include <stdio.h> 
#include <stdarg.h>

char	foo(char *fmt,...) 
{
	va_list ap;
	int d;
	char c;
	char *s;
	
	c = 0;
	printf("1\n");
	va_start(ap, fmt);
	printf("2\n");
	printf("%c\n",fmt);
//	s = va_arg(ap, char *);
//	printf("string %s\n", s);
//			case 'd':
//				d = va_arg(ap, int);
//				printf("int %d\n", d);
//				break;
//			case 'c':
	c = (char) va_arg(ap, int);
	printf("3\n");
	printf("%c\n", c);

	va_end(ap);
	return (c);
}

int main(void)
{
	//char	*str;
	//char	*a;

	//a = "abcdefg";
	char	a = "bcdef"; 
	//a[1] = 'b';
	//char	b[] = "abcdefg";
	printf("%c\n", a);
	//printf("%s\n", b);
	char	str = foo(&a);
}

