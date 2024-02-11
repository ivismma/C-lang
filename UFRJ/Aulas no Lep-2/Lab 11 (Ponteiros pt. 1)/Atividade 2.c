/*
Atividade 2: Considerando o programa apresentado abaixo, responda:
(a) O que esse programa faz?

Aloca um endereço frase de tamanho ( 1* n bytes digitado pelo usuário)
e utiliza manipulação de endereço de memória para juntar a frase inserida, quando ouver espaço.

(b) Mostre o que será impresso se o usuário entrar com os valores: 10 boa prova!

Será impresso "boaprova!"

(c) Mostre o que será impresso se o usuário entrar com os valores: 50 bom dia, como vai?

*/

#include <stdio.h>
#include <stdlib.h>

// TESTE
//   1 0   b o a 
//i  0 1 2 2 3 4 
//j  0 1 2 3 4 5 

// Concluí que o código pausa a acumulação do i quando encontra espaços, fazendo com que remova os espaços na string final.
// Pois --> linha 43: *(frase + i) = *(frase + j); //
// R: Será impresso "bomdia,comovai?"

int main() {
    char* frase; int n;
    
    puts("digite o tamanho da frase: ");
    scanf("%d", &n); getchar();
    frase = (char*)malloc((n + 1) * sizeof(char));
    if (frase == NULL) return -1;
    
    puts("digite a frase: ");
    //scanf("%[ˆ\n]", frase);
    fgets(frase, n + 1, stdin);
    int j = 0, i = 0;
    while (*(frase + j) != '\0') { 
        if (*(frase + j) != ' ') { // espaço
            *(frase + i) = *(frase + j); //
            i++;
        }
        j++;
    }
    frase[i] = '\0';
    printf("%s\n", frase);
    return 0;
}
