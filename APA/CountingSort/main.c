#include <stdio.h>
#include <stdlib.h>

#define MAX_BUCKET 100
#define MAX 10

int vetor[MAX];

void coutingSort(int *V, int N){
	int buckets[MAX_BUCKET];
	int i, j, k;

	for(i = 0; i < MAX_BUCKET; i++)
		buckets[i] = 0;

	for(i =0; i < N; i++)
		buckets[V[i]]++;

	for(i = 0, j = 0; j < MAX_BUCKET; j++)
		for(k = buckets[j]; k > 0; k--)
			V[i++] = j;
}

int main(){

	printf("Elementos do vetor: ");
		for(int i = 0; i < MAX; i++){
			scanf("%d", &vetor[i]);
		}

	coutingSort(vetor, MAX);

	printf("Vetor ordenado: ");

    for (int i = 0; i < MAX; i++)
        printf("%d ", vetor[i]);

return 0;
}
