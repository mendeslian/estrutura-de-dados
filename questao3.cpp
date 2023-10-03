#include <stdio.h>

int main() {
	int num, *p;
	
	p = &num;
	
	printf("Entre com um numero inteiro: ");
	scanf("%d", p);
	
	printf("O numero digitado foi: %d", *p);
}
