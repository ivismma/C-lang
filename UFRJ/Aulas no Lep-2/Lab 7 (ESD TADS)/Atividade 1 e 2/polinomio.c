#include "polinomio.h"
#include <math.h>
#include <limits.h>

polinomio somaPolinomio(polinomio p1, polinomio p2){
	polinomio p_res;
	p_res.c3 = p1.c3 + p2.c3; 
	p_res.c2 = p1.c2 + p2.c2;
	p_res.c1 = p1.c1 + p2.c1;
	p_res.c0 = p1.c0 + p2.c0;
	return p_res;
}

polinomio derivaPolinomio(polinomio p){
	polinomio p_res;
	p_res.c3 = 0;
	p_res.c2 = 3*p.c3;
	p_res.c1 = 2*p.c2;
	p_res.c0 = p.c1;
	return p_res;
}

solucao raizesPolinomio(polinomio p){
	float rdelta, delta = pow(p.c1,2)-4*(p.c2*p.c0); // rdelta = Raiz do determinante (DELTA)
	solucao p_res;
	rdelta = sqrt(delta);
	p_res.x1 = (-p.c1-rdelta)/(2*p.c2);
	p_res.x2 = (-p.c1+rdelta)/(2*p.c2);
	// CRIAR DEFESA
	// (está na main)
	return p_res;
}

float valorPolinomio(polinomio p, int x){
	return ( (p.c3*x) + (p.c2*x) + (p.c1*x) + (p.c0) );
}
