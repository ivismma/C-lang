/*
https://olimpiada.ic.unicamp.br/pratique/pj/2008/f1/vestib/
OBI 2008 - Vestibular

Entrada
A entrada cont�m um �nico conjunto de testes, que deve ser lido do dispositivo de entrada padr�o. 
A primeira linha da entrada cont�m um �nico inteiro N, indicando o n�mero de quest�es da prova. 
A segunda linha da entrada cont�m uma cadeia de N caracteres, indicando o gabarito da prova. 
A terceira linha da entrada cont�m outra cadeia de N caracteres, indicando as op��es marcadas pelo candidato.
 Ambas as cadeias cont�m apenas os caracteres `A", `B", `C", `D" e `E" (sempre em letra mai�scula).

Sa�da
Seu programa deve imprimir na sa�da padr�o uma �nica linha contendo um �nico inteiro, indicando o n�mero 
de acertos do candidato.

Exemplo de entrada:
5
ABAAC
ABCDE

Sa�da: 2 (acertos)

*/

#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

bool valido(string v, int n);
int contabiliza(string resp, string gabarito, int n);

int main(){  
	int n, acertos;
	
	// "A primeira linha da entrada cont�m um �nico inteiro N (1 <= N <= 80)"
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

// Verifica se a alternativa est� entre 'A' e 'E' ao mesmo tempo que verifica se n�o � mai�scula
// porque min�sculas s�o maiores que 'E' na tabela ASCII.
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
