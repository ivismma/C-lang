#include <stdio.h>

int main(){
    int n, i=0, j=1;
    do{
    printf("Digite uma quantidade de linhas de -10 até 10 (exceto zero): ");
    scanf("%d", &n);
    } while(n == 0 || n < -10 || n > 10);
    printf("\n");

    if(n > 0){
        while(n > 0){
            i = n;
            while(i > 0){
                printf("*");
                --i;
            }
            printf("\n");
            --n;
        }
    }
    else{
        while(j <= -n){
                while(i < j){
                    printf("*");
                    ++i;
                }
                i = 0;
                ++j;
                printf("\n");
            }
        }
    printf("\n");
    return 0;
}