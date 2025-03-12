// Leetcode #79 - Word Search
// https://leetcode.com/problems/word-search/

bool exist(char **M, int L, int *C, char *word);
bool exist_backtracking(char **M, bool **visited, int L, int *C, char *word, int i, int j);


bool exist(char **M, int L, int *C, char *word){
	// aloca��o (e inicializa��o) de matriz aux. que vai manter 
	// controle dos elementos j� visitados em uma rotina de checagem.
	// obs.: checagem de sucesso na aloca��o ignorado
	bool **visited = (bool **) malloc(L*sizeof(bool *));
	for(int i = 0; i < L; ++i){
		visited[i] = (bool *) malloc((*C)*sizeof(bool));
		for(int j = 0; j < *C; ++j)
			visited[i][j] = false;
	}
	
	// backtracking:
	bool found;
	for(int i = 0; i < L; ++i){
		for(int j = 0; j < *C; ++j){
			found = exist_backtracking(M, visited, L, C, word, i, j);
			if(found)
				goto END; // goto label para sair do loop aninhado e desalocar a matriz.
				// sem esse goto label seria necess�rio for�ar i = L e dar break.
        }
	}
	
	END:
	// desaloca��o da matriz auxiliar
	for(int i = 0; i < L; ++i)
		free(visited[i]);
	free(visited);
	
	return found;
}

bool exist_backtracking(char **M, bool **visited, int L, int *C, char *word, int i, int j){
	// offset para buscas adjacentes (cima, baixo, esq., dir.):
	const static struct{
		int i;
		int j;
	} offset[4] = { {0,1}, {1, 0}, {0, -1}, {-1, 0} };
	
	
	// significa q o ponteiro da palavra chegou ao fim, encontrou a busca da palavra..
	if(word[0] == '\0')
		return true;
	
	// sS n�o est� fora dos limites, ou j� foi visitado, ou a letra atual n�o � a buscada...
	if(i < 0 || i == L || j < 0 || j == C[0] || visited[i][j] || M[i][j] != word[0])
		return false;
		
	// se chegamos at� aqui, � porque a letra atual � a buscada...
	visited[i][j] = true; // marcar como visto na matriz auxiliar.
	
	// a partir da itera��o atual, realiza backtracking para cima, esq., dir. e baixo...
	for(int k = 0; k < 4; ++k)
		if(exist_backtracking(M, visited, L, C, word+1, i+offset[k].i, j+offset[k].j))
			return true; // atingiu caso base (completou a string buscada)
	
	// n�o encontrou a pr�x. letra atual da string
	visited[i][j] = false; // desmarcar como visto pos. atual.
	
	return false;
}
