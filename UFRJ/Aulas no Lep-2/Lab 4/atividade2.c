/*Atividade 2
Escreva um programa em C que imprima uma figura como a mostrada
abaixo. O número de linhas da figura deve ser informado pelo usuário e não
pode ultrapassar 10. Caso ultrapasse, informar o erro e terminar o
programa.*/

#include <stdio.h>

int main(){
    int n, i;
    do{
    printf("Digite uma quantidade de linhas entre 1 a 10: ");
    scanf("%d", &n);
    } while(n < 1 || n > 10);

    printf("\n");
    
    while(n > 0){
        i = n;
        while(i > 0){
            printf("*");
            --i;
        }
        printf("\n");
        --n;
    }
    printf("\n");

    return 0;
}