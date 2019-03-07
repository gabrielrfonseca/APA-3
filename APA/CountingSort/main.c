#include <stdio.h>
#include <stdlib.h>

int i = 0, j = 0;

int maiorValor(int *Vetor_A, int tam){
	int maior = 0;

	for (i =0; i < tam; i++){
		if (Vetor_A[i] > maior)
			maior = Vetor_A[i];
	}

	return maior;
}

void countingSort(int *A, int *B, int tam, int k){

	int C[k];

	for(i = 0; i <= k; i++)
		C[i] = 0;

	for(j = 0; j < tam; j++)
		C[A[j]]= C[A[j]] + 1;

	for(i = 1; i <= k; i++)
		C[i] = C[i] + C[i-1];

	for(j = tam -1 ; j >= 0; j--){
		int c = C[A[j]];
		B[c] = A[j];
		C[A[j]] = C[A[j]] - 1;
	}
}

int main(){

	int n;

	printf("Informe o tamanho do vetor: ");
	scanf("%d", &n);

	int A[n];

	printf("Elementos do vetor: ");
		for(int i = 0; i < n; i++){
			scanf("%d", &A[i]);
		}

	int k = 0, tam = 0;

	tam = sizeof(A) / sizeof(int);

	k = maiorValor(A,tam);

	int B[tam];

	countingSort(A, B, tam, k);

	printf("Vetor ordenado: ");

    for(i = 1; i <= tam; i++){
		A[i] = B[i];
		printf("%d, ", A[i]);
	}

	getchar();

	return 0;
}
