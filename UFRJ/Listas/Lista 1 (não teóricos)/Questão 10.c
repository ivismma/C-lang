#include <stdio.h>
#include <math.h>
#define True 1
#define False -1

float dist(float x1,float x2,float y1,float y2){
	float DeltaX = (x2 - x1);
    float DeltaY = (y2 - y1);
    float D = sqrt(pow(DeltaX, 2) + pow(DeltaY, 2));
    return D;
}
int main(){
	float x1,x2,y1,y2;
	// (4,8) e (2,1) = 
	
	printf("Digite x1:\n");
	scanf("%f", &x1);
	printf("Digite y1:\n");
	scanf("%f", &y1);
	printf("Digite x2:\n");
	scanf("%f", &x2);
	printf("Digite y2:\n");
	scanf("%f", &y2);
	
	printf("A distância entre P1 e P2 = %f", dist(x1,x2,y1,y2));
	
	return 0;
}
