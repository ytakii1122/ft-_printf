#include <stdio.h>
#include <stdarg.h>

void func( int n, char *p, ... );
int main( void )
{
		int	i;
		char	a[10];
		
		i = 2;
		a[0] = 'c';
		a[1] = 'i';
		func( i, a, 'A', 10 );
		
		i = 3;
		a[0] = 'i';
		a[1] = 'f';
		a[2] = 's';
		func( i, a, 20, 0.234, "Hello." );
	
		return 0;
}

void func( int n, char *p, ... )
{
	int i;
	char cval;
	int ival;
	float fval;
	char *sval;
	va_list	ap;

	va_start( ap, p );
	for( i = 1; i <= n; i++ )
	{
		printf( "%d: ", i);
		switch( *p++ )
		{
			case 'c':
				cval = va_arg( ap, int );
				printf( "%c\n",cval);
				break;
			case 'i':
				ival = va_arg( ap, int );
				printf( "%d\n", ival );
				break;
			case 'f':
				fval = va_arg( ap, double );
				printf( "%f\n", fval );
				break;
			case 's':
			for( sval = va_arg( ap, char *); *sval; sval++ )
				putchar( *sval );
	printf( "\n" );
	break;
	}
}
va_end( ap );
}
