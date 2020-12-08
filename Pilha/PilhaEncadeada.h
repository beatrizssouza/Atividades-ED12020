#include <stdio.h>
#include <stdlib.h>

//PilhaEncadeada.h

typedef enum boolean {false=0, true =1} Boolean;
typedef int TipoElemento;
typedef struct no* ptr;

/**************************************
* DADOS
**************************************/
typedef struct no{
	TipoElemento dado;
	ptr prox;
}No;

typedef struct {
	No *topo;
	int qtdeElementos;
}Pilha;

/**************************************
* PROTÓTIPOS
**************************************/
Pilha* pilha_criar();
void destruir_no(ptr no);
void pilha_destruir(Pilha* p);
Boolean pilha_empilhar(Pilha* p, TipoElemento elemento);
Boolean pilha_desempilhar(Pilha* p, TipoElemento* saida); // estratégia do scanf
Boolean pilha_topo(Pilha* p, TipoElemento* saida); // estratégia do scanf
void pilha_imprimir(Pilha* p);
int pilha_tamanho(Pilha* p);
Pilha* pilha_clone(Pilha* p);
Pilha* pilha_inverter(Pilha* p);
Boolean pilha_empilharTodos(Pilha* p, TipoElemento* vetor, int tamVetor);

/**************************************
* IMPLEMENTAÇÃO
**************************************/
// Desenvolva as funções

Pilha* pilha_criar(){

	Pilha* new = (Pilha*) malloc(sizeof(Pilha));
	new->topo = NULL;
	new->qtdeElementos = 0;

	return new;

}
void destruir_no(ptr no){

	if(no == NULL) return;
	destruir_no(no->prox);
	free(no);
	
}
void pilha_destruir(Pilha* p){

	if(p==NULL) return;
	destruir_no(p->topo);
	free(p);

}
Boolean pilha_empilhar(Pilha* p, TipoElemento elemento){
	
	ptr new = (ptr)malloc(sizeof(ptr));
	new->dado = elemento;

		if(p->topo == NULL){
			p->topo = new;
			new->prox = NULL;
		}else{
			new->prox = p->topo;
			p->topo = new;
		}
		p->qtdeElementos++;
		
}
Boolean pilha_desempilhar(Pilha* p, TipoElemento* saida){
	if(p->topo != NULL){
		ptr no = p->topo;
        TipoElemento* saida=(TipoElemento*) malloc (sizeof(TipoElemento));
        saida = &no->dado;
        p->topo = no->prox;
        p->qtdeElementos--;

		return true;		
	}
}
void pilha_imprimir(Pilha* p){
    if(p->topo ==  NULL)
    printf("A pilha está vazia?! \n");
    else{
        ptr proximo = p->topo;
        printf("[");
            while (proximo != NULL){
                printf("%d ",proximo->dado);
                proximo = proximo->prox;
            }
        printf("]\n");
    } 
}

int pilha_tamanho(Pilha* p){
    return p->qtdeElementos;
}
/*
Adiciona de maneira recursiva
*/
void push_recursivo (Pilha* p, ptr no){

    push_recursivo(p,no->prox);
    pilha_empilhar(p,no->dado);
}
Pilha* pilha_clone(Pilha* p){
    Pilha* clone = pilha_criar();
    push_recursivo(clone,p->topo);
    return clone;

}

Pilha* pilha_inverter(Pilha* p){
    Pilha* invertida = pilha_criar();
    ptr aux = p->topo;
    while(aux != NULL){
        pilha_empilhar(invertida,aux->dado);
        aux= aux->prox;
    }
    return invertida;
}
Boolean pilha_empilharTodos(Pilha* p, TipoElemento* vetor, int tamVetor){
    if(p== NULL || p->topo == NULL){
        return false;
    }else{
        for(int i=0;i < tamVetor;i++){
            pilha_empilhar(p,vetor[i]);
        }
        return true;
    }
}