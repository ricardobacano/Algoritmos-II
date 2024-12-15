#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <time.h>

#include "ordenacao.h"

#define MIN_VALUE 1
#define MAX_VALUE

int main()
{
    char nome[MAX_CHAR_NOME];
    size_t idxBusca;
    uint64_t numComp = 0;
    size_t N;

    int *vetor;

    // Obter informações pessoais
    getNome(nome);
    printf("Trabalho de %s\n", nome);
    printf("GRR %u\n\n", getGRR());

    clock_t start, end;
    double total;

    printf("Tamanho do vetor:");
    scanf("%zu", &N);

    vetor = (int *)malloc(N * sizeof(int));

    if (vetor == NULL)
    {
        printf("Falha fatal. Impossível alocar memória.\n");
        return 1;
    }

    // Insertion Sort
    preencherVetorAleatorio(vetor, N, 1, 100000);
    printf("Vetor novo, não ordenado: ");
    imprimeVetor(vetor, N);

    numComp = total = 0;
    start = clock();
    numComp = insertionSort(vetor, N);
    end = clock();

    printf("Vetor ordenado (Insertion Sort): ");
    imprimeVetor(vetor, N);
    total = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Insertion Sort com %zu elementos fez %lu comparações em %f segundos\n", N, numComp, total);

    printf("\n");

    // Insertion Sort Recursivo

    preencherVetorAleatorio(vetor, N, 1, 100000);
    printf("Vetor novo, não ordenado: ");
    imprimeVetor(vetor, N);

    numComp = 0;
    start = clock();
    numComp = insertionSortRec(vetor, N);
    end = clock();

    printf("Vetor ordenado (Insertion Sort Recursivo): ");
    imprimeVetor(vetor, N);
    total = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Insertion Sort Recursivo com %zu elementos fez %lu comparações em %f segundos\n", N, numComp, total);

    printf("\n");

    // Selection Sort

    preencherVetorAleatorio(vetor, N, 1, 100000);
    printf("Vetor novo, não ordenado: ");
    imprimeVetor(vetor, N);

    numComp = total = 0;
    start = clock();
    numComp = selectionSort(vetor, N);
    end = clock();

    printf("Vetor ordenado (Selection Sort): ");
    imprimeVetor(vetor, N);
    total = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Selection Sort com %zu elementos fez %lu comparações em %f segundos\n", N, numComp, total);

    printf("\n");

    // Selection Sort Recursivo

    preencherVetorAleatorio(vetor, N, 1, 100000);
    printf("Vetor novo, não ordenado: ");
    imprimeVetor(vetor, N);

    numComp = 0;
    start = clock();
    numComp = selectionSortRec(vetor, N);
    end = clock();

    printf("Vetor ordenado (Selection Sort Recursivo): ");
    imprimeVetor(vetor, N);
    total = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Selection Sort Recursivo com %zu elementos fez %lu comparações em %f segundos\n", N, numComp, total);

    printf("\n");

    // Merge Sort

    preencherVetorAleatorio(vetor, N, 1, 100000);
    printf("Vetor novo, não ordenado: ");
    imprimeVetor(vetor, N);

    numComp = total = 0;
    start = clock();
    numComp = mergeSortRec(vetor, N);
    end = clock();

    printf("Vetor ordenado (Merge Sort): ");
    imprimeVetor(vetor, N);
    total = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Merge Sort com %zu elementos fez %lu comparações em %f segundos\n", N, numComp, total);

    printf("\n");
    
    int indiceBusca = rand() % N;
    int valorBusca = vetor[indiceBusca];

    printf("Tamanho do vetor é %zu.\n", N);
    printf("Vetor para buscar o valor %d: ", valorBusca);
    imprimeVetor(vetor, N);
    printf("\n");


    // Busca Sequencial
    numComp = 0;
    idxBusca = buscaSequencial(vetor, N, valorBusca, &numComp);
    if (idxBusca != -1){
        printf("Busca Sequencial:\nÍndice: %zd\nComparações: %lu\n", idxBusca, numComp);
    } else {
        printf("Busca Sequencial, valor não encontrado, total de comparações: %lu", numComp);
        printf("\n");
    }
    printf("\n");

    // Busca Sequencial recursiva
    numComp = 0;
    idxBusca = buscaSequencialRec(vetor, N, valorBusca, &numComp);
    if (idxBusca != -1){
        printf("Busca Sequencial Recursiva\nÍndice: %zd\nComparações: %lu\n", idxBusca, numComp);
    } else {
        printf("Busca Sequencial Recursiva, valor não encontrado, total de comparações: %lu", numComp);
        printf("\n");
    }
    printf("\n");

    // Busca Binaria
    numComp = 0;
    idxBusca = buscaBinaria(vetor, N, valorBusca, &numComp);
    if (idxBusca != -1){
        printf("Busca Binaria \nÍndice: %zd\nComparações: %lu\n", idxBusca, numComp);
    } else {
        printf("Busca Binaria, valor não encontrado, total de comparações: %lu", numComp);
        printf("\n");
    }
    printf("\n");

    // Busca Binaria recursiva
    numComp = 0;
    idxBusca = buscaBinariaRec(vetor, N, valorBusca , &numComp);
    if (idxBusca != -1){
        printf("Busca Binaria Recursiva \nÍndice: %zd\nComparações: %lu\n", idxBusca, numComp);
    } else {
        printf("Busca Binaria Recursiva, valor não encontrado, total de comparações: %lu", numComp);
        printf("\n");
    }
    printf("\n");

    free(vetor);

    return 0;
}
