#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "ordenacao.h"

int main() {
    char nome[MAX_CHAR];
    long long int numComp;
    size_t tamVetor = 1000000;

    // alloca o vetor na memória 
    int* vetor = (int*)malloc(tamVetor * sizeof(int));
    if (vetor == NULL) {
        printf("Falha fatal. Impossível alocar memoria.\n");
        return 1;
    }
    printf("\n");

    //Funções do dados do aluno
    getNome(nome);
    printf("Trabalho de %s\n", nome);
    printf("GRR %u\n", getGRR());
    printf("\n");

    clock_t start, end;
    double total;

    preencherVetorAleatorio(vetor,tamVetor);
    printf("Vetor não-ordenado: \n");
    imprimeVetor(vetor, tamVetor); // impressão do vetor sem ordenação
    printf("\n");

//======================Merge Sort Recursivo====================================

    numComp = 0;
    start = clock();
    numComp = mergeSort(vetor, tamVetor);
    end = clock();
    total = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Merge Sort Recursivo\n");
    imprimeVetor(vetor, tamVetor);
    printf("Comparações: %lld\n", numComp);
    printf("Tempo: %f segundos\n", total);
    printf("\n");

//======================Merge Sort Iterativo====================================

    preencherVetorAleatorio(vetor, tamVetor);
    numComp = 0;
    start = clock();
    numComp = mergeSortSR(vetor, tamVetor);
    end = clock();
    total = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Merge Sort Iterativo\n");
    imprimeVetor(vetor, tamVetor);
    printf("Comparações: %lld\n", numComp);
    printf("Tempo: %f segundos\n", total);
    printf("\n");

//======================Quick Sort Recursivo===================================

    preencherVetorAleatorio(vetor, tamVetor);
    numComp = 0;
    start = clock();
    numComp = quickSort(vetor, tamVetor);
    end = clock();
    total = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Quick Sort Recursivo\n");
    imprimeVetor(vetor, tamVetor);
    printf("Comparações: %lld\n", numComp);
    printf("Tempo: %f segundos\n", total);
    printf("\n");

//======================Quick Sort Iterativo===================================

    preencherVetorAleatorio(vetor,tamVetor);
    numComp = 0;
    start = clock();
    numComp = quickSortSR(vetor, tamVetor);
    end = clock();
    total = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Quick Sort Iterativo\n");
    imprimeVetor(vetor, tamVetor);
    printf("Comparações: %lld\n", numComp);
    printf("Tempo: %f segundos\n", total);
    printf("\n");

//======================Heap Sort Recursivo====================================

    preencherVetorAleatorio(vetor,tamVetor);
    numComp = 0;
    start = clock();
    numComp = heapSort(vetor, tamVetor);
    end = clock();
    total = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Heap Sort Recursivo\n");
    imprimeVetor(vetor, tamVetor);
    printf("Comparações: %lld\n", numComp);
    printf("Tempo: %f segundos\n", total);
    printf("\n");

//======================Heap Sort Iterativo====================================

    preencherVetorAleatorio(vetor,tamVetor);
    numComp = 0;
    start = clock();
    numComp = heapSortSR(vetor, tamVetor);
    end = clock();
    total = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Heap Sort Iterativo\n");
    imprimeVetor(vetor, tamVetor);
    printf("Comparações: %lld\n", numComp);
    printf("Tempo: %f segundos\n", total);
    printf("\n");


    free(vetor);

    return 0;
}
