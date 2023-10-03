#include <stdio.h>

int main() {
	float vet[10], *p;
	
	p = &vet[9];
	
	for(p; p >= &vet[0]; p--) {
		printf("Digite um numero para o vetor: ");
		scanf("%f", p);		
	}

	for(p = &vet[0]; p <= &vet[9]; p++) {
		printf("%.1f |", *p);
	}
}



