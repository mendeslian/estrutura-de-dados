#include <stdio.h>

int calculaFatorial(int num) {
	int i,fatorial;
	i = num - 1;
	fatorial = 1;
	for(i; num > 1; i--, num--) {
		fatorial = num * fatorial;
	}
	return fatorial;
}

int main() {
	int num;
	
	printf("Entre com um numero para calcular o fatorial: ");
	scanf("%d", &num);
	
	printf("Fatorial de %d: %d", num, calculaFatorial(num));
}
