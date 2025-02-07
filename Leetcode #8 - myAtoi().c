#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

// https://leetcode.com/problems/string-to-integer-atoi/

int myAtoi(char *s){
	int i = 0;
	// pular espaços
	while(s[i] == ' ') ++i;
	
	if(s[i] == '\0') return 0;
	
	long long value = 0;     // valor armazenado
	bool isNegative = false; // sinal
	
	// checagem de sinal, se houver:
	if(s[i] == '-'){
		isNegative = true;
		++i;
	}
	else if(s[i] == '+')
		++i;
	
	char c = s[i++];
	while(c != '\0'){
		if(c < 48 || c > 57) // se não é dígito, interrompe.
			break;
		else{
			int digit = c-48; // 48 - '0' (ASCII)
			
			if(!isNegative){
				if((long long) (value*10 + digit) > INT_MAX)
					return INT_MAX;
			}
			else{
				if((long long) (-(value*10 + digit) <= INT_MIN))
					return INT_MIN;
			}
				
			value = value*10 + digit; // não vai dar overflow.. soma valor
		}
		c = s[i++];
	}
	return (int) (isNegative)? -value : value;
}

int main(void){
	//printf("%d", myAtoi(""));
	return 0;
}
