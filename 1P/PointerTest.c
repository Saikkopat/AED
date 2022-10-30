#include <stdio.h>
#include <stdlib.h>

struct p3{
	int a;
};

struct p2{
	int b;
	struct p3 *sig;
};

struct p1{
	int c;
	struct p2 *sig;
};

int main(){
	struct p1 d1, *d_ptr;
	struct p2 d2;
	struct p3 d3;

	d3.a = 3;
	d2.b = 1;
	d1.c = 2;
	d_ptr = &d1;
	d1.sig = &d2;
	d2.sig = &d3;

	printf("\n %d\n\n", (*(d_ptr -> sig)).b);

	return 0;
}