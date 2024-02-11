/*
Autor: Ivis Muzi
Data: 23/08/2023
Descrição: Recebe coordenada (x,y) e informa em qual quadrante (ou eixo) está localizada.
Entrada: Coordenadas x e y.
Saída: A localização (1º,2º,3º ou 4º ou eixo do plano cartesiano.)
Defesa: Deve ser um número real (Não há restrições para essa função).
*/

#include <stdio.h>
int main(){
	float x,y;
	
	printf("Digite o valor x: ");
	scanf("%f", &x);
	printf("Digite o valor y: ");
	scanf("%f", &y);
	
	if(x > 0){ // Quadrante 1 ou 4
		if(y > 0){
			printf("A coordenada do ponto %.1f, %.1f está no 1º quadrante.\n", x,y);
		}
		else if(y < 0){
			printf("A coordenada do ponto %.1f, %.1f está no 4º quadrante.\n", x,y);
		}
		else{
			printf("A coordenada do ponto %.1f, %.1f está no eixo x.\n", x,y);
		}
	
	}
	else if(x < 0){ // Quadrante 2 ou 3
		if(y > 0){
			printf("A coordenada do ponto %.1f, %.1f está no 2º quadrante.\n", x,y);
		}
		else if(y < 0){
			printf("A coordenada do ponto %.1f, %.1f está no 3º quadrante.\n", x,y);
		}
		else{
			printf("A coordenada do ponto %.1f, %.1f está no eixo x.\n", x,y);
		}
	}
	else{ // (x = 0)
		if(y == 0){
			printf("A coordenada do ponto %.1f, %.1f está na origem (eixo x e y).\n", x,y);
		}
		else{
			printf("A coordenada do ponto %.1f, %.1f está no eixo y.\n", x,y);
		}
	}

	return 0; 
}
