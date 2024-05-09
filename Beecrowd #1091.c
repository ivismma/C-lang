#include <stdio.h>
#include <stdlib.h>

#define MAX_K 1000 // Range máximo do K (queries)
#define MAX_XY 10000 // Range máximo das coordenadas

// Problema #1091 do Beecrowd

void exibirPos(int n, int m, int x, int y);

int main(void){
	
	int k; // "queries"
	int n, m; // division point
	int x, y;
	
	scanf("%d", &k);
	do{
		 while(k <= 0 || k > MAX_K)
			scanf("%d", &k);
	
		do{
				scanf("%d %d", &n, &m);
		} while(n < -MAX_XY || m > MAX_XY);
		
		while(k--){
			do{
				scanf("%d %d", &x, &y);
		} while(x < -MAX_XY || y > MAX_XY);
			exibirPos(n, m, x, y);
		}
		scanf("%d", &k);
	} while(k);
	
	return 0;
}

void exibirPos(int n, int m, int x, int y){
	if(x == n || y == m) printf("divisa\n");
	else if(x > n){
		if(y > m) printf("NE\n");
		else printf("SE\n");
	}
	else{ // x < 0
		if(y > m) printf("NO\n");
		else printf("SO\n");
	}
	
	return;
}
