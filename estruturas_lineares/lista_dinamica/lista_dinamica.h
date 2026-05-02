#ifndef LISTADINAMICA_H
#define LISTADINAMICA_H

#include <stdbool.h>

typedef struct listaDinamica ListaDinamica;

ListaDinamica* criarLista(int capacidadeInicial);

int capacidade(ListaDinamica *lista);
int quantidade(ListaDinamica *lista);
int buscar(ListaDinamica *lista, int valor);
int obterElemento(ListaDinamica *lista, int indice);

bool inserir(ListaDinamica *lista, int valor);
bool remover(ListaDinamica *lista, int valor);

void atualizar(ListaDinamica *lista, int indice, int valor);
void liberar(ListaDinamica *lista);

#endif