#include <stdio.h>
#include <stdlib.h>
#define MAX 6

void Troca(int *x, int *y){
   int aux;
   aux=*x;
   *x=*y;
   *y=aux;
}

int Pai(int i){
    int x = (i-1)/2;
    return x;
}

int FilhoEsquerdo(int i){
    int x = (2*i)+1;
    return x;
}

int FilhoDireito(int i){
    int x = (2*i)+2;
    return x;
}

void MaxHeap(int *Y, int tamanho, int i){
	int ladoD = FilhoDireito(i);
	int ladoE = FilhoEsquerdo(i);
	int maior = i;

	int tamHEAP = tamanho - Pai(i) - 1;

	if(ladoE <= tamHEAP && Y[ladoE]>Y[maior]){
		maior = ladoE;
	}
	if(ladoD <= tamHEAP && Y[ladoD]>Y[maior]){
		maior = ladoD;
	}
	if(maior != i){
		Troca(&Y[i], &Y[maior]);
		MaxHeap(tamHEAP, Y, maior);
	}
}

void BuildMaxHeap(int *Y){
	int i = 0;
	int n = MAX;

	for(i = (MAX/2) -1; i >= 0; i--)
		MaxHeap(n, Y, i);
}

void HeapSort(int *Y){
	BuildMaxHeap(Y);
	int i = 0;

	for(i = MAX - 1; i>=0; i--){
		Troca(&Y[0], &Y[i]);
		MaxHeap(i, Y, 0);
	}
}

int main(){
    int vetor[MAX];

	printf("Elementos do vetor: ");
		for(int i = 1; i <= MAX; i++){
			scanf("%d", &vetor[i]);
		}

	printf("\nVetor ordenado: ");

	HeapSort(vetor);

        for (int i = 1; i <= MAX; i++){
            printf("%d ", vetor[i]);
        }

return 0;
}
