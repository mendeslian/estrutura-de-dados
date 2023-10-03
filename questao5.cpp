#include <stdio.h>

int main() {
	int mat[3][3], *pont;
	
	for(pont = &mat[0][0]; pont <= &mat[2][2]; pont++) {
		printf("Entre com um valor da matriz: ");
		scanf("%d", pont);
	}
	
	for(pont = &mat[0][0]; pont <= &mat[2][2]; pont++) {
		printf("%d |", *pont);
	}
}
