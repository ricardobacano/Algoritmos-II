#include "ordenacao.h"
#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <sys/types.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>



void getNome(char nome[]) {
    // substitua por seu nome
    strncpy(nome, "Ricardo Quer do Nascimento Filho", MAX_CHAR_NOME);
    nome[MAX_CHAR_NOME - 1] =
        '\0';  // adicionada terminação manual para caso de overflow
}

// a função a seguir deve retornar o seu número de GRR
uint32_t getGRR() { return 20224827; }

// troca :)
void trocar(int vetor[], size_t i, size_t j){
    
    int aux;
    aux = vetor[i];
    vetor[i] = vetor[j];
    vetor[j] = aux;
}

// preenche um vetor aleatorio entre o intervalo de min e max
void preencherVetorAleatorio(int vetor[], size_t tam, int min,int max) {
    for (size_t i = 0; i < tam; i++) {
        vetor[i] = min + rand() % (max - min + 1);
    }
}

// imprrime vetor
void imprimeVetor(int vetor[], int tam) {
    if (tam <= 0) {
        printf("[]\n");
        return;
    }

    printf("[ ");
    if (tam <= 10) {
        // Imprime todos os elementos se o tamanho for menor ou igual a 10
        for (int i = 0; i < tam; i++) {
            printf("%d", vetor[i]);
            if (i < tam - 1) {
                printf(", ");
            }
        }
    } else {
        // Imprime os primeiros 5 elementos
        for (int i = 0; i < 5; i++) {
            printf("%d", vetor[i]);
            if (i < 4) {
                printf(", ");
            }
        }
        printf(" ... ");
        // Imprime os últimos 5 elementos
        for (int i = tam - 5; i < tam; i++) {
            printf("%d", vetor[i]);
            if (i < tam - 1) {
                printf(", ");
            }
        }
    }
    printf(" ]\n");
}

// cupiar um vetor para outro (usado no MERGE() )
void copiar(int vetor[],size_t inicio, size_t fim, int vetor_u[]){
    size_t i;

    for (i = inicio; i <= fim; i++){
        /* a posição do vetor_u é (i - inicio) */
        vetor[i] = vetor_u[i - inicio];
    } 

}

// busca ingênua
ssize_t buscaSequencial(int vetor[], size_t tam, int valor,
                        uint64_t* numComparacoes) {
    *numComparacoes = 0; 

    for (size_t i = 0; i < tam; i++){

        // incrementa o contador a cada interação
        (*numComparacoes)++;

        if(vetor[i] == valor){
            return i;
        }
    }

    return -1;
}

// busca ingênua recursiva
ssize_t buscaSequencialRec(int vetor[], size_t tam, int valor, uint64_t* numComparacoes) {
    if (tam == 0) {
        *numComparacoes = 0; 
        return -1;
    }

    (*numComparacoes)++; 
    if (vetor[0] == valor) {
        return 0; 
    }

    ssize_t resultado = buscaSequencialRec(&vetor[1], tam - 1, valor, numComparacoes);

    if (resultado == -1) {
        return -1;
    } else {
        return resultado + 1; 
    }
}

// busca binária iterativa
ssize_t buscaBinaria(int vetor[], size_t tam, int valor,
                     uint64_t* numComparacoes) {
    ssize_t inicio = 0;
    ssize_t fim = tam - 1;                     

    *numComparacoes = 0;

    while (inicio <= fim){

        ssize_t meio = (inicio + fim) / 2;

        (*numComparacoes)++;

        if (vetor[meio] == valor){
            return meio;
        } 
        else if (valor < vetor[meio]){
            fim = meio - 1;
        }
        else
            inicio = meio + 1;
    }

    return -1;
}

// busca binária recursiva
ssize_t buscaBinariaRec(int vetor[], size_t tam, int valor, uint64_t* numComparacoes) {
    (*numComparacoes)++;

    if (tam == 0)
        return -1;

    size_t meio = tam / 2;

    if (valor == vetor[meio]) {
        return meio; 
    } else if (valor < vetor[meio]) {
        return buscaBinariaRec(vetor, meio, valor, numComparacoes); // busca na metade esquerda
    } else {
        ssize_t resultado = buscaBinariaRec(vetor + meio + 1, tam - meio - 1, valor, numComparacoes);
        if (resultado != -1)
            return meio + 1 + resultado; // ajusta o índice para o vetor original
        else
            return -1;
    }
}

