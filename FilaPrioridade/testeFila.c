#include <stdio.h>
#include <stdlib.h>
#include "FilaProriedadeHeap.h"

int main(){

    FilaPrioridade* f = filaP_criar();                     
    filaP_inserir(f, 10);                        
    filaP_inserir(f, 9);                         
    filaP_inserir(f, 4);
    filaP_inserir(f, 7);                         
    filaP_inserir(f, 3);                         
    filaP_inserir(f, 2);                         
    filaP_inserir(f, 6);                         
    filaP_inserir(f, 1);                         
    filaP_inserir(f, 5);                         

    fila_imprimir(f);
    int removido;
    while(!filaP_vazia(f)){
        filaP_remover(f, &removido);
        printf("%d ", removido);     // saída esperada: 10 9 8 7 6 5 4 3 2 1 
    }
}

