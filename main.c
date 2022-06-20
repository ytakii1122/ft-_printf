
#include <stdio.h>

int main(void)
{
	int a;
	a = 0;
	a = printf("abc\0defg\n");
	printf("%d", a);
	return (0);
}
