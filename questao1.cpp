#include <stdio.h>

int main() {
	int num; 
	int *ponteiro; // Declarando o ponteiro
	ponteiro = &num; // Pegando o endereço de num
	
	printf("Entre com um numero inteiro: ");
	scanf("%d", ponteiro); // Salvando a entrada no endereço de "num"
	
	printf("O numero digitado foi: %d", ponteiro); // Imprimindo o valor da variável através do ponteiro
}
