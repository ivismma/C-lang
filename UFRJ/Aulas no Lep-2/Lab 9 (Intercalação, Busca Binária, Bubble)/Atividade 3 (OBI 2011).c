/*
Atividade 3 (OBI 2011):
Pedrinho é um garoto fascinado por jogos de tabuleiro. Nas férias de janeiro, ele aprendeu um jogo
chamado Campo Minado, que é jogado em um tabuleiro com N células dispostas na horizontal. O
objetivo desse jogo é determinar, para cada célula do tabuleiro, o número de minas explosivas nos
arredores da mesma (que são a própria célula e as células imediatamente vizinhas à direita e à
esquerda, caso existam). Por exemplo, considere um tabuleiro com 5 células, configuradas da
seguinte forma (# significa “mina”):

[][#][#][][#]

A primeira célula não possui nenhuma mina explosiva, mas é vizinha de uma célula que possui. Nos
arredores da segunda célula temos duas minas (ela mesma e a vizinha à direita), e o mesmo
acontece para a terceira e quarta células; a quinta célula só tem uma mina explosiva em seus
arredores. A resposta para o caso acima seria:

[1][2][2][2][1]

Pedrinho sabe que você está cursando Prog-I e resolveu lhe pedir para escrever um programa em C
que, dado um tabuleiro, imprima o número de minas na vizinhança de cada posição.
A entrada deverá ser lida de teclado. A primeira linha da entrada contém um inteiro N indicando o
número de células no tabuleiro. O tabuleiro é dado na próxima linha. O i-ésimo elemento da
segunda linha contém 0 se não existe uma mina na i-ésima célula do tabuleiro e 1 caso contrário.
A saída é composta por N valores e deverá ser escrita na tela. O i-ésimo valor da saída contém o
número de minas explosivas nos arredores da i-ésima célula do tabuleiro.
*/

#include <stdio.h>

void verificaMinas(int v[], int res[], int n){ // Retorna Vetor com o resultado de minas aos arredores do vetor inicial (saída).
	int soma = 0, 
	i = 0;
	/*
	Ideia do algoritmo: o vetor resultado (da quantidade minas ao redor) inicia como zero por causa da função zeraVetor(),
	a cada checagem uma expressão lógica é testada (se tem minas ao redor), ela retorna 1 se for positiva e
	0 caso contrário, cada iteração de res[i] vai terminar com o total de minas ao redor somadas.
	*/
	
	// Checagem de v[] para i = 0, pois i = -1 não existe
	res[i] += (v[i] == 1);
	res[i] += (v[i+1] == 1);
	++i;
	
	// Checagem de v[] para i = 1 até penúltimo índice.
	do{
		res[i] += (v[i-1] == 1);
		res[i] += (v[i] == 1);
		res[i] += (v[i+1] == 1);
		++i;
	} while(i < n-1); // Usando o do-while, a função fica otimizada economizando uma checagem desnecessária (a primeira).
	
	// Checagem de v[] para i = último índice, pois não existe vetor de v[n];
	res[i] += (v[i-1] == 1);
	res[i] += (v[i] == 1);
}


/*void verificaMinasRec(int v[], int res[], int n, int i) {
    if (i == n)
        return;
        
    res[i] += (v[i] == 1);
    res[i] += (i > 0 && v[i - 1] == 1);
    res[i] += (i < n - 1 && v[i + 1] == 1);
    verificaMinasRec(v, res, n, i + 1);
}*/

void zeraVetor(int v[], int n){
	for(int i = 0;i < n;++i) v[i] = 0;
}

void exibirVetor(int v[], int n){
	for(int i = 0; i < n; ++i) printf("%d ", v[i]);
}

int main(){
	int n;
	scanf("%d", &n); // 1º linha: tamanho N 
	int v[n], res[n]; zeraVetor(res, n); // Zera vetor resultado de minas ao redor.
	
	for(int i = 0; i < n; ++i) scanf("%d", &v[i]); // 2ª linha: Preenche vetor.
	verificaMinas(v, res, n);
	exibirVetor(res, n); // 3ª linha: Resultado.
}
