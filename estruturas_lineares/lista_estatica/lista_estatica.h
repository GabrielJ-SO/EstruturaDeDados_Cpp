#ifndef LISTAESTATICA_H
#define LISTAESTATICA_H

typedef struct lista_estatica {
    int *vetor;
    int tamanho;
    int quantidade;
} ListaEstatica;

ListaEstatica* criar(int tamanho);

int buscar(ListaEstatica *lista, int valor);
int obterElemento(ListaEstatica *lista, int i);

bool inserir(ListaEstatica *lista, int valor);
bool remover(ListaEstatica *lista, int valor);


#endif