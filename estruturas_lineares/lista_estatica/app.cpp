#include <iostream>
#include "lista_estatica.h"
using namespace std;

int main ()
{
    ListaEstatica* lista = criar(10);

    inserir(lista, 1);
    inserir(lista, 2);
    inserir(lista, 3);
    inserir(lista, 4);
    inserir(lista, 5);

    remover(lista, 2);
    remover(lista, 5);

    inserir(lista, 7);
    inserir(lista, 9);

    for (int i = 0; i < lista->quantidade; i++) {
        cout << i << " = " << obterElemento(lista, i) << endl;
    }

    excluir(lista);

    return 0;
}