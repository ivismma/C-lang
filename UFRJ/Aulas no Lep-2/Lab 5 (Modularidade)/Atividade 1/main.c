// main.c -o main.out -Wall
// ./main.out -Wall

#include <stdio.h>
#include "teste.h"

int main() {
	int a = 3, b = 2, res;
	res = multiplica(a, b);
	printf("res = %d", res);
	return 0;
}
