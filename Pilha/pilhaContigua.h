#include <stdio.h>
#include <stdlib.h>
#define TAM 3
//PilhaContigua.h

typedef enum boolean{False=0, True=1} Boolean;
typedef int TipoElemento;

/**************************************
* DADOS
**************************************/
typedef struct {
	TipoElemento* vetor;
	int tamVetor;
	int qtde;
}Pilha;

/**************************************
* PROTÓTIPOS
**************************************/
Pilha* pilha_criar();
void pilha_destruir(Pilha* p);
Boolean pilha_empilhar(Pilha* p, TipoElemento elemento);
void aumenta_vetor(Pilha* p);
Boolean pilha_desempilhar(Pilha* p, TipoElemento* saida); // estratégia do scanf
Boolean pilha_topo(Pilha* p, TipoElemento* saida); // estratégia do scanf
void pilha_imprimir(Pilha* p);
int pilha_tamanho(Pilha* p);
Pilha* pilha_clone(Pilha* p);
void pilha_inverter(Pilha* p);
Boolean pilha_empilharTodos(Pilha* p, TipoElemento* vetor, int tamVetor);

/**************************************
* IMPLEMENTAÇÃO
**************************************/
// Desenvolva as funções

Pilha* pilha_criar(){

    Pilha* p = (Pilha*) malloc (sizeof(Pilha));
    p->vetor = (TipoElemento*) calloc(TAM,sizeof(TipoElemento));
    p->tamVetor= TAM;
    p->qtde = 0;

    return p;
}

void pilha_destruir(Pilha* p){

    free(p->vetor);
    free(p);
}

Boolean pilha_empilhar(Pilha* p, TipoElemento elemento){


    p->vetor[p->qtde++] = elemento;
    if(p->qtde == p->tamVetor)
    aumenta_vetor(p);

    return True;
    
}

void aumenta_vetor(Pilha* p){
    p->tamVetor *= 2;
    TipoElemento* aux = (TipoElemento*) calloc(p->tamVetor,sizeof(TipoElemento));
   
    for(int i = 0; i < p->qtde;i++){
        aux[i] = p->vetor[i];
    }

    free(p->vetor);
    p->vetor = aux;
    
}

Boolean pilha_desempilhar(Pilha* p, TipoElemento* saida){

     *(saida) = p->vetor[p->qtde-1];
     p->qtde--;
     return True;   
} 

Boolean pilha_topo(Pilha* p, TipoElemento* saida){
    int pos= (p->qtde)-1;

    *saida = p->vetor[pos];
    p->vetor[pos] = 0;
    p->qtde--;
    return True;
}

void pilha_imprimir(Pilha* p){
    printf("[ ");
    for(int i=p->qtde-1; i>=0; i--){
        printf("%d ", p->vetor[i]);
    }
    printf("]\n");
};

int pilha_tamanho(Pilha* p){

    return p->tamVetor;
}

Pilha* pilha_clone(Pilha* p){
    Pilha* copia = (Pilha*) malloc (sizeof(Pilha));

    copia->tamVetor = p->qtde;
    copia->qtde = p->qtde;
    copia->vetor = (TipoElemento*) calloc(p->qtde,sizeof(TipoElemento));
    for(int i=0; i < p->qtde;i++){
        copia->vetor[i] = p->vetor[i];
    }
    return copia;
}
void pilha_inverter(Pilha* p){
    TipoElemento* aux = (TipoElemento*) calloc(p->qtde,sizeof(TipoElemento));

    for(int i= (p->qtde-1),j=0;i >=0;i--){
        aux[j] = p->vetor[j];
        j++;
    }
    for(int i=0;i< p->qtde;i++){
        p->vetor[i] = aux[i];
    }

    free(aux);
}

Boolean pilha_empilharTodos(Pilha* p, TipoElemento* vetor, int tamVetor){
    while (p->qtde + tamVetor > p-> tamVetor){
        aumenta_vetor(p);
    }
    for(int i=p->qtde,j=0;j < tamVetor; i++){
        p->vetor[i] = vetor[j];
        p->qtde++;
        j++;
        
    }
    
}

