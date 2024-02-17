#include <stdio.h>
#include <string.h>

struct Aluno{ // Struct armazena quantos forem necessários simultaneamente.
	char nome[60];
	long long matricula;      // Total: 80 bytes
	float CR;                   
};                        

union Temperatura{ // Union só armazena um dado por vez.
	double celsius;
	double fahrenheit;       // Total: 8 bytes 
	double kelvin;           // Se fosse struct: 24 bytes.
};

int main(void){
	struct Aluno aluno;
	union Temperatura temp;
	
	strcpy(aluno.nome, "Joao");
	aluno.matricula = 23619723282;
	aluno.CR = 7.77;
	
	printf("Struct:\n%s | %lld | %f\n", aluno.nome, aluno.matricula, aluno.CR);
	// Será impresso os três dados.
	
	temp.celsius = 40;
	temp.fahrenheit = 104;
	temp.kelvin = 313.15;  // <-- Última atribuição.
	
	printf("Union: %f | %f | %f", temp.celsius, temp.fahrenheit, temp.kelvin);
	
	// Será impresso da Union o valor Kelvin três vezes pois uma union armazena somente
	// um dado por vez, que nesse caso o último inserido foi a da unidade Kelvin.
	// É útil para economizar espaço quando só irá ser utilizado um dos dados por vez,
	// pois este irá sobrescrever o dado atual e permanecer como único na Union.
	
	return 0;
}
