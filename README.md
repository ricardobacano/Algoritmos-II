# Algoritmos de Ordenação e Busca

Este repositório contém a implementação de algoritmos de ordenação e busca para dois trabalhos acadêmicos realizados na disciplina CI056 na UFPR - Algoritmos e Estruturas de Dados II.

---

## Trabalho 1: Ordenação e Busca com Vetores Personalizados

### Descrição
Neste trabalho, foram implementados os seguintes algoritmos na linguagem C:

- **Busca Sequencial (Ingênua)**:
  - Versões: Recursiva e Iterativa.
- **Busca Binária**:
  - Versões: Recursiva e Iterativa.
- **Insertion Sort**:
  - Versões: Recursiva e Iterativa.
- **Selection Sort**:
  - Versões: Recursiva e Iterativa.
- **Merge Sort**:
  - Apenas versão Recursiva.

### Funcionalidade
- O programa permite ao usuário escolher o tamanho do vetor a ser ordenado ou pesquisado.
- Testes foram realizados para medir o tempo de execução e o número de comparações feitas por cada algoritmo.

### Observações
Os resultados obtidos (tempo de execução e número de comparações) foram documentados em um relatório.

---

## Trabalho 2: Ordenação com Vetores Pré-definidos

### Descrição
Neste trabalho, os seguintes algoritmos foram implementados em C:

- **Merge Sort**:
  - Versões: Recursiva e Iterativa.
- **Quicksort**:
  - Versões: Recursiva e Iterativa.
- **Heapsort**:
  - Versões: Recursiva e Iterativa (incluindo a função `max-heapify`).

### Funcionalidade
- Um vetor de tamanho fixo (10.000 elementos) é criado pelo próprio programa.
- Cada algoritmo é executado sobre este vetor, com versões recursivas e não recursivas.

### Observações
- A implementação do `malloc` segue o padrão com `cast`, garantindo compatibilidade com os compiladores usados na disciplina.
- Durante a execução, pilhas auxiliares podem ser usadas para substituir a recursão.
- Todos os resultados foram descritos em um relatório.

---

## Compilação e Execução

### Dependências
- Sistema operacional Linux.
- Compilador GCC.
- Ferramenta `make`.

### Passos para Compilar
1. Navegue até o diretório do trabalho.
2. Execute `make` para compilar o código.
3. Após a compilação, execute o binário gerado por cada trabalho
