#include <stdio.h>
#include "lista_simples.h"

int main()
{
    ListaSimples* lista = criarLista();

    inserirOrdenado(lista, 5);
    inserirOrdenado(lista, 3);
    inserirOrdenado(lista, 7);

    adicionarInicioDaListaSimples(lista, 50);
    adicionarInicioDaListaSimples(lista, 40);
    adicionarInicioDaListaSimples(lista, 30);
    adicionarInicioDaListaSimples(lista, 20);
    adicionarInicioDaListaSimples(lista, 10);

    adicionarFinalDaListaSimples(lista, 60);
    adicionarFinalDaListaSimples(lista, 70);
    adicionarFinalDaListaSimples(lista, 80);

    printf("Numero de nos = %d \n", contarNos(lista));

    imprimirListaSimples(lista);

    inverterLista(lista);
    imprimirListaSimples(lista);

    liberarLista(lista);
    lista = NULL;

    return 0;
}