#include <stdio.h>
#include <stdarg.h>

int add(int n, ...);

int main(int argc, char *argv[])
{
	//printf("test 1:%d\n", add(0));
	//printf("test 2:%d\n", add(1, 10));
	printf("test 3:%d\n", add(2, 10, 20));
	//printf("test 4:%d\n", add(3, 10, 20, 30));
	//printf("test 5:%d\n", add(4, 10, 20, 30, 40));
}


//#define MAX_ARGS 3
int add(int n, ...)
{
	int total = 0;
	va_list ap;
	int i;

	i = 0;
	va_start(ap, n);
	/*while (i < n && i < MAX_ARGS)*/
	//{
		total = va_arg(ap, int);
		printf("%d\n" ,total);
		//i++;
		//printf("%d\n",total);
		//total = va_arg(ap, int);
		//printf("%d\n",total);
	//}
	va_end(ap);
	return (total);
}
