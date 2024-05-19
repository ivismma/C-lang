#include <iostream>
#include <cmath>

#define MAX 10000

using namespace std;
bool checaResp(int r);

int main(void){
	int N;
	scanf("%d", &N);
	if(N < 1 || N > MAX) return 1;
	
	int atual, anterior, max = 0, consec = 1;
	cin >> atual;
	if(!checaResp(atual)) return 2;
	anterior = atual;
	while(--N){
		cin >> atual;
		if(!checaResp(atual)) return 2;
		
		if(atual == anterior){
			++consec;
			if(consec > max) max = consec;
		}
		else consec = 1;
		anterior = atual;
	}
	cout << max << endl;
	return 0;
}

bool checaResp(int r){
	return r >= -pow(2, 31)-1 && r <= pow(2,31)-1;
}
