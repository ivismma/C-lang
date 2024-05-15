#include <iostream>

// Leetcode #167 (modificado -> encontrar *todas* as somas e imprimir)
// Dado um vetor ordenado e um valor N, imprimir todas as somas de dois elementos que resultam no valor N inserido.

using namespace std;

void achaSoma(int *v, short tam, short N);

int main(void){
	int v[] = {0,1,1,3,4,5,6,8,9,10,11,12,13,13,14};
	short tam = sizeof(v)/sizeof(v[0]);
	short N; // target
	
	cout << "Insira N" << endl << "--> ";
	cin >> N;
	achaSoma(v, tam, N);
	
	return 0;
}
void achaSoma(int *v, short tam, short N){
	int i = 0, j = tam-1; // i -> inicio | j -> fim
	cout << "-------" << endl;
	while(i < j){
		int soma = v[i] + v[j];
		if(soma == N){
			cout << v[i] << " e " << v[j] << "\n-------\n";
			int aux = i++; // só pra impedir amostragem de somas repetidas:
			while(v[i] == v[aux]) ++i;
		}
		else if(soma < N) ++i;
		else --j; // soma > N
	}
}
