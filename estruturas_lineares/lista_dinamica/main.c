#include <stdlib.h>
#include <stdio.h>
#include "lista_dinamica.h"

int main()
{
    ListaDinamica* lista = criarLista(5);
    
    inserir(lista, 10); 
    inserir(lista, 15);
    inserir(lista, 20);
    inserir(lista, 25);
    inserir(lista, 30);


    printf("Adicionando cinco elementos na lista.\nCapacidade: %d \nQuantidade: %d\n", capacidade(lista), quantidade(lista));
    for (int i = 0; i < quantidade(lista); i++) {
        printf("%d - ", obterElemento(lista, i));
    }

    inserir(lista, 35);
    inserir(lista, 40);
    inserir(lista, 45);
    inserir(lista, 50);
    inserir(lista, 55);
    inserir(lista, 60);
    inserir(lista, 65);
    inserir(lista, 70);
        
    printf("\n\nLista apos adicionar + 8 elementos.\nCapacidade: %d \nQuantidade: %d\n", capacidade(lista), quantidade(lista));
    for (int i = 0; i < quantidade(lista); i++) {
        printf("%d - ", obterElemento(lista, i));
    }

    remover(lista, 70);
    remover(lista, 55);
    remover(lista, 35);
    remover(lista, 10);
    remover(lista, 20);

    printf("\n\nLista ao remover cinco elementos. \nCapacidade: %d \nQuantidade: %d\n", capacidade(lista), quantidade(lista));
    for (int i = 0; i < quantidade(lista); i++) {
        printf("%d - ", obterElemento(lista, i));
    }

    liberar(lista);
    lista = NULL;

    return 0;
}