#include <stdio.h>

////////--1---////
/*int i =1;
int main()
{
	char* a[] = {"hu ","weiwei","hello"};
	char** p = a;
	p++;	
	printf("%s\n",*p);
	
} */

/*
void print1(int x)
{
	printf("%d\n",x);
}
void print2(int x)
{
	printf("%d\n",x);
}
void print3(int x)
{
	printf("%d\n",x);
}
#define FUN {(void (*)(int))print1,(void (*)(int))print2,( void (*)(int))print3}
typedef struct 
{
	void (*fun1)(int) ;
	void (*fun2)(int) ;
	void (*fun3)(int) ;
}func_;

int main()
{
	func_ f = FUN;
	f.fun1(1);
	f.fun2(2);
	f.fun2(3);
	return 0;
}
*/
