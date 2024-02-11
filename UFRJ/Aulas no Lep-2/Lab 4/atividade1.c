/*
Autor: Ivis Muzi
Data: 06/09/2023
Descrição: <o que o programa faz>
Entrada: <o que o programa espera receber como entrada>
Saída: <o que o programa retorna para o usuário>
Defesa: <restrições sobre os dados de entrada, se
existirem>
*/

/* Atividade 1
Escreva um programa em C que receba como entrada dois números inteiros
x e y, onde x != 0 e y >= 0, e calcule x^y (sem usar a função pow()). Utilize o
comando de repetição do-while. */

#include <stdio.h>

// ITERATIVO
/*float potencia(int x, int y){
    int soma = 1;
    if(y == 0){
        return soma;
    }
    while (y != 0){
        soma *= x;
        --y;
    }
    return soma;
}*/

// RECURSIVO
float potencia(int x, int y, int z){
    return (y == 0)? z: potencia(x,y-1,z*x);
}

int main(){
    int x,y,z;
    do{
        printf("Digite a base: ");
        scanf("%d", &x);
        printf("Digite o expoente: ");
        scanf("%d", &y);
    } while(x == 0 || y < 0);

    z = potencia(x,y,1);
    printf("O número %d elevado a %d é igual a: %d\n\n", x, y, z);

    return 0;
}