#include <stdio.h>

int main(){
float p, q, r;
int x, y;

r = 15 / 2; //r = 7
r = r + 1.3; //r = 8.30
x = 2099 / 100.0; //x = 20
y = x - 0.1; //y = 19
p = y % 10; //p = 9.0
q = p + 1; //q = 10.0
x = q - 1.1; //x = 10.0 - 1.1 = 8.9 (8) <-- int
y = x - 5; //y = 8 - 5 = 3
y = y+y * y; //y = 3+3 * 3 = 3+(3*3) = 3 + 9 = 12
}

// Efetuei testes no compilador com base nas minhas respostas.
