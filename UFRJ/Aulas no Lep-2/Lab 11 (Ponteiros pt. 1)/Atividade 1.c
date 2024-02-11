/*
Atividade 1: Copie o código abaixo e o avalie antes de executá-lo. O que você acha que será
impresso em cada trecho?
Agora rode o programa. Sua intuição se confirmou? Explique o porquê de cada mensagem
apresentada.
*/

#include <stdio.h>
#include <stdlib.h>
#define TAM 3
int main() {
    int v1[TAM]; //Alocação estática
    int* v2 = (int*) malloc(TAM * sizeof(int)); //Alocação dinâmica
    v1[0] = 6; v1[1] = 4; v1[2] = -2;
    v2[0] = 6; v2[1] = 4; v2[2] = -2; //Os mesmos valores em ambos os vetores.
    if (&v1 == &(v1[0])) //O que será impresso?
    // Se endereço de v1 (na stack) == endereço do índice zero de v1.
    // Sim, porque alocação estática, o endereço de v1 já é o próprio endereço do 1ª índice que é 0.
    printf("Os dados de v1 estao armazenados a partir do proprio endereco de v1\n"); // <--
    else
    printf("Os dados de v1 estao separados de v1\n");
    
    if (&v2 == &(v2[0])) //O que será impresso?
    // Os dados estão separados, a variável está na stack, mas o endereço aponta para
    // o ENDEREÇO da 1ª ocorrência que está na HEAP.
    
    printf("Os dados de v2 estao armazenados a partir do proprio endereco dev2\n");
    else
    printf("Os dados de v2 estao separados de v2\n"); // <--
   
    //Comparando os endereços dos dados de v1 e v2:
    if (&(v1[0]) > &(v2[0]))
    puts("Isso eh um absurdo!"); //Por que?? Resposta else.
    else
    puts("Tudo certo!"); // Ele está verificando se o DADO de v1 que é alocação estática é MENOR que o
    // endereço de memória de v2[0] que é possível ser calculado.
    
    int *p1, *p2;
    p1 = &(v1[0]); // p1 recebe o endereço de v1.
    p2 = &(v2[TAM - 1]); // p2 recebe o endereço de v[2].
    for (int i = 0; i < TAM; i++){
        if (*(p1 + i) < *p2) // se CONTEÚDO de (v[] + i) < endereço de memória na heap, ou seja, &v2[0]
        ++(*p1); // Incrementa 1 ao conteúdo de v1[0]
        else
        --p2; // Decrementa 1 ao ENDEREÇO de p2.
    }
    
    /*
    1 ªinteração i = 0, (6 < -2)? NÃO, então p2 vira o endereço de v2[1] ao invés de v2[2].
    2 ªinteração i = 1, (4 < 4)?  NÃO, então p2 vira o endereço de v2[0] ao invés de v2[1].
    3ª interação i = 2, (-2 < 6)? SIM, então o CONTEÚDO de p (que é endereço de memória v1[0]) incrementa 1.
    ou seja, v1[0] = 6+1 = 7.
    */
    
    puts("\nConteudo dos vetores:");
    printf("v1 = ");
    for (int i = 0; i < TAM; i++) printf("%d ", v1[i]); //O que será impresso? 7,4 -2
    // Será impresso: 
    printf("\nv2 = ");
    for (int i = 0; i < TAM; i++) printf("%d ", v2[i]); //O que será impresso? 6, 4, -2.
    return 0;
}