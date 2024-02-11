
#include <stdio.h>

int somaRecursiva(int m[3][3], int i, int j, int soma){
	if(i == 2 && j == 2){
		soma += m[i][j];
		return soma;
	}
	if(j == 2)
		return somaRecursiva(m, i+1, 0, soma += m[i][j]);
	return somaRecursiva(m, i, j+1, soma += m[i][j]);
}

int main(){
	int m[3][3];
	m[0][0] = 5;
	m[0][1] = 1;
	m[0][2] = 7;
	m[1][0] = 7;
	m[1][1] = 6;
	m[1][2] = 4;
	m[2][0] = 8;
	m[2][1] = 3;
	m[2][2] = 5;
	
	printf("%d\n", somaRecursiva(m, 0, 0, 0));
	return 0;
}
