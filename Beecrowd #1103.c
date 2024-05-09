#include <stdio.h>

// Problema 1103 do Beecrowd
// Código comprimido.

int main() {
 	
 	int H1, M1, H2, M2;
 	
 	while(scanf("%d %d %d %d", &H1, &M1, &H2, &M2) && (H1 || M1 || H2 || M2)){
	 	if(H2 < H1){
		 	if(M2 < M1) printf("%d\n", (24-(H1-H2)-1)*60+(60+(M2-M1)));
			else if(M2 > M1) printf("%d\n", (24-(H1-H2))*60+(M2-M1));
			else printf("%d\n", (24-(H1-H2))*60);
		}
		else if(H2 > H1){
			if(M2 < M1) printf("%d\n", (H2-H1-1)*60+60+(M2-M1));
			else if(M2 > M1) printf("%d\n", (H2-H1)*60+(M2-M1));
			else printf("%d\n", (H2-H1)*60);
		}
		else{
			if(M2 < M1) printf("%d\n", 1440+(M2-M1));
			else if(M2 > M1) printf("%d\n", (M2-M1));
			else printf("%d\n", 0);
		}
	}
    return 0;
}
