#include <stdio.h>

int main() {
	int num; 
	int *ponteiro; // Declarando o ponteiro
	ponteiro = &num; // Pegando o endere�o de num
	
	printf("Entre com um numero inteiro: ");
	scanf("%d", ponteiro); // Salvando a entrada no endere�o de "num"
	
	printf("O numero digitado foi: %d", ponteiro); // Imprimindo o valor da vari�vel atrav�s do ponteiro
}
