#ifndef LISTASIMPLES_H
#define LISTASIMPLES_H

typedef struct lista_simples ListaSimples;
typedef struct no No;

No* buscarNo(ListaSimples *lista, int valor);

ListaSimples* criarLista();

int contarNos(ListaSimples *lista);

void adicionarInicioDaListaSimples(ListaSimples *lista, int valor);
void adicionarFinalDaListaSimples(ListaSimples *lista, int valor);
void inserirOrdenado(ListaSimples *lista, int valor);
void imprimirListaSimples(ListaSimples *lista);
void removerUltimoDaListaSimples(ListaSimples *lista);
void inverterLista(ListaSimples *lista);
void liberarLista(ListaSimples *lista);

#endif