/*Atividade 4: Considere o código abaixo:
#include <stdio.h>
int main() {
    char letra;
    char cifra = 'a';
    printf("Digite uma letra: ");
    letra = getchar();
    
    //Defesa:
    if (!((letra >= 'A' && letra <= 'Z') || (letra >= 'a' && letra <= 'z'))) {
        printf("Caractere invalido");
        return 0;
    }

    printf("A cifra de %c eh %c", letra, cifra);
    return 0;
}
Este código lê um caractere do teclado e, caso o mesmo seja uma letra do
alfabeto, seja minúscula ou maiúscula, o mapeia sempre para a letra ‘a’.
Modifique o programa acima para que ele contemple, ao mesmo tempo,
os dois requisitos a seguir:*/

#include <stdio.h>
#define TRUE 1
#define FALSE 0

int checaLetra(char c){
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')){
        return TRUE;
    }
    return FALSE;
}

char chplus12(char c){
    if(c < 'O')
        return c+12;
    else if(c <= 'Z')
        return c-14;
    else if(c <= 'o')
        return c+12;
    else
        return c-14;
}

int main() {
    char letra;
    char cifra = 'a';
    
    //Defesa:
    
        while(checaLetra){
        printf("Digite uma letra: ");
        letra = getchar();
        }
    printf("O 12º caracter após %c eh %c", letra, chplus12(letra));
    
    return 0;
}