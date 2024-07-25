/*
https://olimpiada.ic.unicamp.br/pratique/pj/2008/f1/vestib/
OBI 2008 - Vestibular

Entrada
A entrada contém um único conjunto de testes, que deve ser lido do dispositivo de entrada padrão. 
A primeira linha da entrada contém um único inteiro N, indicando o número de questões da prova. 
A segunda linha da entrada contém uma cadeia de N caracteres, indicando o gabarito da prova. 
A terceira linha da entrada contém outra cadeia de N caracteres, indicando as opções marcadas pelo candidato.
 Ambas as cadeias contêm apenas os caracteres `A", `B", `C", `D" e `E" (sempre em letra maiúscula).

Saída
Seu programa deve imprimir na saída padrão uma única linha contendo um único inteiro, indicando o número 
de acertos do candidato.

Exemplo de entrada:
5
ABAAC
ABCDE

Saída: 2 (acertos)

*/

#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

bool valido(string v, int n);
int contabiliza(string resp, string gabarito, int n);

int main(){  
	int n, acertos;
	
	// "A primeira linha da entrada contém um único inteiro N (1 <= N <= 80)"
	do cin >> n; while(n < 1 || n > 80);
	string resp, gabarito;
	
	getline(cin>>ws, gabarito);
	if(!valido(gabarito,n)) return 10; 
	
	getline(cin>>ws, resp);
	if(!valido(resp,n)) return 11; 
	
	acertos = contabiliza(resp, gabarito, n);
	cout << acertos << endl;
	
	return 0;
}

// Verifica se a alternativa está entre 'A' e 'E' ao mesmo tempo que verifica se não é maiúscula
// porque minúsculas são maiores que 'E' na tabela ASCII.
bool valido(string v, int n){
	for(int i = 0; i < n; ++i)
		if(v[i] < 'A' || v[i] > 'E')
			return false;
      
	return true;
}

int contabiliza(string resp, string gabarito, int n){
    int cont = 0;
    for(int i = 0; i < n; i++) 
		cont += (resp[i] == gabarito[i]);
    
	return cont;
}
