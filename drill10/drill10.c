#include <stdio.h> //standard I/O

void C_func(char* p, int x){
	printf("p: %s, x: %d\n", p,x);
/* %s means "Print a C-style string", %d means "Print an integer using decimal digits"*/
}

int main(){
	printf("Hello, World!\n");

	char* h = "Hello";
	char* w = "World!";

	printf("%s %s\n",h,w);

	C_func("foo",7);

	return 0;
}
