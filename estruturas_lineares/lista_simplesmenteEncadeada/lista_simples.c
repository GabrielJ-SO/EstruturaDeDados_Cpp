#include <stdlib.h>
#include <stdio.h>
#include "lista_simples.h"

typedef struct lista_simples 
{
    No* inicio;
} ListaSimples;

typedef struct no
{
    int valor;
    No* proximo;
} No;

No* _criarNo(int valor) {
    No* novoNo = (No*)calloc(1, sizeof(No));
    novoNo->valor = valor;
    novoNo->proximo = NULL;

    return novoNo;
}


ListaSimples* criarLista() {
    ListaSimples* lista = (ListaSimples*)calloc(1, sizeof(ListaSimples));
    lista->inicio = NULL;

    return lista;
}


No* buscarNo(ListaSimples *lista, int valor) {
    if (lista == NULL) { return NULL; }
    
    No* noAtual = lista->inicio;
    while (noAtual != NULL)
    {
        if (noAtual->valor == valor) {
            return noAtual;
        }

        noAtual = noAtual->proximo;
    }
    return noAtual;
}


int contarNos(ListaSimples* lista) {
    if (lista == NULL)
        return 0;

    No* noAtual = lista->inicio;
    int contador = 0;

    while (noAtual != NULL) {
        contador++;
        noAtual = noAtual->proximo;
    }

    return contador;
}


void adicionarInicioDaListaSimples(ListaSimples *lista, int valor) {
    No* novoNo = _criarNo(valor);

    if (lista->inicio == NULL) {
        lista->inicio = novoNo;
        return;
    }
    else {
        novoNo->proximo = lista->inicio;
        lista->inicio = novoNo;
    }
}

void adicionarFinalDaListaSimples(ListaSimples *lista, int valor) {
    if (lista == NULL) { return; }
    
    if (lista->inicio == NULL) {
        No* novoNo = _criarNo(valor);
        lista->inicio = novoNo;
        return;
    }

    No *no = lista->inicio;
    while (no->proximo != NULL)
    {
        no = no->proximo;
    }
    no->proximo = _criarNo(valor);
}

void inserirOrdenado(ListaSimples *lista, int valor) {
    No *novoNo = _criarNo(valor);

    if (lista->inicio == NULL || valor < lista->inicio->valor) {
        novoNo->proximo = lista->inicio;
        lista->inicio = novoNo;
        return;
    }

    No* noAtual = lista->inicio;
    while (noAtual->proximo != NULL && noAtual->proximo->valor < valor) {
        noAtual = noAtual->proximo;
    }

    noAtual->proximo = noAtual->proximo;
    noAtual->proximo = novoNo;
}

void imprimirListaSimples(ListaSimples *lista) {
    if (lista == NULL) { return; }
        
    No* noAtual = lista->inicio;

    while (noAtual != NULL) {
        printf("[%d]-->", noAtual->valor);
        noAtual = noAtual->proximo;
    }
    printf("NULL\n");
}

void removerUltimoDaListaSimples(ListaSimples *lista) {
    if (lista == NULL) { return; }

    No *no = lista->inicio;

    while (no->proximo->proximo != NULL) 
    {
        no = no->proximo;
    }
    free(no->proximo);
    no->proximo = NULL;
}

void inverterLista(ListaSimples *lista) {
    if (lista == NULL) { return; }

    No* anterior = NULL;
    No* atual = lista->inicio;
    No* proximo = NULL;

    while (atual != NULL) 
    {
        proximo = atual->proximo;
        atual->proximo = anterior;
        anterior = atual;
        atual = proximo;
    }

    lista->inicio = anterior;
}

void liberarLista(ListaSimples *lista) {

    if (lista != NULL) {
        while (lista->inicio->proximo != NULL) {
            removerUltimoDaListaSimples(lista);
        }

        free(lista->inicio);
        lista->inicio = NULL;
    }
}
