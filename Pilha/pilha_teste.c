#include<stdio.h>
#include<stdlib.h>
//#include "pilhaContigua.h"
#include "PilhaEncadeada.h"

int main(){
	// Desenvolva os testes para verificar se a função implementada 
  //está funcionando como esperado
    Pilha* p = pilha_criar();
    pilha_empilhar(p,10);
    pilha_empilhar(p,20);
    pilha_empilhar(p,30);
    pilha_empilhar(p,40);
    pilha_empilhar(p,50);

    pilha_imprimir(p);

  /*   int aux;
    aux =30;
    pilha_desempilhar(p,&aux);
    pilha_imprimir(p); */

    pilha_inverter(p);
    pilha_imprimir(p);
 
}