// ordenação por inserção
uint64_t insertionSort(int vetor[], size_t tam) {
    uint64_t totalComparacoes = 0;

    for(size_t i = 0; i < tam - 1; i++){
        int valorAtual = vetor[i];
        ssize_t  j = i - 1;

        while (j >= 0 && vetor[j] > valorAtual){
            vetor[j + 1] = vetor[j];
            j--;
            totalComparacoes++;
        }

        vetor[j + 1] = valorAtual;
    }

    return totalComparacoes;

}

// ordenação por inserção recursivo
uint64_t insertionSortRec(int vetor[], size_t tam) {
    if (tam <= 1) {
        return 0;
    }

    uint64_t numComparacoes = 0;

    numComparacoes += insertionSortRec(vetor, tam - 1);

    // elemento a ser inserido é o último elemento do vetor atual
    int elementoInserir = vetor[tam - 1];

    inserir(vetor, tam - 1, elementoInserir, &numComparacoes);

    return numComparacoes;
}

// função auxiliar para ordenar por inserção recursivamente
void inserir(int vetor[], size_t posicao, int elemento, uint64_t* numComparacoes) {
    ssize_t posicaoInsercao = buscaBinaria(vetor, posicao, elemento, numComparacoes);

    // testa se a posição é um indice valido
    if (posicaoInsercao >= 0 && posicaoInsercao <= posicao) {
        // move para direita para abrir espaço
        for (size_t i = posicao; i > posicaoInsercao; i--) {
            vetor[i] = vetor[i - 1];
        }

        vetor[posicaoInsercao] = elemento;
    } else {
        return;
    }
}

// ordenação por seleção
uint64_t selectionSort(int vetor[], size_t tam) {

    uint64_t numComparacoes = 0;

    for (size_t i = 0; i < tam - 1; i++){
        size_t indiceMenor = i;

        for (size_t j = i + 1; j < tam; j++){
            numComparacoes++;
            if (vetor[j] < vetor[indiceMenor]){
                indiceMenor = j;
            }
        }
        /* se o menor elemento não estiver na posição atual, troca */
        if (indiceMenor != i){
            trocar(vetor, i, indiceMenor);
        }
    }
    return numComparacoes;
}

// ordenação por seleção recursivo
uint64_t selectionSortRec(int vetor[], size_t tam) {
    if (tam <= 1){
    return 0;
    }

    size_t numComparacoes = 0;
    
    ssize_t indiceMenor = buscaMinimo(vetor,tam, 0, &numComparacoes );

    trocar(vetor, 0, indiceMenor);

    selectionSortRec(vetor + 1, tam - 1);

    return numComparacoes;
}

//função auxiliar para ordenar por seleção recursivamente
uint64_t buscaMinimo(int vetor[], size_t tam, int valor, uint64_t* numComparacoes) {
    ssize_t indiceMenor = 0;

    for (size_t i = 1; i < tam; i++) {
        (*numComparacoes)++;
        
        if (vetor[i] < vetor[indiceMenor]) {
            indiceMenor = i;
        }
    }

    return indiceMenor;
}

// função auxiliar para o Merge Sort recursivo
uint64_t mergeSortAux(int vetor[], size_t inicio, size_t fim, uint64_t* numComparacoes, int vetor_u[]) {
    if (inicio >= fim) {
        return 0; 
    }

    size_t meio = (inicio + fim) / 2;
    mergeSortAux(vetor, inicio, meio, numComparacoes, vetor_u);
    mergeSortAux(vetor, meio + 1, fim, numComparacoes, vetor);
    merge(vetor, inicio, meio, fim, numComparacoes,vetor_u);

    return *numComparacoes;
}

// ordenação merge sort recursivo
uint64_t mergeSortRec(int vetor[], size_t tam) {
    if (tam <= 0) {
        return 0; 
    }

    int *vetor_u = (int *)malloc(tam * sizeof(int));

    uint64_t numComparacoes = 0;
    mergeSortAux(vetor, 0, tam - 1, &numComparacoes,vetor_u);

    free(vetor_u);

    return numComparacoes;
}

// mesclar dois vetores, auxiliar do merge sort
uint64_t merge(int vetor[],size_t inicio, size_t meio, size_t fim,uint64_t* numComparacoes, int vetor_u[]){
    if (inicio >= fim){
        return 0;
    }

    size_t k = 0;
    size_t i = inicio;
    size_t j = meio + 1;

    size_t tam = fim - inicio + 1;
    while (k < tam){
        if (j > fim || (i <= meio && vetor[i] <= vetor[j])){
            vetor_u[k] = vetor[i];
            i++;
        } else{
            vetor_u[k] = vetor[j];
            j++;
        }
        (*numComparacoes)++;
        k++;
    }

    copiar(vetor,inicio,fim,vetor_u);
    return *numComparacoes;
}

