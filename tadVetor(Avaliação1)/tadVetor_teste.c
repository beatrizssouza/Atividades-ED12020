#include <stdio.h>
#include <stdlib.h>
#include "tadVetor.h"

void teste1(){

    
   /*  Vetor* v1 = vet_criar();
    Produto p1 = {20,"teclado",38.60};
    vet_inserirFim(v1,p1);

    vet_imprimir(v1);
 */

 Vetor* v1 = vet_criar();
 vet_inserirFim(v1, 10);
 vet_inserirFim(v1,20);
  vet_inserirFim(v1,40);
 vet_inserirFim(v1,30); 

 vet_imprimir(v1);
 

 vet_inserir(v1,500,1);
 vet_imprimir(v1);


  vet_substituir(v1,2,89);
 vet_imprimir(v1);
  
int removido;
vet_removerPosicao(v1, 1,&removido);
printf("O elemento que foi removido e o  %d ", removido);
vet_imprimir(v1);

printf("O elemento da posicao  %d foi removido.\n",vet_removerElemento(v1,89)); 
vet_imprimir(v1);

printf("A quantidade de elementos e %d \n",vet_tamanho(v1));


int aux1;
vet_elemento(v1,3,&aux1);
printf("O elemento da posicao e : %d \n ",aux1);
aux1 = vet_posicao(v1,89);
printf("A posicao do elemento e  %d \n",aux1); 
vet_imprimir(v1); 


/* Vetor* v2 = vet_clone(v1);
    vet_imprimir(v2); */  
   
/*  vet_ordenarBuble(v1);
   vet_imprimir(v1); */ 
/* 
    vet_ordenarInsertion(v1);
    vet_imprimir(v1); 
  */

 
  /*  Vetor* v2 = vet_criar();
    v2 = vet_importar("arquivo_entrada.txt");
    vet_imprimir(v2); */

    //vet_imprimir(vet_criarAleatorio(4));

}

int main(){
    
    teste1();

     

}