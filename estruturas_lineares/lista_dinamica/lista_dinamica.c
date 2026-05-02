#include <stdlib.h>
#include <stdbool.h>
#include "lista_dinamica.h"

struct listaDinamica {
    int *vetor;
    int capacidade;
    int quantidade;
};

ListaDinamica* criarLista(int capacidadeInicial) {
    ListaDinamica* lista = (ListaDinamica*)calloc(1, sizeof(ListaDinamica));
    lista->vetor = (int*)calloc(capacidadeInicial, sizeof(int));
    lista->capacidade = capacidadeInicial;
    lista->quantidade = 0;
}

int capacidade(ListaDinamica *lista) {
    return lista->capacidade;
}

int quantidade(ListaDinamica *lista) {
    return lista->quantidade;
}

int buscar(ListaDinamica *lista, int valor) {
    for (int i = 0; i < lista->quantidade; i++) {
        if (lista->vetor[i] == valor)
            return i;
    }

    return -1;
}

int obterElemento(ListaDinamica *lista, int indice) {
    if (indice >= lista->quantidade || indice < 0)
        return -1;
    else
        return lista->vetor[indice];
}

bool inserir(ListaDinamica *lista, int valor) {
    if (lista != NULL) {
        if (lista->quantidade == lista->capacidade) {
            lista->capacidade *= 2;
            lista->vetor = (int*)realloc(lista->vetor, lista->capacidade * sizeof(int));
        }
        lista->vetor[lista->quantidade] = valor;
        lista->quantidade++;

        return true;
    }

    return false;
}

bool remover(ListaDinamica *lista, int valor) {
    int i = buscar(lista, valor);

    if (i == -1) 
        return false;

    lista->quantidade--;
    for (i; i < lista->quantidade; i++) {
        lista->vetor[i] = lista->vetor[i + 1];
    }

    if (lista->capacidade / lista->quantidade >= 2) {
        lista->capacidade = lista->capacidade / 2;
        lista->vetor = (int*)realloc(lista->vetor, lista->capacidade * sizeof(int));
    }

    return true;
}


void atualizar(ListaDinamica *lista, int indice, int valor) {
    if (indice >= lista->quantidade || indice < 0) {
        return;
    }

    lista->vetor[indice] = valor;
}

void liberar(ListaDinamica *lista) {
    if (lista != NULL) {
        free(lista->vetor);
        free(lista);
    }
        
}

