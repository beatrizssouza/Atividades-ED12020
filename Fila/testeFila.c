
#include<stdio.h>
#include<stdlib.h>
//#include "FilaCircular.h"
#include "FilaEncadeada.h"

int main(){
	// Desenvolva os testes para verificar se a função implementada 
  //está funcionando como esperado
  int removido;
Fila* f = fila_criar();                     // []
fila_inserir(f, 1);                         // [1]
fila_inserir(f, 2);                         // [1,2]
fila_inserir(f, 3);                         // [1,2,3]
fila_imprimir(f);

fila_remover(f, &removido);                 // [2,3]
printf("Valor removido: %d\n", removido);
fila_inserir(f, 4);                        // [2,3,4]
fila_imprimir(f);
}
