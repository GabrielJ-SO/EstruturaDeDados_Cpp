#include <iostream>
#include "lista_estatica.h"

    ListaEstatica* criar(int tamanho) {
        ListaEstatica* lista;
        lista->tamanho = tamanho;
        lista->quantidade = 0;
        lista->vetor = (int*)calloc(tamanho, sizeof(int));

        return lista;
    }
        
    int buscar(ListaEstatica *lista, int valor) {
        for (int i = 0; i < lista->quantidade; i++) {
            if (lista->vetor[i] == valor) 
                return i;
        }

        return -1;
    }

    int obterElemento(ListaEstatica *lista, int i);


    bool inserir(ListaEstatica *lista, int valor) {
        if (lista->quantidade >= lista->tamanho) {
            return false;
        }
        else {
            lista->vetor[lista->quantidade] = valor;
            lista->quantidade++;
            return true;
        }
    }

    bool remover(ListaEstatica *lista, int valor) {
        int i = buscar(lista, valor);

        if (i == -1) { return false; } 
            
        lista->quantidade--;
        for (i; i < lista->quantidade; i ++) {
            lista->vetor[i] = lista->vetor[i + 1];
        }

        return true;
    }

    
